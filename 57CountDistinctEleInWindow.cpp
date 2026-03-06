class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        vector<int> res;
        unordered_map<int,int> store;
        
        int left = 0, right = 0;
        
        while(right<k){
            
            store[arr[right]]++;
            right++;
        }
        
        res.push_back(store.size());
        
        while(right<arr.size()){
            
            store[arr[left]]--;
            if(store[arr[left]] == 0) store.erase(arr[left]);
            left++;
            
            store[arr[right]]++;
            right++;
            
            res.push_back(store.size());
            
        }
        
        return res;
    }
};