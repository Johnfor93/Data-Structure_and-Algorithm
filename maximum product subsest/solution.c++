/*
    The general idea is using sliding Kadane Algorithm
    if there is any cumulative product with zero value(0) change to one(1)

    We need to travese array twice RTL and LTR. There is case when the array value
    [-1, 2, 3, 4]
    If that case only using LTR the maximum result is -24 while the answer is 24 if we trace with RTL method

    Time Complexity : O(N)
    Space Complexity: O(1)
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxResult = INT_MIN;
        int size=nums.size();
        int curMult = 1;
        
        for(int i=0; i<size; i++)
        {
            curMult *= nums[i];
            maxResult = max(curMult, maxResult);
            if(curMult == 0) curMult = 1;
        }

        curMult =1;

        for(int i=size-1; i>=0; i--)
        {
            curMult *= nums[i];
            maxResult = max(curMult, maxResult);
            if(curMult == 0) curMult = 1;
        }

        return maxResult;
    }
};