class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        int n = mat[0].size();
        int m = mat.size();
        
        int i = 0, j = n-1;
        while(i<m && j>=0){
            
            if(mat[i][j] == x) return true;
            
            if(mat[i][j]>x){
                j--;
            }
            else{
                i++;
            }
        }
        
        return false;
    }
};