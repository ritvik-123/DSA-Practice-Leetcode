class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> pat1;
        unordered_map<char, int> pat2;

        int p1 = 0;
        int p2 = 0;

        for (int i = 0; i < s.size(); i++) {
            if (!pat1.contains(s[i])) {
                pat1[s[i]] = p1++;
            }

            if (!pat2.contains(t[i])) {
                pat2[t[i]] = p2++;
            }

            if (pat1[s[i]] != pat2[t[i]]) {
                return false;
            }
        }

        return true;
    }
};