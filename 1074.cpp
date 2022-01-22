// Brute force approch
/* 

Approch - 1

Brute force approch
Here, In a Matrix every submatrix is having a starting point(x1,y1) and ending point((x2,y2).

Consider a following sub matrix
  ------------------------
 | (x1,y1) |      |       |
 |         |      |       | 
  ------------------------
 |         |      |       |
 |         |      |       |
  ------------------------
 |         |      |       |
 |         |      |(x2,y2)|
  ------------------------
  
  For these end points we can obtain the sum using O(n^2) algorithm.
  
  Now, we have to find these end-point using Brute-force method. 
 
 */

// CODE -1 RESOURCE(https://sixian.li/number-of-submatrices-that-sum-to-target) 
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
        int row = A.size();
        int col = A[0].size();
        int result = 0;
        
        SUM(A,row,col);   // prefix sum
        
        // top_left_most [a,b] anf bottom rightmost [c,d]
        // sum([a,b] [c,d]) = A[c,d] - A[a-1,d] - A[c,b-1] + A[a-1,b-1]
        // Here we will find [startR,startC] and [endR,endC] --> O(n^4)
        
        // Looping
    }
    
    void SUM(vector<vector<int>> & A, int row,int col){
        
        // First fill the inital row and column
        for(int i = 1;i<col;i++){
            A[0][i] += A[0][i-1];
        }
        for(int i =1;i<row;i++){
            A[i][0] +=A[i-1][0];
        }
        
        // filling rest of the matrix
        for(int i=1;i<row;i++){
            for(int j = 1;j<col;j++){
                A[i][j] += (A[i-1][j]+A[i][j-1]-A[i-1][j-1]);
            }
        }
        
    }
};


// CODE -2 (optimized approch)

