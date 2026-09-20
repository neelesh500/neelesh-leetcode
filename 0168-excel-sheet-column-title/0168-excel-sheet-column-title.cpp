class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while (columnNumber > 0) {
            columnNumber--;
            int remainder = columnNumber % 26;
            result += (char)('A' + remainder);
            columnNumber /= 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};