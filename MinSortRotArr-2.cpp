class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int right = nums.size()-1;
        int left = 0;
        int mid = 0;
        while(right>=left)
        {
            mid = left+(right - left)/2;
            if(nums[mid] == target)
            {
                return true;
            }
            else if(nums[mid]<nums[right])
            {
                if(nums[mid]<target && nums[right]>=target)
                {
                    left = mid+1;
                }
                else
                {
                    right = mid-1;
                }
            }
            else if(nums[mid] == nums[right])
            {
                right = right-1;
            }
            else
            {
                if(nums[mid]>target && nums[left]<=target)
                {
                    right = mid-1;
                }
                else
                {
                    left = mid+1;
                }
            }
        }
        return false;
    }
};