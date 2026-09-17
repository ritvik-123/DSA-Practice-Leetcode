class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        int running_sum = 0;
        int index = 0;
        sort(candidates.begin(), candidates.end());
        backtrack(result, candidates, current, target, running_sum, index);
        return result;
    }
    void backtrack(vector<vector<int>>& result, vector<int>& candidates, vector<int>& current, int target, int runSum, int index)
    {
        if(runSum == target)
        {
            result.push_back(current);
            return;
        }
        if(index>=candidates.size())
        {
            return;
        }
        if(index<candidates.size() && (runSum + candidates[index]<=target))
        {
            current.push_back(candidates[index]);
            backtrack(result, candidates, current, target, runSum+candidates[index], index+1);
            current.pop_back();
        }
        if(index<candidates.size())
        {
            while(index+1<candidates.size() && (candidates[index]==candidates[index+1]))
            {index++;}
            backtrack(result, candidates, current, target, runSum, index+1);
        }
    }
};