class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size()-1;
        int k = 0; // our pivot 

        // find the pivot or the value of 'k'
        while (low < high) {
            int mid = (low+high)/2;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        k=low;

        // we need to find the array in which the target may lie
        low = 0;
        high = nums.size()-1;

        if( target >= nums[k] && target <= nums[high]){
            low = k;
        }

        else{
            high = k-1;
        }

        // next we need to find the target through binary search in that subarray 
        
        while(low <= high){
            int mid = (low+high)/2;
            if( target < nums[mid] ){
                high = mid-1;
            }

            else if( target > nums[mid]){
                low = mid+1;
            }

            else if( nums[mid] == target){
                return mid;
            }
        }

        return -1;
    }
};

// Time Complexity: O(log n)
// Space Complexity: O(1)

// Optimal Approach (same time and space complexity)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) return mid;

            // If Left half is sorted
            if (nums[low] <= nums[mid]) {
                if (target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            // If Right half is sorted
            else {
                if (target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};

