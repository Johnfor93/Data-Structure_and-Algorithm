class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        long long coinNum[amount+1];
        fill_n(coinNum, amount+1, INT_MAX);
        coinNum[0]=0;
        for(int i=0; i<amount; i++)
        {
            if(coinNum[i] == INT_MAX ) continue;
            for(int j=0; j<coins.size(); j++)
            {
                if((long long)coins[j]>(long long)amount) continue;
                if((long long)i+coins[j]>(long long)amount) continue;
                coinNum[i+coins[j]]=min(coinNum[i+coins[j]], coinNum[i]+1);
            }
        }
        if(coinNum[amount]==INT_MAX) return -1;
        return coinNum[amount];
    }
};