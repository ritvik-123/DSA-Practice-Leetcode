class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        while(left<right)
        {
            mid = left + (right - left)/2;
            if(mid%2==0 && nums[mid]==nums[mid+1])
            {
                left = mid+1;
            }
            else if(mid%2==0 && nums[mid] != nums[mid+1])
            {
                right = mid;
            }
            else if(mid%2!=0 && nums[mid]==nums[mid+1])
            {
                right = mid;
            }
            else if(mid%2!=0 && nums[mid] != nums[mid+1])
            {
                left = mid+1;
            }
        }
        return nums[left];
    }
};