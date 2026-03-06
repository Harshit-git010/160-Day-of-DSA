//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Your code here                                       // Another better solution below
        int max_sum = INT_MIN;
        
        int current_sum = 0;
        
    
        for(int i = 0 ; i<arr.size() ; i++){
            
            current_sum = current_sum + arr[i];
            
            if(max_sum < current_sum){
                max_sum = current_sum;
            }
            
            if(current_sum < 0){
                current_sum = 0;
            }
            
        }
        
        return max_sum;
    }
};

// Better approach

class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {

        int temp = INT_MIN;
        int maxi = INT_MIN;

        for(int i = 0 ; i<nums.size() ; i++){

            if(temp < 0) temp = max(temp,nums[i]);

            else  temp+=nums[i];

            maxi = max(maxi,temp); 
        }

        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl << "~" << endl;
    }
}
// } Driver Code Ends