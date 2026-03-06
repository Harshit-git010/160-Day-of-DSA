class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        int count = 0;
        unordered_map<int,int> mp;
        int current = 0;
        for(int i = 0 ; i<arr.size() ; i++){
            
            current += arr[i];
            int fnd = current - k;
            
            if(current == k) count++;
            
            if(mp.find(fnd) != mp.end()){
                // if found
                count+=mp[fnd];
            }
            
            (mp.find(current) != mp.end()) ? mp[current]++ : mp[current]=1;
        }
        
        return count;
    }
};

// Time Complexity: O(n) where n is the number of elements in the array
// Space Complexity: O(n)