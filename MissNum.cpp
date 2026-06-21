class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0;
        int n = nums.size();
        int i = 0;
        for  (i=0;i<n;i++)
        {
            x = x^i;
            x = x^nums[i];
        }
        x = x^n;
        return x;
    }
};