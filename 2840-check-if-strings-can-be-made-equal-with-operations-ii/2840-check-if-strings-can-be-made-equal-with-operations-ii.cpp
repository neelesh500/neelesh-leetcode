class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int even1[26] = {0}, odd1[26] = {0};
        int even2[26] = {0}, odd2[26] = {0};
        
        for (int i = 0; i < s1.length(); i++) {
            if (i % 2 == 0) {
                even1[s1[i] - 'a']++;
                even2[s2[i] - 'a']++;
            } else {
                odd1[s1[i] - 'a']++;
                odd2[s2[i] - 'a']++;
            }
        }
        
        for (int i = 0; i < 26; i++) {
            if (even1[i] != even2[i] || odd1[i] != odd2[i]) {
                return false;
            }
        }
        
        return true;
    }
};