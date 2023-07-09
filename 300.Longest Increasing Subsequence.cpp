#include<bits/stdc++.h>

using namespace std;

/*
    
    Time Complexity: O(n*n)
    Space Complexity: O(n)

    Iterate from index i=1 to n first
    Every iteration we do iteration from 0 to i
    The nested iteration we need to know how many element can built with i is the max number in sub sequence
    If we get i is greater than any data between 0 to data i we need update dp[i] with max(dp[i], dp[j]+1)
    This anticipate if any data that have most element with increasing subsequence
*/

int lengthOfLIS(vector<int>& nums) {
	int n = nums.size();
	vector<int>dp(n, 1);
	for(int i=1; i<n; i++){
        for(int j=0; j<i; j++)
        {
            if(nums[i]>nums[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
	}
	return *max_element(dp.begin(), dp.end());
}

    // Trying O(n log n) solution

    // The approach is every iteration is
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    // It's keep the subSequence element's
    vector<int> subSequence;
    subSequence.push_back(nums[0]);
    for(int i=1; i<n; i++){
        // Check if nums[i] < subSequence.end() there is new data is new data is highest
        if(nums[i] > subSequence.back()){
            subSequence.push_back(nums[i]);
        }
        else{
            // search to replace
            // Using lower_bound() function with O(log N) Time Complexity
            // Source: https://www.geeksforgeeks.org/lower_bound-in-cpp/
            // Iterator thats mean this is a pointer
            vector<int>::iterator low;
            low = lower_bound(subSequence.begin(), subSequence.end(), nums[i]);
            *low = nums[i];
        }
    }
    return subSequence.size();
}

int main(){
	vector<int> nums{4, 3, 5, 2, 8 , 9};
	
	cout<<lengthOfLIS(nums)<<endl;
}
