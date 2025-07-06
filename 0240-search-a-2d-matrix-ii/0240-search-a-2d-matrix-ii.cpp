class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col=matrix[0].size();
        int row=matrix.size();
        int i=row-1;
        int j=0;

        while(j<col && i>=0){
            if(matrix[i][j]==target)
            return true;
            else if(matrix[i][j]<target)
            j++;
            else
            i--;
        }
        return false;
    }
};