class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
        {
            return {};
        }
        unordered_map<char, vector<char>> nums_to_let;
        nums_to_let.insert({'2', {'a','b','c'}});
        nums_to_let.insert({'3', {'d','e','f'}});
        nums_to_let.insert({'4', {'g','h','i'}});
        nums_to_let.insert({'5', {'j','k','l'}});
        nums_to_let.insert({'6', {'m','n','o'}});
        nums_to_let.insert({'7', {'p','q','r','s'}});
        nums_to_let.insert({'8', {'t','u','v'}});
        nums_to_let.insert({'9', {'w','x','y','z'}});
        vector<string> fin;
        string current;
        int ind = 0;
        int vec_ind = 0;
        backtrack(digits, current, fin, ind, nums_to_let, vec_ind);
        return fin;
    }
    void backtrack(string digits, string current, vector<string> &fin, int ind, unordered_map<char, vector<char>> nums_to_let, int vec_cur_ind)
    {
        if(current.size() == digits.size())
        {
            fin.push_back(current);
            return;
        }
        else
        {
            char t = digits[ind];
            vector<char> temp = nums_to_let[t];
            if (vec_cur_ind >= temp.size()) return;
            current.push_back(temp[vec_cur_ind]);
            backtrack(digits, current, fin, ind+1, nums_to_let, 0);
            current.pop_back();
            backtrack(digits, current, fin, ind, nums_to_let, vec_cur_ind+1);
        }
    }
};