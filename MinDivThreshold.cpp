class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(),nums.end());
        int mid = 0;
        int sum_div = 0;
        while(left<right)
        {
            mid = left + (right-left)/2;
            sum_div = 0;
            for(int i = 0; i<nums.size();i++)
            {
                sum_div += ((1.0*(nums[i] + mid -1))/mid);
                if(sum_div>threshold){break;}

            }
            if(sum_div>threshold)
            {
                left = mid+1;
            }
            else
            {
                right = mid;
            }
        }
        return right;
    }
};