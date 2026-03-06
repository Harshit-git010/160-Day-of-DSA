class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int> row,col;

        // traverse for finding zeroes
        for(int i = 0 ; i<matrix.size() ; i++){
            for(int j = 0 ; j<matrix[i].size() ; j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        // make those rows zero
        for(int r : row){
            for( int j = 0 ; j<n ; j++){
                matrix[r][j] = 0;
            }
        }

        // make the columns zero
        for(int c : col){
            for( int j = 0 ; j<m ; j++){
                matrix[j][c] = 0;
            }
        }
        
    }
};
// Time Complexity: O(m*n) + O(m*n) ~ O(m*n)
// Space Complexity: O(m) + O(n) ~ O(m+n)

// Optimal Approach: Using constant space

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();  // row size
        int n = matrix[0].size(); //column size

        bool firstRow = false , firstCol = false;

        for(int i = 0 ; i<m ; i++){
            if(matrix[i][0]==0){
                firstRow = true;
                break;
            }
        }

        for(int j = 0 ; j<n ; j++){
            if(matrix[0][j]==0){
                firstCol = true;
                break;
            }
        }

        // traverse for finding zeroes
        // mark the first row and column to be zero
        for(int i = 1 ; i<m ; i++){
            for(int j = 1 ; j<n ; j++){
                if(matrix[i][j]==0){
                   matrix[i][0]=0;
                   matrix[0][j]=0;
                }
            }
        }

        for(int i = 1 ; i<m ; i++){
            for(int j = 1 ; j<n ; j++)
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j] = 0;
                }
        }

        if(firstRow){
            for(int i = 0 ; i<m ;i++){
                matrix[i][0]=0;
            }
        }

        if(firstCol){
            for(int j = 0 ; j<n ;j++){
                matrix[0][j]=0;
            }
        }
        
    }
};
// Time Complexity: O(m*n) + O(m*n) ~ O(m*n)
// Space Complexity: O(1)