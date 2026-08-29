class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> indexed_nums(n);
        for (int i = 0; i < n; ++i) {
            indexed_nums[i] = {nums[i], i};
        }
        sort(indexed_nums.begin(), indexed_nums.end());
        vector<vector<pair<int, int>>> groups;
        groups.push_back({indexed_nums[0]});
        for (int i = 1; i < n; ++i) {
            if (indexed_nums[i].first - indexed_nums[i - 1].first <= limit) {
                groups.back().push_back(indexed_nums[i]);
            } else {
                groups.push_back({indexed_nums[i]});
            }
                }
        vector<int> result(n);
        for (const auto& group : groups) {
            vector<int> indices;
            for (const auto& p : group) {
                indices.push_back(p.second);
            }
            
            sort(indices.begin(), indices.end());
            
            for (size_t i = 0; i < indices.size(); ++i) {
                result[indices[i]] = group[i].first;
            }
        }
        
        return result;
    }
};