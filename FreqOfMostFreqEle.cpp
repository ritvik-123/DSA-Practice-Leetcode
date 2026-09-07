class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        long long sum = 0;     // running sum of window
        int l = 0;
        int ans = 1;

        for (int r = 0; r < (int)nums.size(); r++) {
            sum += nums[r];

            // while cost to make all nums[l..r] equal to nums[r] exceeds k, shrink
            while ((long long)nums[r] * (r - l + 1) - sum > k) {
                sum -= nums[l];
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
