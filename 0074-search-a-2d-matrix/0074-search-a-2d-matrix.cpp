class Solution {
public:

    bool searchInRow(vector<vector<int>>& matrix, int target , int row){
        // int m = matrix.size();
        int n = matrix[0].size();

        int stR = 0;
        int endR = n-1;

        while(stR <= endR){
            int mid = stR + (endR - stR)/2;
            if(target == matrix[row][mid]){
                return true;
            }else if(target > matrix[row][mid]){
                stR = mid + 1;   
            }else{
                endR = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m = matrix.size();
      int n = matrix[0].size();

      int stR = 0;
      int endR = m-1;

      while(stR <= endR){
        int mid = stR + (endR - stR)/2;
        if(target >= matrix[mid][0] && target <= matrix[mid][n-1]){
            return searchInRow(matrix , target , mid);
        }else if(target > matrix[mid][n-1]){
            stR = mid + 1;
        }else{
            endR = mid - 1;
        }
      }
        return false;
    }
};