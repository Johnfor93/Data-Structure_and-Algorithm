/*
    The idea: https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

    Because of this array sorted, then we should find the data with this condition
    data[i] > data[i+1]
    where data[i+1] is the smallest data in array because we know that array sorted in ascending order

    Time Complexity: O(log N)
*/

class Solution {
public:
    int pivotSearch(vector<int>&nums, int left, int right)
    {
        if(left > right || left == nums.size()-1) return 0;

        int mid = (right+left)/2;

        // Check next data for 
        if(nums[mid]>nums[mid+1]) return mid+1;
        if(nums[mid-1]>nums[mid]) return mid;

        if(nums[left] < nums[mid]) return pivotSearch(nums, left, mid-1);
        return pivotSearch(nums, mid, right);
    }
    int findMin(vector<int>& nums) {
        int pivotedIndex = pivotSearch(nums, 0, nums.size()-1);
        return nums[pivotedIndex];
    }
};