class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        int run_sum = 0;
        backtrack(k, n, result, current, 1, run_sum);
        return result;
    }
    void backtrack(int k, int n, vector<vector<int>>& result, vector<int>& current, int start, int run_sum)
    {
        if(current.size()==k && run_sum == n)
        {
            result.push_back(current);
            return;
        }
        for(int i = start; i<=9; i++)
        {
            if(run_sum+i>n)
            {
                break;
            }
            current.push_back(i);
            backtrack(k, n, result, current, i+1, run_sum+i);
            current.pop_back();
        }
    }
};