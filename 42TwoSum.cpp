#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){

    unordered_map<int,int> nums2 ;       

        for(int i = 0 ; i<nums.size() ; i++){

            int temp = target - nums[i];

                if(nums2.find(temp) != nums2.end()){
                    return vector<int> {nums2[temp] , i};
                }

                nums2[nums[i]] = i;

        }
        return{};
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)

