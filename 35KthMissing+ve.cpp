class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // code here
        
        int low = 0, high = arr.size()-1;
        int ans = arr.size()+k;
        
        while(low<=high){
            
            int mid = low + (high-low)/2;
            
            if(arr[mid] > mid+k){
                ans = mid+k;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};