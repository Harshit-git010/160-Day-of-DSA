class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size()-1;

        for(int i = 0 ; i<=n/2 ; i++){
            for(int j = i ; j<=n-1-i ; j++){

                int pos1 = matrix[i][j];
                int pos2 = matrix[j][n-i];
                int pos3 = matrix[n-i][n-j];
                int pos4 = matrix[n-j][i];

                // pos4 = pos3
                matrix[n-j][i] = pos3;
                // pos3 = pos2
                matrix[n-i][n-j] = pos2;
                // pos2 = pos1
                matrix[j][n-i] = pos1;
                // pos1 = pos4
                matrix[i][j] = pos4;

            }
        }
        
    }
};
//Time Complexity: O(N^2) where N is the number of rows or columns in the matrix.
//Space Complexity: O(1)

class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        // code here
        int n = mat.size()-1;
        
        // [i][j] = [j][n-i]
        for(int i = 0 ; i<=n/2 ; i++){
            for(int j = i ; j<mat.size()-i-1 ; j++){
                
                int temp = mat[i][j];
                mat[i][j] = mat[j][n-i];
                mat[j][n-i] = mat[n-i][n-j];
                mat[n-i][n-j] = mat[n-j][i];
                mat[n-j][i] = temp;
            }
        }
    }
};