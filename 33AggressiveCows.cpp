class Solution {
  public:
  
    bool check(int dist,vector<int> &stalls,int k){
        
        int count = 1;
        int prev = stalls[0];
        
        for(int i = 0 ; i < stalls.size() ; i++){
            
            if(stalls[i]-prev >= dist){
                prev = stalls[i];
                count++;
            }
        }
        
        if(count>=k) return true;
        else return false;
    }
  
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n = stalls.size();
        int res = 0;
        
        sort(stalls.begin(),stalls.end());
        
        int low = 1;
        int right = stalls[n-1] - stalls[0]; 
        
        if(k==2) return right;
        
        while(low<=right){
            
            int mid = low + (right-low)/2;
            if(check(mid,stalls,k)){
                res = mid;
                low = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        
        return res;
    }
};
//Time Complexity: O(N log N) + O(N log M) where N is the number of stalls and M is the maximum distance between two stalls.
//Space Complexity: O(1)