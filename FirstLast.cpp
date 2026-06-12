class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        bool found = false;
        int right = nums.size()-1;
        int left = 0;
        int mid = 0;
        vector<int> result;
        while(right>=left)
        {
            mid = left + (right-left)/2;
            if(nums[mid] == target)
            {
                found = true;
                break;
            }
            else if (nums[mid]>target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        if(found == true)
        {
            int left = 0;
            int right = mid-1;
            int mid_l = 0;
            int mid_r = 0;
            while(left<=right)
            {
                mid_l = left + (right-left)/2;
                if(nums[mid_l] == target)
                {
                    right = mid_l - 1;
                }
                else
                {
                    left = mid_l + 1;
                }
            }
            result.push_back(left);
            left = mid+1;
            right = nums.size()-1;
            while(left<=right)
            {
                mid_r = left + (right-left)/2;
                if(nums[mid_r] == target)
                {
                    left = mid_r + 1;
                }
                else
                {
                    right = mid_r - 1;
                }
            }
            result.push_back(right);
            return result;
        }
        else
        {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
    }
};