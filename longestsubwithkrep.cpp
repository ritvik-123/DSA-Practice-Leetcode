class Solution {
public:
    int longestSubstring(string s, int k) {
        int r = 0;
        int l = 0;
        unordered_map<char,int> umap;
        int len = 0;
        bool valid = false;
        for(int i = 0;i<s.size();i++)
        {
            umap[s[i]] += 1;
        }

        for(r = 0;r<s.size();r++)
        {
            if(umap[s[r]]<k)
            {
                valid = true;
                len = max(len, longestSubstring(s.substr(l,r-l),k));
                cout<<len;
                l = r+1;
            }
        }
        if (valid == false)
        {
            return s.size();
        }
        else
        {
            return max(len, longestSubstring(s.substr(l,r-l),k));
        }
    }
};