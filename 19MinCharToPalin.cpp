class Solution {
public:
    string shortestPalindrome(string s) {

        string rev = s;
        reverse(rev.begin(),rev.end());

        string s1 = s+'$'+rev;

        // make the lps array of s1

        int n = s1.size();
        vector<int> lps(n,0);

        int i = 1;
        int j = 0;
        
        while( i<n ){
            
            if(s1[i]==s1[j]){
               j++;
               lps[i]=j;
               i++;
            }
            
            else{
                
                if(j!=0){
                    j=lps[j-1];
                }
                
                else{
                    i++;
                }
            }
        }

        // minimum char needed for palindrome 
        int ans = s.size()-lps.back();

        // substr to be added
        string sub_str = s.substr(lps.back(),ans);
        reverse(sub_str.begin(),sub_str.end());

        // adding the string
        string palin = sub_str+s;

        return palin;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)