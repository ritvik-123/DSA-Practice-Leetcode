class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> result;
        long long sum = 0;
        sort(nums.begin(),nums.end());
        if(nums.size() < 4)
        {
            return result;
        }
        for(int j = 0; j<nums.size()-3;j++)
        {
            if(j==0 || nums[j-1]!=nums[j])
            {
                for(int i = j+1; i<nums.size()-2;i++)
                {
                    if(nums[i]!=nums[i-1] && i>j+1 || i==j+1)
                    {
                        int r,l;
                        r = nums.size()-1;
                        l = i+1;
                        while(r>l)
                        {
                            sum = static_cast<long long>(nums[r])+nums[l]+nums[j]+nums[i];
                            if(sum==target)
                            {
                                result.push_back({nums[j],nums[i],nums[l],nums[r]});
                                while((l < r) && nums[l+1]==nums[l])
                                {
                                    l++;
                                }
                                while((l < r) && nums[r-1]==nums[r])
                                {
                                    r--;
                                }
                                l++;
                                r--;
                            }
                            else if((sum<target))
                            {
                                l++;
                            }
                            else
                            {
                                r--;
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
};