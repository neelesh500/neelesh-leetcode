class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd_count = 0;
        for (int num : nums1) {
            if (num % 2 != 0) {
                odd_count++;
            }
        }
        return true;
    }
};