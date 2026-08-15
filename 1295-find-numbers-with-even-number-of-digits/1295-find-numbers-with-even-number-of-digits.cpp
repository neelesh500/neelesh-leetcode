class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int evenDigitCount = 0; 
        for (int i = 0; i < nums.size(); i++) {
            int currentNum = nums[i];
            int digitCount = 0;
            while (currentNum > 0) {
                currentNum = currentNum / 10;
                digitCount++;
            }
            if (digitCount % 2 == 0) {
                evenDigitCount++;
            }
        }
        
        return evenDigitCount;
    }
};