class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
       
       unordered_map<int,int> mp;
       int count = 0;
       
       for(int i = 0 ; i<arr.size() ; i++){
           
           int goal = target - arr[i];
           
           if(mp.find(goal) != mp.end()){
               count+=mp[goal];
           }
           
           if(mp.find(arr[i]) != mp.end()){
               mp[arr[i]]++;
           }
           else{
               mp[arr[i]] = 1;
           }
           
       }
        
        return count;
    }
};