class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<nums.size()-2;i++)
        {
            if(i==0)
            {
                int r,l;
                r = nums.size()-1;
                l = i+1;
                while(r>l)
                {
                    if((nums[r]+nums[l]==-nums[i]))
                    {
                        result.push_back({nums[r],nums[l],nums[i]});
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
                    else if((nums[r]+nums[l]+nums[i]<0))
                    {
                        l++;
                    }
                    else
                    {
                        r--;
                    }
                }
            }
            else if(nums[i]!=nums[i-1])
            {
                int r,l;
                r = nums.size()-1;
                l = i+1;
                while(r>l)
                {
                    if((nums[r]+nums[l]==-nums[i]))
                    {
                        result.push_back({nums[r],nums[l],nums[i]});
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
                    else if((nums[r]+nums[l]+nums[i]<0))
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
        return result;
    }
};