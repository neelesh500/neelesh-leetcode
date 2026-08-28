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
        for (int i = m - 1; i >= 0; i--) {
            vector<int> available = cnt;
            bool possible = true;
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
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (available[c] == 0)
                    continue;
                string res = target.substr(0, i);
                res += char('a' + c);
                available[c]--;
                for (int x = 0; x < 26; x++) {
                    while (available[x] > 0) {
                        res += char('a' + x);
                        available[x]--;
                    }
                }
                return res;
            }
        }
        return "";    }
        string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        int odd = 0;
        char mid = '#';
        for (int c = 0; c < 26; c++) {
            if (freq[c] % 2) {
                odd++;
                mid = char('a' + c);
            }
        }
        if (odd > 1) {
            return "";
        }
        vector<int> halfFreq(26);
        for (int c = 0; c < 26; c++) {
            halfFreq[c] = freq[c] / 2;
        }
        int m = n / 2;
        string targetHalf = target.substr(0, m);
        string greaterHalf = nextHalf(halfFreq, targetHalf);
        string answer = "";
        if (!greaterHalf.empty()) {
            answer = buildPalindrome(greaterHalf, mid);
        }
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