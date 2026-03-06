class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int i = 0, j = n-1;

        // loop for upper diagonals
        while(j > 0){
            i = 0;
            int t = j;
            vector<int> temp;

            //store the diagonal values in vector
            while(t<n){
                temp.push_back(grid[i][t]);
                i++,t++;
            }

            //sort it in ascending
            sort(temp.begin(),temp.end());

            //put it in the diagonal
            i = 0 , t = j;
            while(t<n){
                grid[i][t] = temp[i];
                i++,t++;
            }

            j--;
        }

        // loop for lower diagonals
        i=0;
        while(i<n){
            j = 0;
            int t = i;
            vector<int> temp;

            //store the diagonal values in vector
            while(t<n){
                temp.push_back(grid[t][j]);
                j++,t++;
            }

            //sort it in decending
            sort(temp.rbegin(),temp.rend());

            //put it in the diagonal
            j = 0, t = i;
            while(t<n){
                grid[t][j] = temp[j];
                j++,t++;
            }

            i++;
        }

        return grid;
    }
};
// Time Complexity: O(n^2 log n)
// Space Complexity: O(n)

