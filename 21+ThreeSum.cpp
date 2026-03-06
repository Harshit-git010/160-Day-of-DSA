// This solution contains duplicate triplets
// and does not handle the case where the same triplet is counted multiple times.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // take two pointer 
        int i = 0 ;     // one pointer starting from nums[0]
        int j = i + 1;  // other from next to first pointer

        // vector to return
        vector<vector<int>> output;

        // three elements to add
        int x,y;

        // hash table
        unordered_map <int,int> ash;
        for(int i = 0 ; i<nums.size() ; i++){
            ash[nums[i]]=i;
        }

        while(i<nums.size()-2){

            x=nums[i];
            y=nums[j%nums.size()];

            int target = -(x+y);
            auto it  = ash.find(target);

            // search for the last element in hash table

            if(it != ash.end() && it->second > j%nums.size()){
                // add x,y and target in vector
                output.push_back({x,y,target});
                j++;
            }
            else{
                if(j%nums.size() == nums.size()-1){
                    i++;     // increment pointer
                    j=i+1;
                }
                else{
                    j++;
                }
            }

        }

        /* 
        here the extra task that is performed is the same triad that is not add upto
        0 being checked again and again
        */ 
        
        return output;
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(n)

// Optimal Solution
// This solution avoids duplicate triplets and handles the case where the same triplet is counted multiple

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // sort the array
        sort(nums.begin(),nums.end());

        // vector to return
        vector<vector<int>> output;

        for(int i = 0 ; i<nums.size()-2 ; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;

            int left = i+1 , right = nums.size()-1;
            while(left<right){

                int sum = nums[i]+nums[left]+nums[right];
                if(sum==0){

                    output.push_back({nums[i],nums[left],nums[right]});

                    while(left<right && nums[left]==nums[left+1]) left++;
                    while(left<right && nums[right]==nums[right-1]) right--;

                    left++;
                    right--;
                }
                else if(sum<0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        
        return output;
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(1) for the output vector, O(n) for the sorting