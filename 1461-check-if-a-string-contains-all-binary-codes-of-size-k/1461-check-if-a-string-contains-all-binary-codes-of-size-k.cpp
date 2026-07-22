class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        int totalRequired = 1 << k; // 2^k binary codes hone chahiye
        
        // Agar string hi itni chhoti hai ki 2^k codes nahi aa sakte
        if (n < k + totalRequired - 1) {
            return false;
        }
        
        unordered_set<string> seen;
        
        for (int i = 0; i <= n - k; i++) {
            // k length ka substring nikal kar set me daal do
            seen.insert(s.substr(i, k));
            
            // Agar saare possible combinations mil gaye toh aage loop chalane ki zarurat nahi
            if (seen.size() == totalRequired) {
                return true;
            }
        }
        
        return seen.size() == totalRequired;
    }
};