class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        // dp[i][j] will store the maximum score Alice can get from stones i to j
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Prefix sum array to quickly calculate the sum of any subarray in O(1) time
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }
        
        // Loop over the length of the subarray (from 2 to n)
        for (int len = 2; len <= n; ++len) {
            // Loop over the starting index of the subarray
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1; // Ending index of the subarray
                
                // Try every possible split point 'k' between i and j-1
                for (int k = i; k < j; ++k) {
                    // Calculate sums of the left and right parts using the prefix array
                    int left_sum = prefix[k + 1] - prefix[i];
                    int right_sum = prefix[j + 1] - prefix[k + 1];
                    
                    if (left_sum < right_sum) {
                        // Bob throws away the right row, Alice keeps the left row
                        dp[i][j] = max(dp[i][j], left_sum + dp[i][k]);
                    } else if (left_sum > right_sum) {
                        // Bob throws away the left row, Alice keeps the right row
                        dp[i][j] = max(dp[i][j], right_sum + dp[k + 1][j]);
                    } else {
                        // Sums are equal, Alice can choose either one to maximize her score
                        dp[i][j] = max(dp[i][j], left_sum + max(dp[i][k], dp[k + 1][j]));
                    }
                }
            }
        }
        
        // The result for the entire array from index 0 to n-1
        return dp[0][n - 1];
    }
};