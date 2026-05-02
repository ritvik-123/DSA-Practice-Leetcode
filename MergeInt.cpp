class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> results;
        results.push_back(intervals[0]);
        int i = 0;
        int j = 0;
        while(j<intervals.size())
        {
            if(results[i][1]>=intervals[j][0])
            {
                results[i][1] = max(results[i][1],intervals[j][1]);
            }
            else
            {
                results.push_back({intervals[j][0],intervals[j][1]});
                i++;
            }
            j++;
        }
        return results;
    }
};