/*
    The general idea is using sliding Kadane Algorithm
    if there is any cumulative product with zero value(0) change to one(1)

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