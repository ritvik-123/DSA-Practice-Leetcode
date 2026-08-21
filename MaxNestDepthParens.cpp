class Solution {
public:
    int maxDepth(string s) {
        int max = 0;
        int curr = 0;
        int i = 0;
        for (i = 0; i<s.size(); i++)
        {
            if(s[i] == '(')
            {
                curr++;
                if(curr>max)
                {
                    max = curr;
                }
            }
            else if(s[i] == ')')
            {
                curr--;
            }
        }
        return max;
    }
};