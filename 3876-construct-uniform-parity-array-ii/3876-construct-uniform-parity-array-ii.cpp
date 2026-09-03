class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_val = nums1[0];
        bool has_odd = false;
        for (int num : nums1) {
            if (num < min_val) {
                min_val = num;
            }
            if (num % 2 != 0) {
                has_odd = true;
            }
        }
        if (min_val % 2 != 0) {
            return true;
        }
        return !has_odd;
    }
};