#include <vector>
#include <algorithm>

using namespace std;

// Basic Approach

/*

        int firstMissingPositive(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        int num=1;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i]==num) num++;
        }

        return num;
    }
*/

// Better Approach
/*
        int firstMissingPositive(vector<int>& nums) {

            int n = nums.size();

            vector<bool> vis(n,false);

            for(int i = 0 ; i<n ; i++){

                if(nums[i]>0 && nums[i]<=n) 
                {
                    vis[nums[i]-1]=true;
                }
            }

            for(int i = 0 ; i<n ;i++){
                if(vis[i]==false) return i+1;
            }

        }
*/

// Optimal solution

    int firstMissingPositive(vector<int>& nums) {

        // making elements at their actual place in array
    
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i]<0  || nums[i]>nums.size() || nums[i]==nums[nums[i]-1]) continue;
        
            else{
                swap(nums[i],nums[nums[i]-1]);
                i--;
            }
        }
    
        // finding the index of the missing element

        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i]!=i+1) return i+1;
        }

    return nums.size()+1;
}
