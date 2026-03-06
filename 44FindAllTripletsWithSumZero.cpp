// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        vector<vector<int>> res;
        
        for(int i = 0 ; i<arr.size()-2 ; i++){
            
            unordered_map<int,vector<int>> mp;
            
            for(int j = i+1 ; j<arr.size() ; j++){
                
                int target = 0 - arr[i] - arr[j];
                
                if(mp.find(target) != mp.end()){
                    for(int k : mp[target]){
                        vector<int> triplet = {i,k,j};
                        sort(triplet.begin(),triplet.end());
                        res.push_back(triplet);
                    }
                }
                
                mp[arr[j]].push_back(j);
            }
        }
        
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        
        return res;
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(n)