class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ans_r = 0;
        int ans_c = matrix[0].size()-1;
        while(ans_c>=0 && ans_r<matrix.size())
        {
            if(target == matrix[ans_r][ans_c])
            {
                return true;
            }
            else if(target<matrix[ans_r][ans_c])
            {
                ans_c--;
            }
            else
            {
                ans_r++;
            }
        }
        return false;
    }
};