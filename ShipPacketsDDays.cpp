class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int right = accumulate(weights.begin(),weights.end(),0);
        int left = *max_element(weights.begin(),weights.end()); // least capacity needs to be max weight otherwise all the weights won't be transferred
        int mid = 0;
        int days_taken = 1; // days taken will be 1
        int weight_cap_day = 0;
        while(left<right)
        {
            days_taken = 1;
            mid = left + (right - left)/2;
            weight_cap_day = 0;
            for(int i = 0; i<weights.size();i++)
            {
                weight_cap_day += weights[i];
                if(weight_cap_day>mid)
                {
                    days_taken++;
                    weight_cap_day = weights[i]; //need to assign weights[i] otherwise we will miss that weight
                }

            }
            if(days_taken>days)
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