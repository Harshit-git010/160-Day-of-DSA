#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        
        int temp = arr[0];
        int kadane_max = arr[0];
        
        int total_sum = 0;
        int kadane_min = arr[0];
        
        // Maximum subarray by kadane's algorithm
        
        for(int i = 1 ; i<arr.size() ; i++){
            
            if(temp<0) temp = max(temp,arr[i]);
            
            else temp+=arr[i];
            
            kadane_max=max(kadane_max,temp);
        }
        
        temp = arr[0];
        
        // Minimm subarray 
        
            // total sum of array
            
            for(int i = 0 ; i<arr.size() ; i++){
                total_sum+=arr[i];
            }
            
            // mininum subarray
            
            for(int i = 1 ; i<arr.size() ; i++){
                
                if(temp>0) temp = min(temp,arr[i]);
                
                else temp+=arr[i];
                
                kadane_min = min(kadane_min,temp);
            }
            
            // changing total_sum = total - minimum // 
            if(total_sum != kadane_min) total_sum = total_sum - kadane_min;
            
        // Max of Both
        return max(total_sum,kadane_max);
        
        
    }
};