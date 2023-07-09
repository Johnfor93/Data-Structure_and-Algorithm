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

int main(){
	vector<int> nums{4, 3, 5, 2, 8 , 9};
	
	cout<<lengthOfLIS(nums)<<endl;
}
