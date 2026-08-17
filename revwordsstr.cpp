class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int word_ctr = 0;
        string result = "";
        string temp = "";
        vector<string> interim;
        bool inaword = false;
        while(i<s.size())
        {
            if(s[i] == ' ' && !inaword)
            {
                i++;
            }
            else if(s[i] == ' ' && inaword)
            {
                interim.push_back(temp);
                temp = "";
                word_ctr++;
                i++;
                inaword = false;
            }
            else
            {
                inaword = true;
                temp = temp + s[i];
                i++;
            }
        }
        if (!temp.empty())
        {
            interim.push_back(temp);
        }
        reverse(interim.begin(), interim.end());
        for(i = 0;i<interim.size()-1;i++)
        {
            result = result + interim[i] + ' ';
        }
        result = result + interim[i];
        return result;
    }
};