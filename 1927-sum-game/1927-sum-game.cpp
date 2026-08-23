class Solution {
public:
    bool sumGame(string num) {
        int sum[2] = {0, 0}, q[2] = {0, 0};
        int n = num.length();

        for (int i = 0; i < n; ++i) {
            int j = i / (n >> 1);
            if (num[i] == '?')
                q[j]++;
            else
                sum[j] += num[i] - '0';
        }

        return ((q[0] + q[1]) & 1) || 
               ((sum[0] - sum[1]) << 1) != (q[1] - q[0]) * 9;
    }
};