class Solution {
public:
    string longestPalindrome(string s) {

        if(s.size()==1) return s;
        string o_res1 = s.substr(0, 1), o_res = s.substr(0, 1);
        string e_res1 = s.substr(0, 1), e_res = s.substr(0, 1);

        // loop for mini even string - aa, bb 
        for(int i = 0 ; i<s.size()-1 ; i++){

            if(s[i]==s[i+1]){
                int left = i, right = i+1;

                while(left>=0 && right<s.size()){
                    
                    if(s[left]==s[right]){
                    left--,right++;
                    }
                    else break;
                }
                e_res1 = s.substr(left + 1, right - left - 1);

                if(e_res1.size() > e_res.size()) e_res = e_res1;
            }
        }

        // loop for odd mini array - ada, bab
        for(int i = 1 ; i<s.size()-1 ; i++){

            if(s[i-1]==s[i+1]){
                int left = i-1, right = i+1;

                while(left>=0 && right<s.size()){
                    
                    if(s[left]==s[right]){
                    left--,right++;
                    }
                    else break;
                }
                o_res1 = s.substr(left + 1, right - left - 1);

                if(o_res1.size() > o_res.size()) o_res = o_res1;
            }
        }

        if( e_res.size() > o_res.size() ) return e_res;
        else return o_res;
    }
};
//Time Complexity: O(N^2) where N is the length of the string.
//Space Complexity: O(1)

// Better code formatting

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 1) return s;
        
        string res = s.substr(0, 1); // at least one char palindrome

        // Expand Around Centers
        for (int i = 0; i < s.size(); i++) {
            // Odd length palindrome
            int left = i, right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (right - left + 1 > res.size()) {
                    res = s.substr(left, right - left + 1);
                }
                left--; right++;
            }

            // Even length palindrome
            left = i; right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (right - left + 1 > res.size()) {
                    res = s.substr(left, right - left + 1);
                }
                left--; right++;
            }
        }
        return res;
    }
};
//Time Complexity: O(N^2) where N is the length of the string.
//Space Complexity: O(1)