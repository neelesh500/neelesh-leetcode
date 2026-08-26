class Solution {
public:
    std::string shortestBeautifulSubstring(std::string s, int k) {
        int n = s.length();
        std::string ans = "";
        int min_len = n + 1;

        // Sliding window / two pointers to find substrings with exactly k ones
        for (int i = 0; i < n; ++i) {
            int count_ones = 0;
            std::string curr = "";
            for (int j = i; j < n; ++j) {
                curr += s[j];
                if (s[j] == '1') {
                    count_ones++;
                }

                if (count_ones == k) {
                    int curr_len = curr.length();
                    // Check if we found a shorter length, or same length with lexicographically smaller string
                    if (curr_len < min_len) {
                        min_len = curr_len;
                        ans = curr;
                    } else if (curr_len == min_len) {
                        if (ans == "" || curr < ans) {
                            ans = curr;
                        }
                    }
                    break; // Since we want the shortest starting from 'i', we can break early
                }
            }
        }

        return ans;
    }
};