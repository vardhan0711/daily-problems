class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Edge case: if matrix is empty or first row is empty, no target can exist
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();      
        int n = matrix[0].size();   
        
        // Start from the top-right corner of the matrix
        int r = 0;        
        int c = n - 1;    
        
        // Loop until we go out of matrix bounds
        while (r < m && c >= 0) {
            int cur = matrix[r][c]; 
            if (cur == target) {
                return true;
            } 
            else if (cur > target) {
                // Current element is too big → move left
                // (all elements below in the same column are even bigger)
                c--;
            } 
            else {
                // Current element is too small → move down
                // (all elements to the left in the same row are even smaller)
                r++;
            }
        }
        
        return false;
    }
};
