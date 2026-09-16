class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        if(s.size()<=1)
        {
            return false;
        }
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                S.push(s[i]);
            }
            else if (s[i] == ')' && S.size()!=0 && S.top() == '(')
            {
                S.pop();
            }
            else if(s[i] ==  ']' && S.size()!=0 && S.top() == '[')
            {
                S.pop();
            }
            else if(s[i] ==  '}' && S.size()!=0 && S.top() == '{')
            {
                S.pop();
            }
            else
            {
                return false;
            }
        }
        if(S.size()!=0)
        {
            return false;
        }
        return true;
    }
};