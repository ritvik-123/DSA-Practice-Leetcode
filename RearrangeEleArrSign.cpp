class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> fin(n);
        int p = 0;
        int neg = 1;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] >= 0)
            {
                fin[p] = nums[i];
                p+=2;
            }
            else
            {
                fin[neg] = nums[i];
                neg+=2;
            }
        }
        return fin;
    }
};