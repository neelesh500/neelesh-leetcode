class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int multiple = k;
        while (true) {
            if (num_set.find(multiple) == num_set.end()) {
                return multiple;
            }
            multiple += k;
        }
    }
};