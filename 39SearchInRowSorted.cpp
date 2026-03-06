class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        // code here
        
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 0 ; i<n ; i++){
            
            if(mat[i][0]<=x && mat[i][m-1]>=x){
                
                // Binary Search
                int left = 0, right = m-1;
                while(left<=right){
                    int mid = left + (right-left)/2;
                    
                    if(mat[i][mid] == x) return true;
                    
                    else if(mat[i][mid]>x){
                        right = mid-1;
                    }
                    else left = mid+1;
                }
            }
        }
        return false;
    }
};