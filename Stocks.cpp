class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int minSoFar = prices[0];
        int size = prices.size();
        for (int i = 0; i < size; i++) {
            if (prices[i] < minSoFar) {
                minSoFar = prices[i];
            }
            if ((prices[i] - minSoFar) > maxP) {
                maxP = prices[i] - minSoFar;
            }
        }
        return maxP;
    }
};
}