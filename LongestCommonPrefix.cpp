class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string result;
        int vecsize = strs.size();
        int j = 0;
        int i = 0;
        bool ycom=true;
        if(strs.empty())
        {
            return result;
        }
        if(vecsize==1)
        {
            return strs[0];
        }
        while(ycom)
        {
            for(i = 0; i<vecsize-1;i++)
            {
                if(j<strs[i].size() && j<strs[i+1].size())
                {
                    if(strs[i][j]==strs[i+1][j])
                    {
                        ycom=true;
                    }
                    else
                    {
                        ycom=false;
                        return result;
                    }
                }
                else
                {
                    return result;
                }
            }
            if(ycom)
            {
                result.push_back(strs[i][j]);
            }
            j++;
        }
        return result;
    }
};