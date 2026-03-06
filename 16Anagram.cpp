//           One Solution

class Solution {
public:
    bool isAnagram(string s, string t) {

// check if both strings have equal size
        if(s1.size() != s2.size()) return false;
        
        // update r1
        string r1 = "";
        for(auto it = s1.begin() ; it!= s1.end() ; ++it){
            r1+=*it;
        }
        sort(r1.begin(),r1.end());
        
        // update r2
        string r2= "";
        for(auto it = s2.begin() ; it!= s2.end() ; ++it){
            r2+=*it;
        }
        sort(r2.begin(),r2.end());
        
        // check if elements are equal
        for( int it = 0 ; it < r1.size() ; it++){
            if(r1[it]!=r2[it]) return false;
        }
        
        return true;

     }
};

// Time Complexity: O(nlogn)
// Space Complexity: O(n)

//    Another Solution

// Better Approach

class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;
        
        unordered_map<char,int> ash;
        
        // insert values in hash
        for( char c : s){
            ash[c]++;
        }
        
        // reduce int if s2 values are found
        // if value of t is not found , return false
        // if value becomes negative, means there are some extra characters, return false
        // else reduce it

        for( char c : t){
            if(ash.find(c) == ash.end() || ash[c]==0){
                 return false;
            }
            ash[c]--;
        }
        
        return true;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)

// Optimal Approach

class Solution {
public:
    bool isAnagram(string s, string t) {

        // if there sizes are not equal, return false
        if(s.size() != t.size()) return false;
        
        // creating a vector for 26 alphabets (size = 26) with count(value) of zero
        vector<int> freq(26,0);
        
        // increasing count for each character found
        // difference in ASCII values of char in string and 'a' gives the index
        for( char c : s){
            freq[c - 'a']++;
        }
        
        // decreasing count , if they are anagram , vector would be empty 
        for( char c : t){
            freq[c - 'a']--;
        }
        
        // if vector is not empty, return false
        for(int count : freq){
            if(count != 0) return false;
        }
        
        // else true
        return true;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1) - since the size of vector is constant (26)