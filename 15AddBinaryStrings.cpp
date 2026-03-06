class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        string s = "" ;
        char carry = '0';
        
        // making two strings equal
        if(s1.size()>s2.size()){
            while(s2.size()!=s1.size()){
                s2.insert(0,"0"); // better way would be s2 = "0" + s2;
            }
        }
        
        else if(s2.size()>s1.size()){
            while(s1.size()!=s2.size()){
                s1.insert(0,"0");  /// better way would be s1 = "0" + s1;
            }
        }
        
        // loop for sum
        
        for(int it = s1.size()-1 ; it>=0 ; it--){
            
            if(s1[it]=='0' && s2[it]=='0'){
                if(carry =='1') s+="1";
                else s+="0";
                carry = '0';
            }
            
            else if( (s1[it]=='1' && s2[it]=='0') || (s1[it]=='0' && s2[it]=='1')){
                if(carry =='1'){
                    s+="0";
                    carry = '1';
                }
                else{
                    s+="1";
                    carry = '0';
                }
            }
            
            else if(s1[it]=='1' && s2[it]=='1'){
                if( carry == '1'){
                    s+="1";
                    carry = '1';
                }
                else{
                    s+="0";
                    carry = '1';
                }
            }
        }
        
        // reverse the string
        if(carry=='1') s+='1';
        reverse(s.begin(),s.end());
        
        // removing leading zeroes
        s.erase(0,s.find_first_not_of('0'));
        if(s.empty()) s="0";
        
        // return the string
        return s;
        
    }
};