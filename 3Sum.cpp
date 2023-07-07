#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n=nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    set<vector<int>> setResult;

    for(int i=0; i<n; i++)
    {
        int left = i+1;
        int right = n-1;
        while(left < right)
        {

            int currentRes = nums[i] + nums[left] + nums[right];
            if(currentRes == 0)
            {
                setResult.insert({nums[i], nums[left], nums[right]});
                left++;
                right--;
            }
            else if(currentRes < 0) left++;
            else right--;
        }
    }

    for(auto resData: setResult){
        result.push_back(resData);
    }
    return result;
}

int main(){
	vector<int> nums;
	nums.push_back(-4);
	nums.push_back(-1);
	nums.push_back(-1);
	nums.push_back(-0);
	nums.push_back(1);
	nums.push_back(2);
	
	vector<vector<int>> result = threeSum(nums);
	cout<<"Result are here:\n";
	for(int i=0; i< result.size(); i++)
	{
		for(int j=0; j<result[i].size(); j++)
		{
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
}
