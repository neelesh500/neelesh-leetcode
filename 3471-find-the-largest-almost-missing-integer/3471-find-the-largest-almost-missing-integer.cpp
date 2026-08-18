class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        int res = -1;
        if (k == n) {
            for (int num : nums) {
                res = max(res, num);
            }
            return res;
        }
        if (k == 1) {
            for (const auto& pair : freq) {
                if (pair.second == 1) {
                    res = max(res, pair.first);
                }
            }
            return res;
        }
        if (freq[nums[0]] == 1) {
            res = max(res, nums[0]);
        }
        if (freq[nums[n - 1]] == 1) {
            res = max(res, nums[n - 1]);
        }
        
        return res;
    }
};