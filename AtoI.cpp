class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        long long res = 0;
        bool num = false;
        bool is_neg = false;
        while(i<s.size())
        {
            // allowing whitespace
            if(!num && s[i] == ' ')
            {
                i++;
                continue;
            }
            // allowing negation
            else if(!num && s[i] == '-' && i<s.size() && isdigit(s[i+1]))
            {
                is_neg = true;
            }
            // allowing positive
            else if(!num && s[i] == '+' && i<s.size() && isdigit(s[i+1]))
            {
                is_neg = false;
            }
            // scanning for nums
            else if(isdigit(s[i]))
            {
                num = true;
                int digit = s[i] - '0';

                if (res > ((INT_MAX - digit) / 10) && !is_neg)
                    return INT_MAX;
                
                else if (res > (((1LL*INT_MAX+1) - digit) / 10) && is_neg)
                    return INT_MIN;

                res = res * 10 + digit;
            }
            // otherwise breaking from the loop
            else
            {
                break;
            }
            i++;
        }
        // negation if true
        if(is_neg)
        {
            res = -res;
        }
        // capping the value
        if (res > INT_MAX)
            return INT_MAX;

        if (res < INT_MIN)
            return INT_MIN;

        return (int)res;
    }
};