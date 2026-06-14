class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> rotated_vector;
        k = k%n;
        for(int i = n-k; i<(n-k)+n; i++)
        {
            rotated_vector.push_back(nums[i%n]);
        }
        nums = rotated_vector;
    }
};