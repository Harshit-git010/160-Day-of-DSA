class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> res;
        unordered_map<string,vector<string>> ash;
        
        for(auto it : strs){
            string temp = it;
            sort(temp.begin(),temp.end());
            ash[temp].push_back(it);
        }

        for(auto x : ash){
            res.push_back(x.second);
        }

        return res;
    }
};
// Time Complexity: O(n * klogk) where n is the number of strings and k is the maximum length of a string
// Space Complexity: O(n)

// Optimized Approach
class Solution {
  public:
  
  const int MAX_ALPHA = 26;
  
    string getHash(string &str){
      string hash;
      vector<int> table (MAX_ALPHA,0);
      
      for(char c : str){
          table[c - 'a'] += 1;
      }
      
      for(int i = 0 ; i<table.size() ; i++){
          hash.append(to_string(table[i]));
          hash.append("$");
      }
      return hash;
    }
  
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        vector<vector<string>> res;
        unordered_map<string,int> ash;
        
        for(string s : arr){
            string key = getHash(s);
            
            if(ash.find(key) == ash.end()){
                ash[key] = res.size();
                res.push_back({});
            }
            
            res[ash[key]].push_back(s);
        }    
        return res;
    }    
};
// Time Complexity: O(n * k) where n is the number of strings and k is the maximum length of a string
// Space Complexity: O(n)