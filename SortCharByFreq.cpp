class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        string res;
        for(int i = 0; i<s.size();i++)
        {
            freq[s[i]]++;
        }
        vector<pair<char, int>> vfreq(freq.begin(),freq.end());
        sort(vfreq.begin(), vfreq.end(),[](const auto& a, const auto& b) 
        {
            return a.second > b.second;
        });
        for(const auto& [key, value]: vfreq)
        {
            for(int i = 0;i<value;i++)
            {
                res.push_back(key);
            }
        }
        return res;
    }
};