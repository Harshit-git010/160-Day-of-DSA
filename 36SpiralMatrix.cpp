#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;


    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> arr;

        int left = 0, right = n-1;
        int top = 0, bottom = m-1;
        int count = m*n;

        while(top<=bottom && left<=right){

            //move right
            for(int j = left ; j <= right ; j++){
                arr.push_back(matrix[top][j]); 
                count--;
            }
            top++;

            //move down
            for(int i = top ; i <= bottom ; i++){
                arr.push_back(matrix[i][right]);
                count--;
            }
            right--;

            if(count<=0) break;
            //move left
            for(int j = right ; j>= left ; j--){
                arr.push_back(matrix[bottom][j]);
                count--;
            }
            bottom--;
            

            if(count<=0) break;
            //move up
            for(int i = bottom ; i >= top ; i--){
                arr.push_back(matrix[i][left]);
                count--;
            }
            left++;
            
        }
    return arr;
    }

// we can also use the count variable to keep track of number of elements added to the array and break the loop when count reaches 0

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        // code here
        vector<int> res;
        int count=0;
        
        int up = 0, down = mat.size()-1;
        int left = 0, right = mat[0].size()-1;
        int limit = mat.size()*mat[0].size();
        
        int i = 0, j = 0;
        while(up<=down && left<=right){
            // left
            while(j<=right){
                res.push_back(mat[i][j]);
                j++;
                count++;
            }
            j--;
            up++;
            i++;
            
            if(count==limit) break;
            
            // down
            while(i<=down){
                res.push_back(mat[i][j]);
                i++;
                count++;
            }
            i--;
            right--;
            j--;
            
            if(count==limit) break;
            
            // right
            while(j>=left){
                res.push_back(mat[i][j]);
                j--;
                count++;
            }
            j++;
            down--;
            i--;
            
            if(count==limit) break;
            
            // up
            while(i>=up){
                res.push_back(mat[i][j]);
                i--;
                count++;
            }
            i++;
            left++;
            j++;
            
            if(count==limit) break;
        }
        return res;
    }
};