class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int total_sub = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int len = nums.size();
        for (int i = 0;i<len;i++)
        {
            sum += nums[i];
            if(mp.find(sum-k)!= mp.end())
            {
                total_sub += mp[sum-k];
            }
            mp[sum]++;
        }
        return total_sub;
    }
};