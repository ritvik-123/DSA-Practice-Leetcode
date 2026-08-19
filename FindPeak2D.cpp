class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> result;
        int i = 0;
        int j = 0;
        int left = 0;
        int right = 0;
        int top = 0;
        int bottom = 0;
        while(true)
        {
            if(j == 0)
            {
                left = -1;
            }
            else
            {
                left = mat[i][j-1];
            }
            if(j == mat[0].size()-1)
            {
                right = -1;
            }
            else
            {
                right = mat[i][j+1];
            }
            if(i == 0)
            {
                top = -1;
            }
            else
            {
                top = mat[i-1][j];
            }
            if(i == mat.size()-1)
            {
                bottom = -1;
            }
            else
            {
                bottom = mat[i+1][j];
            }
            if(mat[i][j]>top && mat[i][j]>bottom && mat[i][j]>right && mat[i][j]>left)
            {
                break;
            }
            else
            {
                if(top>bottom && top>right && top>left && i-1>=0)
                {
                    i--;
                }
                else if(bottom>right && bottom>left && i+1<mat.size())
                {
                    i++;
                }
                else if(right>left && j+1<mat[0].size())
                {
                    j++;
                }
                else if(j-1>=0)
                {
                    j--;
                }
            }
        }
        result.push_back(i);
        result.push_back(j);
        return result;
    }
};
