class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> current;
        vector<int> result;
        current.push_back(1);
        backtrack(current, result, rowIndex);
        return result;
    }
    void backtrack(vector<int> &current, vector<int> &result, int rowIndex)
    {
        if(current.size()==rowIndex+1)
        {
            result = current;
            return;
        }
        int s = current.size();
        vector<int> n(s+1);
        n[0] = 1;
        n[s] = 1;
        for(int i = 0; i<s-1; i++)
        {
            n[i+1] = current[i] + current[i+1];
        }
        backtrack(n,result,rowIndex);
    }
};