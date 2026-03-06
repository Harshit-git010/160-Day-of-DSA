class Solution {
  public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        // code here
        vector<int> res;
        unordered_set<int> ash;
        
        for(int i = 0 ; i<a.size() ; i++){
            ash.insert(a[i]);
        }
        
        for(int i = 0 ; i<b.size() ; i++){
            if(ash.find(b[i]) != ash.end()){
                
                res.push_back(b[i]);
                ash.erase(b[i]);
            }
        }
        return res;
    }
};