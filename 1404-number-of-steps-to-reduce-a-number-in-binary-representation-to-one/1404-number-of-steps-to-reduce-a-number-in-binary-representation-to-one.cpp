class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        
        // Right to left traverse karenge string ko
        for (int i = s.length() - 1; i > 0; --i) {
            int bit = (s[i] - '0') + carry;
            
            if (bit % 2 == 1) { // Agar number odd hai (even + carry hone par)
                steps += 2;     // Ek step add karne ke liye, aur ek division ke liye
                carry = 1;      // Carry generate hoga
            } else {            // Agar number even hai
                steps += 1;     // Sirf division ke liye ek step
            }
        }
        
        return steps + carry;
    }
};