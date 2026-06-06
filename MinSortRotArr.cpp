class Solution {
public:
    int findMin(vector<int>& nums) {
        int right = nums.size()-1;
        int left = 0;
        int min = nums[0];
        int mid = 0;
        while(right>=left)
        {
            mid = left+(right - left)/2;
            if(min>nums[mid])
            {
                min = nums[mid];
            }
            if(nums[mid] < nums[right])
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return min;
    }
};