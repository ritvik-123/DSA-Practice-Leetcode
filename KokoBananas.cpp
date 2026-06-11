class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(),piles.end());
        int mid = 0;
        int hours_taken = 0;
        while(right>left)
        {
            mid = left + (right-left)/2;
            hours_taken = 0;
            for(int i = 0;i<piles.size();i++)
            {
                hours_taken += ceil((double)piles[i]/mid);
            }
            if(hours_taken<=h)
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        }
        return left;
    }
};