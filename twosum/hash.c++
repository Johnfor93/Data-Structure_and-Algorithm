class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> mapping;
        for(int i=0; i<nums.size(); i++){
            if(mapping[target - nums[i]]){
                res.push_back(i);
                res.push_back(mapping[target - nums[i]] - 1);
            }
            mapping[nums[i]] = i+1;
        }
        return res;
    }
};