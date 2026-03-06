
class Solution {
  public:
    char nonRepeatingChar(string &s) {
        //  code here
        char c = '$';
        
        vector<int> alpha(26,0);
        
        for( char it : s){
            alpha[it - 'a']++;
        }
        
        for( char it : s){
            if(alpha[it - 'a'] == 1) return it;
        }
        
        return c;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1) since the size of the vector is constant (26 for lowercase letters)