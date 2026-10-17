class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_r = m;
        int min_c = n;
        
        for (const auto& op : ops) {
            if (op[0] < min_r) {
                min_r = op[0];
            }
            if (op[1] < min_c) {
                min_c = op[1];
            }
        }
        
        return min_r * min_c;
    }
};