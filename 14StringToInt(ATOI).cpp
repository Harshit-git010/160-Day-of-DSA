#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {

        int temp = 0 , sign = 1 , idx = 0 ;

        while( s[idx] == ' '){
            idx++;
        } 

        if( s[idx] == '+' || s[idx] == '-'){
            if(s[idx] == '-'){
                sign = -1;
            }
            idx++;
        }

        while( s[idx] >= '0' && s[idx] <= '9'){

            if(temp > INT_MAX/10 || (temp == INT_MAX/10 && s[idx]-'0' > 7) ){
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            temp = temp*10 + ( s[idx] - '0' ) ;
            idx++;
        }

        return temp*sign;
        
    }
};