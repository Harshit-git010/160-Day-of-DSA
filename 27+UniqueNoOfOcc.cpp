class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int,int> ash;

        for(int i = 0 ; i<arr.size() ; i++){

            int target = arr[i];
            if(ash.find(target) != ash.end()){ // if found
                ash[target]++;
            }
            else{
                ash[target]=1;
            }
        }

        // check for unique values
        for( auto it = ash.begin() ; it!=ash.end() ; ++it){
            unordered_set<int> s;
            int target = (*it).second;
            if(s.find(target) != s.end()) return false; // if found
            else s.insert(target);
        }

        return true;
    }
};
// Time Complexity: O(n) + O(n) ~ O(n)
// Space Complexity: O(n) + O(n) ~ O(n)

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
      unordered_map<int,int>freq;
      for(auto x: arr){
          freq[x]++;
      }  
      unordered_set<int>s;
      for(auto x: freq){
          s.insert(x.second);
      }
      return freq.size()==s.size();
    }
};
// Time Complexity: O(n) + O(n) ~ O(n)
// Space Complexity: O(n) + O(n) ~ O(n)