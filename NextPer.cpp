class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        bool gotdec = false;
        int len  = nums.size();
        for(int i = len-1; i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                gotdec = true;
                for(int j = len-1;j>=i;j--)
                {
                    if(nums[j]>nums[i-1])
                    {
                        int temp = nums[j];
                        nums[j] = nums[i-1];
                        nums[i-1] = temp;
                        reverse(nums.begin()+i,nums.end());
                        break;
                    }

                }
                break;
            }
        }
        if (gotdec == false)
        {
            sort(nums.begin(),nums.end());
        }
    }
};