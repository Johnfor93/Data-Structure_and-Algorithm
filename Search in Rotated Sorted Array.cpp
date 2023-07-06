#include<bits/stdc++.h>

using namespace std;

/*
    Function Solution is below

    Search pivoted index like solution of Find Minimum on Sorted Rotated Array
    Then check the target, where the data exist between 0 to pivotedIndex-1 or pivotedIndex to size-1
    After that using binary search for search the data

    Idea come from https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
*/
int search(vector<int>& nums, int target) {
    int size = nums.size();
    int left = 0, right = size-1;
    while(left < right)
    {
        int mid = left + (right - left) / 2;

        // check if sorted, then left is the pivot Index
        if(nums[left] < nums[right]) break;

        if(nums[left] <= nums[mid]) left = mid+1;
        else right = mid;
    }
    
    // now left is pivotedIndex so we need to change left, right index for binser
	// If data not rotated, then search from 0 to last index   
	// if the data[0] less than target value, then we need to search from 0 to pivotedIndex-1
	// else then we need to search from pivotedIndex to last index
    if(left != 0){
    	if(nums[0]<=target){
    		right = left-1;
    		left=0;
		} else {
			right = size-1;
		}
	}

    while(left <= right)
    {
    	int mid = (left + right) / 2;

        // check if middle of data is the target
        if(nums[mid] == target) return mid;

        if(target > nums[mid]) left = mid+1;
        else right = mid-1;
    }
    
    return -1;
}

int main()
{
	vector<int> arr;
	arr.push_back(1);
	int target = 10;
	
	cout<<search(arr, target);
}
