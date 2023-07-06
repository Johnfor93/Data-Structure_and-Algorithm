/*
    The idea: https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

    Because of this array sorted, then we should find the data with this condition
    data[left] < data[right]
    then data[left] is the smallest data in array because we know that array sorted in ascending order

    Time Complexity: O(log N)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        int left = 0, right = size-1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;

            // check if sorted, then left is the pivot Index
            if(nums[left] < nums[right]) return nums[left];

            if(nums[left] <= nums[mid]) left = mid+1;
            else right = mid;
        }
        return nums[left%size];
    }
};