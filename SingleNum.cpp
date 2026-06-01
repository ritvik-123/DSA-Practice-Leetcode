class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        int n = nums.size();
        int i = 0;
        for( i=0 ; i<n ; i++)
        {
            x = x^nums[i];
        }
        return x;
    }
};