class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> newNums;
        int k = 0;
        int n = nums.size();
        int i = 0;
        for(i = 0; i<n ; i++)
        {
            if(nums[i] != 0)
            {
                newNums.push_back(nums[i]);
                k++;
            }
        }
        for(int j  = k; j<n ; j++)
        {
            newNums.push_back(0);
        }
        nums = newNums;
    }
};