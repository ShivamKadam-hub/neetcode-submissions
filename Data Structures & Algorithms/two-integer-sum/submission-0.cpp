class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0;i<nums.size();i++){
            int diff = target-nums[i];
            if(mp.find(diff)!=mp.end()) return {min(i,mp[diff]),max(i,mp[diff])};
            mp[nums[i]] = i;
        }
        return {};
    }
};