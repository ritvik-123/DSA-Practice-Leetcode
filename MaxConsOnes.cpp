class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_val = 0;
        int l = 0;
        int n = nums.size();
        for (int r = 0 ; r<n ; r++)
        {
            if (nums[r] == 1)
            {
                if(r-l+1 > max_val)
                {
                    max_val = r-l+1;
                }
            }
            else if(nums[r] != 1)
            {
                l = r+1;
            }
        }
        return max_val;
    }
};