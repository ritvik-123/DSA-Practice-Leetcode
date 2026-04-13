class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int a = min(matrix.size(),matrix[0].size());
        if(a%2 == 0)
        {
            a = a/2;
        }
        else
        {
            a = a/2+1;
        }
        vector<int> newvec;
        for (int i = 0; i<a ;i++)
        {
            for(int j = i ;j<matrix[0].size()-i-1;j++)
            {
                newvec.push_back(matrix[i][j]);
            }
            if(newvec.size()>=matrix.size()*matrix[0].size())
            {
                break;
            }
            for(int j = i ;j<matrix.size()-i;j++)
            {
                newvec.push_back(matrix[j][matrix[0].size()-1-i]);
            }
            if(newvec.size()>=matrix.size()*matrix[0].size())
            {
                break;
            }
            for(int j = matrix[0].size()-i-2 ;j>=i+1;j--)
            {
                newvec.push_back(matrix[matrix.size()-i-1][j]);
            }
            if(newvec.size()>=matrix.size()*matrix[0].size())
            {
                break;
            }
            for(int j = matrix.size()-i-1 ;j>i;j--)
            {
                newvec.push_back(matrix[j][i]);
            }

            if(newvec.size()>=matrix.size()*matrix[0].size())
            {
                break;
            }
        }
        return newvec;
    }
};