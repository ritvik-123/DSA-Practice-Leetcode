class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = s.length();
        string s1, sf;
        int slen = 0;
        int mslen = 0;
        int j = 0;
        for(int i = 0; i<l ; i++)
        {
            j = i;
            while(j < l)
            {
                if(s1.contains(s[j]))
                {
                    if(slen>mslen)
                    {
                        mslen = slen;
                    }
                    sf = s1;
                    s1 = "";
                    slen = 0;
                    break;
                }
                else
                {
                    s1 += s[j];
                    slen++;
                    if(slen>mslen)
                    {
                        mslen = slen;
                    }
                    j++;
                }
            }
        }
        return mslen;
    }
};