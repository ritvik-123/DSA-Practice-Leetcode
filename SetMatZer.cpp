class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows;
        vector<int> col;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0;i<m;i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(matrix[i][j]==0)
                {
                    rows.push_back(i);
                    col.push_back(j);
                }
            }
        }
        int r_size = rows.size();
        for(int i = 0;i<r_size;i++)
        {
            for(int j = 0;j<n;j++)
            {
                matrix[rows[i]][j] = 0;
            }
        }
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<r_size;j++)
            {
                matrix[i][col[j]] = 0;
            }
        }
    }
};