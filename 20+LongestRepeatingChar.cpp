class Solution {
public:
    int characterReplacement(string s, int k) {

        int left = 0;
        int maxCount=0;
        int ans = 0;
        vector<int> freq(26,0);

        for( int right = 0 ; right<s.size() ; right++){

            freq[s[right]-'A']++;
            maxCount = max(maxCount,freq[s[right]-'A']);

            while( (right-left+1) - maxCount > k){
                freq[s[left]-'A']--;
                left++;
            }

            ans=max(ans,right-left+1); // maximum of ans and window size
        }
        return ans;
    }
};
    m is the size of the character set (e.g., 26 for lowercase English letters).

// The time complexity is O(n) where n is the length of the string
// The space complexity is O(min(n, m)).

