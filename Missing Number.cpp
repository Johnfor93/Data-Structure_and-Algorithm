class Solution {
public:
    /*
        Bitwise XOR Operation
        Time Complexity: O(n)
        Extra Space Complexity: O(1)

        For any number, number XOR number is 0
        So, we need to iterate 0 to N with XOR Operation and also XOR operation the data
    */
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int resultXOR=0;
        for(int i=0; i<n; i++)
        {
            resultXOR ^= (nums[i]^i);
        }
        return resultXOR^n;
    }

    /*
        Math solution
        Time Complexity: O(n)
        Extra Space Complexity: O(1)

        Sum all data and number from 0 to n
        Then find difference from two addition data
    */
    // int missingNumber(vector<int>& nums) {
    //     int n=nums.size();
    //     int result = (n*(n+1))/2;
    //     int resultArr=0;
    //     for(int i=0; i<n; i++)
    //     {
    //         resultArr+=nums[i];
    //     }
    //     return result-resultArr;
    // }
};