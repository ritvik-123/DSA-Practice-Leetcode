class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n = nums.size();
        int k = 0;
        int i = 0;
        vector<int> newNums;
        if(n==0 || n==1)
        {
            return n;
        }
        for(i = 1; i < n;i++)
        {
            if(nums[i-1] < nums[i])
            {
                k++;
                newNums.push_back(nums[i-1]);
            }
        }
        if(k==0)
        {
            k++;
            newNums.push_back(nums[i-1]);
        }
        if(newNums[k-1] < nums[i-1])
        {
            k++;
            newNums.push_back(nums[i-1]);
        }
        nums = newNums;
        return k;
    }
};