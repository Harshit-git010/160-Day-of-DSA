class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int left = 0 , right = arr.size()-1;
        int mini = INT_MAX;
        
        while(left<=right){
            
            int mid = left + (right-left)/2;
            mini = min(mini,arr[mid]);
            
            if(arr[mid]>arr[right]){
                left = mid+1;
            }
            else right = mid-1;
        }
        return mini;
    }
};
// Time Complexity: O(log n)
// Space Complexity: O(1)