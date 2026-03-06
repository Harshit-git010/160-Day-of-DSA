class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        // code here
        vector <int> num;
        
        int m = txt.size();
        int n = pat.size();
        
        for( int i = 0 ; i< m-n+1 ; i++){
            if( txt.substr(i,n) == pat) num.push_back(i);
        }
        
        return num;
    }
};

// Time Complexity: O(m*n) where m is the length of txt and n is the length of pat
// Space Complexity: O(1) since we are not using any extra space except for the output vector
// Note: This is a brute force approach and can be improved with more efficient algorithms like KMP or Rabin-Karp.

// Optimal solution by using KMP algorithm

class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        // code here
        vector <int> num;
        
        int m = txt.size();
        int n = pat.size();
        
        // first make the lps array
        
        vector<int> lps(n,0);
        
        int i = 1;
        int j = 0;
        
        while( i<n ){
            
            if(pat[i]==pat[j]){
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
        
        // next find the pattern using lps array
        vector<int>res;
        
        i=0;
        j=0;
        
        while(i<m){
            
            if(txt[i]==pat[j]){
                i++;
                j++;
                
                if(j==n){
                    res.push_back(i-j);
                }
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
        
        
        return res;
    }
};


// Time Complexity: O(m+n) where m is the length of txt and n is the length of pat
// Space Complexity: O(n) for the lps array
