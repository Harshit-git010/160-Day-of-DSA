class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();

        // char with its position in string 
        unordered_map<char,int> lastseen; 

        int left = 0;
        int maxi = 0;

        for (int right = 0; right < s.size(); right++) {
            // store the currrent char
            char c = s[right]; 
            
            // If char was seen and is inside current window
            // meaning we have to reset the window to size zero
            if (lastseen.find(c) != lastseen.end() && lastseen[c] >= left) {
                left = lastseen[c] + 1; // move left pointer right after duplicate
            }

            lastseen[c] = right; // update last seen position to the current index
            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(min(n, m)) where n is the size of the string and