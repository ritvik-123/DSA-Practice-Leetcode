class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> cur(n,string(n,'.'));
        vector<vector<string>> res;
        int row = 0;
        int cur_queens = 0;
        backtrack(cur, res, row, n, cur_queens);
        return res;
    }
    void backtrack(vector<string>& cur, vector<vector<string>>& res, int row, int n, int cur_queens)
    {
        if(cur_queens == n)
        {
            res.push_back(cur);
            return;
        }
        for(int col = 0; col<n; col++)
        {
            if(isSafe(cur, row, col, n))
            {
                cur[row][col] = 'Q';
                backtrack(cur, res, row+1, n, cur_queens+1);
                cur[row][col] = '.';
            }
        }
    }
    bool isSafe(vector<string>& cur, int row, int col, int n)
    {
        //is safe up
        int i = row;
        int j = col;
        while(i>=0)
        {
            if(cur[i][j] == 'Q')
            {
                return false;
            }
            i--;
        }
        i = row;
        // is safe left up
        while(i>=0 && j>=0)
        {
            if(cur[i][j] == 'Q')
            {
                return false;
            }
            i--;
            j--;
        }
        i = row;
        j = col;
        // is safe right up
        while(i>=0 && j<n)
        {
            if(cur[i][j] == 'Q')
            {
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
};