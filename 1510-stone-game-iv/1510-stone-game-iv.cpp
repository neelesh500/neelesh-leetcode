class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> grundy(n + 1, 0);
         for (int i = 1; i <= n; ++i) {
            unordered_set<int> reachable_grundy;
            for (int k = 1; k * k <= i; ++k) {
                reachable_grundy.insert(grundy[i - k * k]);
            }
            int mex = 0;
            while (reachable_grundy.count(mex)) {
                mex++;
            }
            grundy[i] = mex;
        }
        return grundy[n] > 0;
    }
};