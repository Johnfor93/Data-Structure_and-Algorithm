/*
    We have 2 pointer that indicate the first index and the last index.
    We iterate to change these pointer by compare the height of the index.
    If left is smaller than right then index left will be increment

    Because if want to have a max area, we need highest and widest as possible.
    When there is [2,5,12,6,4,1,4]
    After first iteration we want to keep 4 as right index because it bigger than 2 hopefully we found data that bigger than 2 after the iteration with only sacrifice 1 wide unit. The iteration go until the index left is equal or greater than right index.

*/

class Solution {
public:
    int maxArea(vector<int>& arr) {
        int left=0, right=arr.size()-1, maxArea=INT_MIN;
        while(left<right)
        {
            int curArea = min(arr[left], arr[right])*(right-left);
            maxArea = max(maxArea, curArea);
            if(arr[left]<arr[right]) left++;
            else right--;
        }
        return maxArea;
    }
};