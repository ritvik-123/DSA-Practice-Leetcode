class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        int index = 0;
        sort(nums.begin(), nums.end());
        backtrack(result, nums, current, index);
        return result;
    }
    void backtrack(vector<vector<int>>& result, vector<int>& nums, vector<int>& current, int index)
    {
        if(index>=nums.size())
        {
            result.push_back(current);
            return;
        }
        if(index<nums.size())
        {
            current.push_back(nums[index]);
            backtrack(result, nums, current, index+1);
            current.pop_back();
        }
        if(index<nums.size())
        {
            while(index<nums.size()-1 && nums[index]==nums[index+1])
            {
                index++;
            }
            backtrack(result, nums, current, index+1);
        }
    }
};