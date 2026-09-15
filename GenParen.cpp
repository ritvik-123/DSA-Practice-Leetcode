class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        int open = 0;
        int close = 0;
        string current;
        vector<string> result;
        getString(result, current, open, close, n);
        return result;
    }
    void getString(vector<string> &result, string current, int open, int close, int n)
    {
        if (open == n && close == n)
        {
            result.push_back(current);
            return;
        }

        if (open < n)
        {
            getString(result, current + "(", open + 1, close, n);
        }

        if (close < open)
        {
            getString(result, current + ")", open, close + 1, n);
        }
    }
};