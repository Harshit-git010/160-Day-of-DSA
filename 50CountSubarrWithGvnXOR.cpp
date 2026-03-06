class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int count = 0;
        unordered_map<int,int> mp;
        int current = 0;
        
        for(int i = 0 ; i<arr.size() ; i++){
            current ^= arr[i];
            int fnd = (current^k);
            
            if(current == k) count++;
            
            if(mp.find(fnd) != mp.end()) count+=mp[fnd];
            
            mp[current]++;
        }
        
        
        return count;
    }
};

// Time Complexity: O(n) where n is the number of elements in the array
// Space Complexity: O(n)