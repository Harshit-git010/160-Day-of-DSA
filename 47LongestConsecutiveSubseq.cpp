class Solution {
  public:
    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int count = 1;
        
        unordered_set<int> mp; 
        
        for(int num : arr){
            mp.insert(num);
        }
        
        for(int i = 0 ; i<arr.size() ; i++){
            
            if(mp.find(arr[i]-1) == mp.end()){
                int j = 1;
                while(mp.find(arr[i]+j) != mp.end()) j++;
                count = max(count, j);
            }
        }
        
        return count;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)