class Solution {
public:
    int countSubstrings(string s) {

    int count=0;

    // first pass for odd substrings
    int left = 0;
    int right = 0;

    while(left<s.size()){

            int left1 = left , right1 = right;
            while(left1>0 && right1<s.size()){

                if(s[left1]==s[right1]){
                    count++;
                    left1--;
                    right1++;
                }
                else break;
            }
    
        left++, right++;
    }

    // next pass for even substrings

    left=0 , right=1;

    while(right<s.size()){

            int left1 = left , right1 = right;
            while(left1>0 && right1<s.size()){

                if(s[left1]==s[right1]){
                    count++;
                    left1--;
                    right1++;
                }
                else break;
            }
        

        left++, right++;
    }

    return count;
        
    }
};

// The time complexity is O(n^2) where n is the length of the string
// The space complexity is O(1) since we are using a constant amount of extra space

// Same approch with better code

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        // Expand around each possible center
        for (int center = 0; center < 2 * n - 1; center++) {
            int left = center / 2;
            int right = left + center % 2;

            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        }

        return count;
    }
};
// The time complexity is O(n^2) where n is the length of the string
// The space complexity is O(1) since we are using a constant amount of extra space

