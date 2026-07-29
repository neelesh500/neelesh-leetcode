#include <unordered_map>
#include <string>

class Solution {
public:
int romanToInt(string s) {
        std::unordered_map<char, int> values = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int total = 0;
        int max_val = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            int curr_val = values[s[i]];

            if (curr_val >= max_val) {
                total += curr_val;
                max_val = curr_val;
            } else {
                total -= curr_val;
            }
        }

        return total;
    }
};