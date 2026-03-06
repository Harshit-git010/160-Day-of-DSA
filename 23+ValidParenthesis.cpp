class Solution {
public:
    bool isValid(string s) {

        if(s.size()%2 != 0 ) return false;

        string s2 = "";

        for(int i = 0 ; i<s.size() ; i++){

            // add in stack
            s2+=s[i];
    
            // if ),},) - check the last char of check and remove it
            if(s2.size()>=2){
                int size = s2.size()-1;

                if(s2[size-1]=='(' && s2[size]==')' ){
                    s2.pop_back();
                    s2.pop_back();
                }
                else if(s2[size-1]=='{' && s2[size]=='}'){
                    s2.pop_back();
                    s2.pop_back();
                }
                else if(s2[size-1]=='[' && s2[size]==']'){
                    s2.pop_back();
                    s2.pop_back();
                }
            }
            
            
        }

        if(s2.size()==0) return true;
        else return false;
        
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n) due to the string used for checking valid parentheses

// This can also be solved using a stack data structure, which would have similar time and space complexities.