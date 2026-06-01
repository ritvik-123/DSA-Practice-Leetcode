class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int currMax = nums[0];
        int currMin = nums[0];
        int preMax = nums[0];
        int preMin = nums[0];
        int Max = nums[0];
        for(int i = 1; i<nums.size();i++)
        {
            currMax = std::max({nums[i],nums[i]*preMax,nums[i]*preMin});
            currMin = std::min({nums[i],nums[i]*preMax,nums[i]*preMin});
            if(Max<currMax || Max<currMin)
            {
                Max = std::max(currMax,currMin);
            }
            preMax = currMax;
            preMin = currMin;
        }
        return Max;
    }
};