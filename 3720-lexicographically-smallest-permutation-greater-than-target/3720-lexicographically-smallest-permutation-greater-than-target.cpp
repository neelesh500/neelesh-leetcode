class Solution {
public:
    std::string lexGreaterPermutation(std::string s, std::string target) {
        int n = s.length();
        std::vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        std::string current = "";
        std::string result = "";

        std::function<bool(int, bool)> backtrack = [&](int idx, bool isTight) {
            if (idx == n) {
                if (current > target) {
                    result = current;
                    return true;
                }
                return false;
            }

            int start = isTight ? (target[idx] - 'a') : 0;

            for (int i = start; i < 26; ++i) {
                if (freq[i] > 0) {
                    freq[i]--;
                    current.push_back('a' + i);

                    bool nextTight = isTight && (i == (target[idx] - 'a'));

                    if (backtrack(idx + 1, nextTight)) {
                        return true;
                    }

                    current.pop_back();
                    freq[i]++;
                }
            }
            return false;
        };

        if (backtrack(0, true)) {
            return result;
        }
        return "";
    }
};