class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=prices[0], max=prices[0], maxProfit = 0;
        for(int i=1; i< prices.size(); i++)
        {
            if(prices[i]<min)
            {
                maxProfit = max(maxProfit , max-min);
                min = prices[i];
                max = prices[i];
            }
            if(prices[i]>max)
            {
                max=prices[i];
            }
        }
        return max(maxProfit , max-min);
    }
};