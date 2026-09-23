class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        int start = 1;
        backtrack(result, current, n, k, start);
        return result;
    }
    void backtrack(vector<vector<int>>& result, vector<int>& current, int n, int k, int start)
    {
        if(current.size()==k)
        {
            result.push_back(current);
            return;
        }
        for(int i = start; i<=n ; i++)
        {
            current.push_back(i);
            backtrack(result, current, n, k, i+1);
            current.pop_back();
        }
    }
};