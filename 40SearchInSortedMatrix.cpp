class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n = mat.size(), m = mat[0].size();
        int low = 0 ,high = (n*m)-1;
        
        while(low <= high){
            
            int mid = low + (high-low)/2;
            
            int i = mid/m , j = mid%m;
            
            if(mat[i][j] == x) return true;
            else if(mat[i][j] > x){
                high = mid-1;
            }
            else low = mid+1;
        }
        return false;
    }
};
// Time Complexity: O(log (n*m))
// Space Complexity: O(1)