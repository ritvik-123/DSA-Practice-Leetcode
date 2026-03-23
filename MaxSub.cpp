class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int r;
        int max_sum = nums[0];
        int curr_sum = nums[0];
        int len = nums.size();
        for (int r = 1; r<len; r++)
        {
            curr_sum += nums[r];
            if (curr_sum<=nums[r])
            {
                curr_sum = nums[r];
            }
            if (curr_sum>max_sum)
            {
                max_sum = curr_sum;
            }
        }
        return max_sum;
    }
};