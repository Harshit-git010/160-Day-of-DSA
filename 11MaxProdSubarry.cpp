//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray                       below is much better solution
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        
        int maxi = arr[0];
        int mini = arr[0];
        int overall = arr[0];
        
        for(int i = 1 ; i<arr.size() ; i++){
            
            if(arr[i]<0){
                swap(maxi,mini);
            }
            
            maxi = max(arr[i] , maxi*arr[i]);
            mini = min(arr[i] , mini*arr[i]);
            
            overall = max(overall , maxi);
        }
        
        return overall;
        
    }
};

// Another solution (Optimal Solution)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int prod=1;

        for(int i=0;i<nums.size();i++)
        {
          prod*=nums[i];
          maxi=max(prod,maxi);

          if(prod==0)
           prod=1;
        }

        prod=1;

        for(int i=nums.size()-1;i>=0;i--)
        {
          prod*=nums[i];
          maxi=max(prod,maxi);

          if(prod==0)
           prod=1;
        }
        
        return maxi;
    }
};

