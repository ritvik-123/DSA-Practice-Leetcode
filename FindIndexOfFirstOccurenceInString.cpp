class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = 0;
        int n = 0;
        int res = -1;
        bool is_matching = false;
        if(needle.size()>haystack.size())
        {
            return res;
        }
        if (needle.empty())
        {
            return 0;
        }
        for(h = 0; h<haystack.size(); h++)
        {
            if(haystack[h] == needle[n])
            {
                if(is_matching == false)
                {
                    res = h;
                    is_matching = true;
                }
                n++;
                if(n==needle.size())
                {
                    return res;
                }
            }
            else if(is_matching == true)
            {
                is_matching = false;
                n=0;
                h = res;
                res = -1;
            }
        }
        if(is_matching == true)
        {
            res = -1;
        }
        return res;
    }
};