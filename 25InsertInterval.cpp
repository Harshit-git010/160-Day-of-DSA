class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        
        vector<vector<int>> result;
        
        int new_low = newInterval[0];
        int new_high = newInterval[1];
        
        int i = 0;
        int n = intervals.size();
        
        // push the preceeding intervals into result
        while(i<n && intervals[i][1]<new_low){
            result.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }
        
        // merge the overlapping intervals
        while(i<n && intervals[i][0]<=new_high){
            
            new_low = min(intervals[i][0],new_low);
            new_high = max(intervals[i][1],new_high);
            i++;
        }
        result.push_back({new_low,new_high});
        
        // push the remaining intervals into the result
        while(i<n){
            result.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }
        
        return result;
    }
};