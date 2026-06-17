class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int run_sum=0;
        bool state=false;
        int state_ctr = 0;
        //vector<int> lens;
        int min_len = nums.size();
        for(int r = 0;r<nums.size();r++)
        {
            run_sum += nums[r];
            if (run_sum>=target && !state)
            {
                state_ctr = 1;
                if((r-l+1)<min_len)
                {
                    min_len = (r-l+1);
                }
                state = true;
            }
            while(state)
            {
                run_sum -= nums[l];
                l++;
                if(run_sum>=target)
                {
                    if((r-l+1)<min_len)
                    {
                        min_len = (r-l+1);
                    }
                }
                else
                {
                    state = false;
                }
            }
        }
        //sort(lens.begin(),lens.end());
        if(state_ctr>0)
        {
            return min_len;
        }
        else
        {
            return 0;
        }
    }
};