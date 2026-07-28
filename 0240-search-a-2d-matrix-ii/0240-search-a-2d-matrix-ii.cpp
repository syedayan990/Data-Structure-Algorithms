class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) { // 0(m+n)
        int m = matrix.size();
        int n = matrix[0].size();
        
        int row = 0;
        int col = n-1;

        while(col >= 0 && row < m){
            if(target == matrix[row][col]){
                return true;
            }else if(target < matrix[row][col]){
                col--;
            }else{
                row++;
            }
        }


        return false;
    }
};