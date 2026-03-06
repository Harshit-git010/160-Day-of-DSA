class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        
        vector<vector<int>> result;
        
        sort(arr.begin(),arr.end());
        
        int low = arr[0][0];
        int high = arr[0][1];
        
        if(arr.size()==1) result.push_back({low,high});
        
        int j = 1;
        while(j<arr.size()){
            
            if(arr[j][0] >= low && arr[j][0]<=high){
                
                if(arr[j][1]>high){
                    high = arr[j][1];
                }
                
            }
            
            else if(arr[j][0]>high || j==arr.size()-1 ){
                result.push_back({low,high});
                low = arr[j][0]; 
                high = arr[j][1];
            }
                
            
            if(j==arr.size()-1) result.push_back({low,high});
            
            j++;
        }
        return result;
    }
};
// Time Complexity: O(N log N) + O(N) ~ O(N log N)
// Space Complexity: O(N) for result array

class Solution {
  public:

    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {

        // Sort intervals based on start values
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> res;
        res.push_back(arr[0]);

        for (int i = 1; i < arr.size(); i++) {
            vector<int>& last = res.back();
            vector<int>& curr = arr[i];

            // If current interval overlaps with the last merged
            // interval, merge them 
            if (curr[0] <= last[1]) 
                last[1] = max(last[1], curr[1]);
            else 
                res.push_back(curr);
        }

        return res;
    }
};

