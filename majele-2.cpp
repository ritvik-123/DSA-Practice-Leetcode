class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        vector<int> result;
        for(int i = 0; i<nums.size();i++)
        {
            umap[nums[i]]++;
        }
        for (const auto& pair: umap)
        {
            if(pair.second > nums.size()/3)
            {
                result.push_back(pair.first);
            }
        }
        return result;
    }
};