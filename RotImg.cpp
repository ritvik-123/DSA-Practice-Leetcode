class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> mat(matrix.size(),vector<int>(matrix.size(), 0));
        int temp = 0;
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix.size();j++)
            {
                mat[j][matrix.size()-i-1] = matrix[i][j];
            }
        }
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix.size();j++)
            {
                cout<<mat[i][j];
                matrix[i][j] = mat[i][j];
            }
        }

    }
};