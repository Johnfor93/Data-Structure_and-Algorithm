/*
    The easy solution is multiply all element and save on a variabel then iterate all data then using result multiplication divided with iterated data
    The problem using easy solution is:
        - If we encounter data with 0 value, will fail on Runtime Error because that will be a operation divided by 0

    The first idea is using prefix sum, but the prefix sum is only save all result before the element and not the after element
    So, we need to trace all data with prefix sum and suffix sum.

    The idea: 
        - https://www.geeksforgeeks.org/prefix-sum-array-implementation-applications-competitive-programming/
        - https://www.geeksforgeeks.org/suffix-sum-array/
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int rightProduct=1;

        vector<int> product(n);

        product[0] = 1;
        // Multiply all element that placed on left
        // Prefix sum
        for(int i=1; i<n; i++)
        {
            product[i] = product[i-1] * nums[i-1];
        }

        // Traceback all element RTL but we need a variable for save right product
        // Then multiply the left product that we have before with right product
        // Suffix sum
        for(int i=n-2; i>=0; i--)
        {
            rightProduct *= nums[i+1];
            product[i] = rightProduct * product[i];
        }

        return product;
    }
};