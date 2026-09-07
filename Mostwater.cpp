class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int r = height.size()-1;
        int l = 0;
        int max = 0;
        int mins = 0;
        while(l<r)
        {
            mins = min(height[l],height[r]);
            if((mins*(r-l))>max)
            {
                max = mins*(r-l);
            }
            if(height[l]<height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return max;
    }
};