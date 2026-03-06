class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        vector<int> res;
        unordered_set<int> mp;
        
        for(int i = 0 ; i<a.size() ; i++){
            mp.insert(a[i]);
        }
        for(int j = 0 ; j<b.size() ; j++){
            mp.insert(b[j]);
        }
        
        for(auto it = mp.begin() ; it!=mp.end() ; ++it){
            res.push_back(*it);
        }
        
        return res;
    }
};

// Time Complexity: O(n+m)
// Space Complexity: O(n+m)