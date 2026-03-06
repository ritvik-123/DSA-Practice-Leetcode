class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int a = 0;
        int b = 0;
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> combined;
        while(a<size1 && b<size2)
        {
            if(nums1[a]<nums2[b])
            {
                combined.push_back(nums1[a]);
                a++;
            }
            else
            {
                combined.push_back(nums2[b]);
                b++;
            }
        }
        if(a<size1)
        {
            while(a<size1)
            {
                combined.push_back(nums1[a]);
                a++;
            }
        }
        if(b<size2)
        {
            while(b<size2)
            {
                combined.push_back(nums2[b]);
                b++;
            }
        }
        if((size1+size2)%2 == 0)
        {
            cout<<combined[((size1+size2)/2)-1]<<combined[((size1+size2)/2)];
            return (combined[((size1+size2)/2)-1]+combined[((size1+size2)/2)])/2.0;
        }
        else
        {
            return combined[(size1+size2)/2];
        }
    }
};