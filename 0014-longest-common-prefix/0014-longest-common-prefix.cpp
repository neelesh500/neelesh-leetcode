#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    bool isCommonPrefix(const vector<string>& strs, int len) {
        string prefix = strs[0].substr(0, len);
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i].compare(0, len, prefix) != 0)
                return false;
        }
        return true;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        int minLen = strs[0].length();
        for (const string& s : strs) {
            minLen = min(minLen, (int)s.length());
        }

        int low = 1, high = minLen;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isCommonPrefix(strs, mid)) {
                low = mid + 1; 
            } else {
                high = mid - 1;
            }
        }

        return strs[0].substr(0, (low + high) / 2);
    }
};