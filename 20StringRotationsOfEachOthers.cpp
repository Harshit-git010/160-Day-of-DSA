class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // code here
        
        // making a string of txt and finding pat or s2 in it
        
        string txt = s1+s1;
        
        // making lps array
        vector<int> lps(s2.size(),0);
        
        int i = 1;
        int j = 0;
        
        while(i<s2.size()){
            
            if(s2[i]==s2[j]){
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
        
        // finding the s2 string in txt
        
        i=0,j=0;
        
        while(i<txt.size()){
            
            if(txt[i]==s2[j]){
                j++;
                i++;
                
                if(j==s2.size()) return true;
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
        return false;
    }
};