class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int minIdx = 0, maxIdx = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
        if (minIdx > maxIdx) swap(minIdx, maxIdx);
        int opt1 = maxIdx + 1;
        int opt2 = n - minIdx;
        int opt3 = (minIdx + 1) + (n - maxIdx);
        return min({opt1, opt2, opt3});
    }
};