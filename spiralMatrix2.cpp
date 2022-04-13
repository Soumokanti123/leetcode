// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
  
// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]


// Example 2:

// Input: n = 1
// Output: [[1]]

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>v(n, vector<int>(n));
        // int a = 0;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         v[i][j] = a+1;
        //         a++;
        //     }
        // }
        int row_start = 0, row_end = n-1, col_start = 0, col_end = n-1;
        int a = 0;
        while(row_start <= row_end and col_start <= col_end){
            for(int col = col_start; col<=col_end; col++){
                v[row_start][col] = a+1;
                a++;
            }
            row_start++;
            for(int row = row_start; row<= row_end; row++){
                v[row][col_end] = a+1;
                a++;
            }
            col_end--;
            if(row_start <= row_end){
                for(int col = col_end; col>=col_start; col--){
                    v[row_end][col] = a+1;
                    a++;
                }
                row_end--;
            }
            if(col_start <= col_end){
                for(int row = row_end; row >= row_start; row--){
                    v[row][col_start] = a+1;
                    a++;
                }
                col_start++;
            }
        }
        return v;
    }
};
