class Solution {
public:
    string longestPalindrome(string s) {
        int right = 0;
        int left = 0;
        string res;
        for(int i = 0; i<s.size();i++)
        {
            //trying odd length of palindrome
            right = i;
            left = i;
            while(left>=0 && right<=s.size()-1 && s[right]==s[left])
            {
                if(res.size()<right-left+1)
                {
                    res = s.substr(left,right-left+1);
                }
                right++;
                left--;
            }
            //trying even length
            if(i<s.size()-1)
            {
                left = i;
                right = i+1;
                while(left>=0 && right<=s.size()-1 && s[right]==s[left])
                {
                    if(res.size()<right-left+1)
                    {
                        res = s.substr(left,right-left+1);
                    }
                    right++;
                    left--;
                }
            }
        }
        return res;
    }
};