class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int num_drops = 0;
        int size = nums.size();
        for (int i = 0; i<size;i++)
        {
            if(nums[i]>nums[(i+1)%size])
            {
                num_drops++;
                if(num_drops>1)
                {
                    return false;
                }
            }
        }
        return true;
    }
};