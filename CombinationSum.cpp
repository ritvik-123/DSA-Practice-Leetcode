class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(result, candidates, current, target, 0, 0);
        return result;
    }
    void backtrack(vector<vector<int>>& result, vector<int>& candidates, vector<int>& current, int target, int index, int sum)
    {
        if(sum == target)
        {
            result.push_back(current);
            return;
        }
        if(index>=candidates.size())
        {
            return;
        }
        //take current
        if((index<candidates.size() && (sum+candidates[index])<=target))
        {
            current.push_back(candidates[index]);
            backtrack(result, candidates, current, target, index, sum + candidates[index]);
            current.pop_back();
        }
        //skip current
        if(index<candidates.size())
        {
            backtrack(result, candidates, current, target, index+1, sum);
        }
    }
};