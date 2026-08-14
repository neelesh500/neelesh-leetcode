class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0;
        int maxLength = 0;
        int freq[26] = {0}; 

        for (int right = 0; right < s.length(); right++) {
            freq[s[right] - 'a']++; 

            while (freq[s[right] - 'a'] > 2) {
                freq[s[left] - 'a']--; 
                left++; 
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};