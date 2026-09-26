class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> result;
        int a = 0;
        int b = 0;
        while(a<nums1.size() && b<nums2.size())
        {
            if(nums1[a] == nums2[b])
            {
                result.push_back(nums1[a]);
                while((a+1)<nums1.size() && nums1[a] == nums1[a+1])
                {
                    a++;
                }
                a++;
                while((b+1)<nums2.size() && nums2[b] == nums2[b+1])
                {
                    b++;
                }
                b++;
            }
            else if(nums1[a]<nums2[b])
            {
                while((a+1)<nums1.size() && nums1[a] == nums1[a+1])
                {
                    a++;
                }
                a++;
            }
            else
            {
                while((b+1)<nums2.size() && nums2[b] == nums2[b+1])
                {
                    b++;
                }
                b++;
            }
        }
        return result;
    }
};