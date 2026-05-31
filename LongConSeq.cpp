class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = 0;
        int maxlen = 0;
        bool iscon = false;
        if(nums.size() == 0 || nums.size() == 1)
        {
            return nums.size();
        }
        for(int i = 0;i<nums.size()-1;i++)
        {
            if(nums[i+1] - nums[i] == 1)
            {
                iscon = true;
                len++;
                if(maxlen<len)
                {
                    maxlen = len;
                }
            }
            else if(nums[i+1] - nums[i] == 0)
            {
                iscon = true;
            }
            else
            {
                len = 0;
                iscon = false;
            }
        }
        return maxlen+1;
    }
};