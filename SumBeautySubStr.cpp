class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        int beauty = 0;
        for (int i = 0; i<s.size();i++)
        {
            beauty = 0;
            vector<int> freq(26);
            for(int j = i ; j<s.size(); j++)
            {
                beauty = 0;
                freq[s[j]-'a']++;
                int k = 0;
                int max = 0;
                int min = s.size();
                while(k<26)
                {
                    if(freq[k]>max)
                    {
                        max = freq[k];
                    }
                    if(freq[k]<min && freq[k]!=0)
                    {
                        min = freq[k];
                    }
                    k++;
                }
                beauty = max - min;
                sum += beauty;
            }
        }
        return sum;
    }
};