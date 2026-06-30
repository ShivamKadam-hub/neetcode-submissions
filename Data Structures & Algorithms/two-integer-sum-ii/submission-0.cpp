class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l = 0;  int r = n-1;
        int sum;
        while(l<r){
            sum = nums[l]+nums[r];
            if(sum==target)return {l+1,r+1};
            else if(sum<target) l++;
            else r--;
        }
        return {};
    }
};
