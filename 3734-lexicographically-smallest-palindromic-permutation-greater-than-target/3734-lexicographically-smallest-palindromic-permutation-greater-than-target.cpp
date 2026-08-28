class Solution {
public:

    string buildPalindrome(const string& half, char mid) {
        string ans = half;

        if (mid != '#')
            ans += mid;

        for (int i = (int)half.size() - 1; i >= 0; i--)
            ans += half[i];

        return ans;
    }

    string nextHalf(vector<int> cnt, const string& target) {
        int m = target.size();

        // Try to make the answer greater at the
        // rightmost possible position.
        for (int i = m - 1; i >= 0; i--) {

            vector<int> available = cnt;

            bool possible = true;

            // Match target[0 ... i-1]
            for (int j = 0; j < i; j++) {
                int c = target[j] - 'a';

                if (available[c] == 0) {
                    possible = false;
                    break;
                }

                available[c]--;
            }

            if (!possible)
                continue;

            // At position i, choose the smallest
            // character strictly greater than target[i].
            for (int c = target[i] - 'a' + 1; c < 26; c++) {

                if (available[c] == 0)
                    continue;

                string res = target.substr(0, i);
                res += char('a' + c);

                available[c]--;

                // Fill remaining characters in sorted order.
                for (int x = 0; x < 26; x++) {
                    while (available[x] > 0) {
                        res += char('a' + x);
                        available[x]--;
                    }
                }

                return res;
            }
        }

        return "";
    }

    // IMPORTANT:
    // This name must match LeetCode's expected function name.
    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        // Check if a palindrome is possible.
        int odd = 0;
        char mid = '#';

        for (int c = 0; c < 26; c++) {
            if (freq[c] % 2) {
                odd++;
                mid = char('a' + c);
            }
        }

        // More than one odd-frequency character
        // means no palindrome is possible.
        if (odd > 1) {
            return "";
        }

        // Characters used in the left half.
        vector<int> halfFreq(26);

        for (int c = 0; c < 26; c++) {
            halfFreq[c] = freq[c] / 2;
        }

        int m = n / 2;

        string targetHalf = target.substr(0, m);

        // Find the smallest left half that is
        // strictly greater than targetHalf.
        string greaterHalf = nextHalf(halfFreq, targetHalf);

        string answer = "";

        if (!greaterHalf.empty()) {
            answer = buildPalindrome(greaterHalf, mid);
        }

        // Also check the case where the left half is
        // exactly equal to targetHalf.
        vector<int> check = halfFreq;

        bool exactPossible = true;

        for (char c : targetHalf) {
            int idx = c - 'a';

            if (check[idx] == 0) {
                exactPossible = false;
                break;
            }

            check[idx]--;
        }

        if (exactPossible) {

            string candidate =
                buildPalindrome(targetHalf, mid);

            if (candidate > target) {

                if (answer.empty() || candidate < answer) {
                    answer = candidate;
                }
            }
        }

        return answer;
    }
};