class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(),0);
        int cur_sum = left+(right-left)/2;
        int run_sum = 0;
        int num_sub = 1;
        while(left<=right)
        {
            num_sub = 1;
            run_sum = 0;
            cur_sum = left + (right-left)/2;
            for(int i = 0; i<nums.size();i++)
            {
                run_sum += nums[i];
                if(run_sum>cur_sum)
                {
                    num_sub++;
                    run_sum = nums[i];
                }
            }
            if(num_sub>k)
            {
                left = cur_sum+1;
            }
            else
            {
                right = cur_sum-1;
            }
        }
        return left;
    }
};