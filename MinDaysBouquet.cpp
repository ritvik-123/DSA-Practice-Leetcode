class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<(long long)m*k)
        {
            return -1;
        }
        int left = 1;
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int mid = 0;
        int adj = 0;
        int boq = 0;
        while(left<right)
        {
            mid = left+(right-left)/2;
            adj = 0;
            boq = 0;
            for(int i = 0; i<bloomDay.size();i++)
            {
                if(bloomDay[i] - mid < 1)
                {
                    adj++;
                    if(adj>=k)
                    {
                        boq++;
                        adj = 0;
                    }
                }
                else
                {
                    adj = 0;
                }
            }
            if(boq>=m)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return right;
    }
};