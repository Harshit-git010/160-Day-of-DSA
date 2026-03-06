class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());

        int prev = 0;
        int count = 0;
 
        for(int curr = 1; curr<intervals.size() ; curr++){

            // overlapping
            if(intervals[curr][0]<intervals[prev][1]){
                count++;
                // [1,5] [3,6] delete second

                // [1,5] [2,3] delete first
                if(intervals[curr][1]<=intervals[prev][1]){
                    prev = curr;
                }
            }

            else prev = curr;
        }
        
        return count;
    }
};

// Another SOLUTION

class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        int prev = 0;
        int count = 1;

        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= intervals[prev][1]){
                prev = i;
                count++;
            }
        }
        return n - count;
    }
};

// comparator function
bool compare(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

int minRemoval(vector<vector<int> >& intervals) {
	int cnt = 0;
  
    // Sort by minimum ending point
    sort(intervals.begin(), intervals.end(), compare);

    int end = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {

        // if there is an overlap increase the count
        if (intervals[i][0] < end)
            cnt++;

        // else increment the ending point
        else
            end = intervals[i][1];
    }

    // return the count
    return cnt;
}

