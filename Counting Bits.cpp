class Solution {
public:

    /*
        This is naive appoarch
    */
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0; i<=n; i++)
        {
            int current = i;
            int currentResult = 0;
            while(current){
                if(current&1) currentResult++;
                current>>=1;
            }
            res.push_back(currentResult);
        }
        return res;
    }

    /*
        This is dynamic programming approach

        There is concurrent condition where
            t[N] = t[(N/2)%2]+t[(N/4)%2]+t[(N/8)%2]+...t[(N/x)%2]
        where x is nearest power of 2 with number N, also we now that
            t[N-(N/x)%2] = t[(N/2)%2]+t[(N/4)%2]+t[(N/8)%2]+...t[(N/(x/2))%2]
        so we can conclude the formula is
            t[N] = t[(N/x)%2]+t[N-(N/x)%2]
    */
    vector<int> countBits(int n) {
        vector<int> res;
        int nearestPower2=1;
        for(int i=0; i<=n; i++)
        {
            if(i==0)
            {
                res.push_back(0);
                continue;
            }
            if(i == nearestPower2*2)
            {
                nearestPower2=i;
            }

            res.push_back(res[i-nearestPower2]+1);
            
        }
        return res;
    }
};