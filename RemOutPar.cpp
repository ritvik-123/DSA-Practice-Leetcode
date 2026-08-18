class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0;
        string result;
        for (int i = 0; i<s.size();i++)
        {
            if(s[i]=='(' && depth == 0)
            {
                depth++;
            }
            else if(s[i]=='(')
            {
                depth++;
                result.push_back(s[i]);
            }
            else if(s[i]==')' && depth==1)
            {
                depth--;
            }
            else if(s[i]==')')
            {
                depth--;
                result.push_back(s[i]);
            }
        }
        return result;
    }
};