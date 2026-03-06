class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        vector<int> ans;
        
        int left = 0, right = left;
        int sum = arr[left];
        
        while(left<arr.size() && right<arr.size()){
            
            if(sum>target){
                sum-=arr[left];
                left++;
                
                if(left>right){
                    right++;
                    if(right>arr.size()-1) break;
                    sum+=arr[right];
                }
            }
            else if(sum<target){
                sum+=arr[right+1];
                right++;
            }
            else{
                int ele1 = left+1, ele2 = right+1;
                ans.push_back(ele1);
                ans.push_back(ele2);
                break;
            }
            
        }
        
        if(ans.size()==0) ans.push_back(-1);
        return ans;
    }
};