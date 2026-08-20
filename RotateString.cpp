class Solution {
public:
    bool rotateString(string s, string goal) {
        char temp;
        for(int i = 0; i<s.size(); i++)
        {
            if(s == goal)
            {
                return true;
            }
            temp = s[s.size()-1];
            for(int j = s.size()-2; j>=0; j--)
            {
                s[j+1] = s[j];
            }
            s[0] = temp;
        }
        return false;
    }
};