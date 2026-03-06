class Solution {
public:
    int findMin(vector<int>& nums) {

        // binary search
        int left = 0;
        int right = nums.size()-1;
        int ans = INT_MAX;

        if(nums.size()==1) return nums[0];

        while(left!=right){

            int mid = (left+right)/2;

            if(left==right-1) return min(nums[left],nums[right]);
            if(nums[mid]>nums[right]){
                left=mid;
            }
            else if(nums[mid]<nums[right]){
                right=mid;
            }

            ans = min(ans,nums[mid]);

        }
        return ans;
        
    }
};
// Time Complexity: O(log n) in average case, O(n) in worst case (when all elements are the same)
// Space Complexity: O(1)

// Optimal Solution
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n - 1;
        while (l < h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] > nums[h]) {
                l = mid + 1;
            } else {
                h = mid;
            }
        }
        return nums[l];
    }
};
// Time Complexity: O(log n)
// Space Complexity: O(1)