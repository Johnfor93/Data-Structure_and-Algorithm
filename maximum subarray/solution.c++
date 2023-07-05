/*
    The general idea is using sliding Kadane Algorithm
    Moving a subarray if there is any cumulative sum with negative value change current cumulative sum with 0
    If next data negative, the cumulative sum will be even worse
    If next data positive, the next data is a new maximum sum

    Time Complexity : O(N)
    Space Complexity: O(1)
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int cur_sum = 0;
        int size = nums.size();
        // Sliding windows
        for(int i=0; i<size; i++)
        {
            // if current sum negative the next current sum must be reset
            // if next data negative, the cumulative sum will be even worse
            // if next data positive, the next data is a new maximum sum
            if(cur_sum < 0 ) cur_sum=0;
            cur_sum+=nums[i];

            // 2 line of code above can be replaced by this line
            // cur_sum = max(cur_sum+nums[i], nums[i]);

            maxSum = max(cur_sum, maxSum);
        }
        return maxSum;
    }
};