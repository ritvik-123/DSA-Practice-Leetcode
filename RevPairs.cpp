class Solution {
public:
    void merge(vector<int>& nums, int& result, int left, int mid, int right)
    {
        int i = left;
        int j = mid+1;
        for(int i = left; i<=mid ; i++)
        {
            while(j<=right && (long long)nums[i]>2LL*nums[j])
            {
                j++;
            }
            result += j-(mid+1);
        }
        i = left;
        j = mid+1;
        vector<int> temp;

        while((i<=mid)&&(j<=right))
        {
            if(nums[i] > nums[j])
            {
                temp.push_back(nums[j]);
                j++;
            }
            else
            {
                temp.push_back(nums[i]);
                i++;
            }
        }
        while(i<=mid)
        {
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=right)
        {
            temp.push_back(nums[j]);
            j++;
        }
        for(int i = 0; i<temp.size();i++)
        {
            nums[left+i] = temp[i];
        }
    }
    void mergePairs(vector<int>& nums, int& result, int left, int right)
    {
        if(left>=right)
        {
            return;
        }
        int mid = left + (right - left)/2;
        mergePairs(nums,result,left,mid);
        mergePairs(nums,result,mid+1,right);
        merge(nums, result, left, mid, right);
    }
    int reversePairs(vector<int>& nums)
    {
        int result = 0;
        int n = nums.size();
        mergePairs(nums, result, 0, n-1);
        return result;
    }
};