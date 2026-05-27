class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr_m = 0;
        int ptr_n = 0;
        vector<int> results;
        vector<int> new_nums1(nums1.begin(), nums1.begin()+m);
        while(ptr_m<m && ptr_n<n)
        {
            if(new_nums1[ptr_m]<=nums2[ptr_n])
            {
                results.push_back(new_nums1[ptr_m]);
                ptr_m++;
            }
            else
            {
                results.push_back(nums2[ptr_n]);
                ptr_n++;
            }
        }
        while(ptr_m<m)
        {
            results.push_back(new_nums1[ptr_m]);
            ptr_m++;
        }
        while(ptr_n<n)
        {
            results.push_back(nums2[ptr_n]);
            ptr_n++;
        }
        nums1 = results;
    }
};