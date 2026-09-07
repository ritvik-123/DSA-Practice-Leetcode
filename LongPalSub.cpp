class Solution {
public:
    string longestPalindrome(string s) {
        int str_size = s.size();
        int start = 0;
        int end = 0;
        bool is_palin = false;
        for(int win = str_size; win>0;win--)
        {
            cout<<win;
            if (win == 1)
            {
                return s.substr(0,1);
            }
            for(int scan = 0; scan < (str_size-win+1);scan++)
            {
                for(int comp = 0; comp<win/2;comp++)
                {
                    start = comp + scan;
                    end = scan + win - 1 - comp;
                    if (s[start] == s[end])
                    {
                        is_palin = true;
                    }
                    else
                    {
                        is_palin = false;
                        break;
                    }
                }
                if(is_palin == true)
                {
                    return s.substr(scan, win);
                }
            }
        }
        return s;
    }
};