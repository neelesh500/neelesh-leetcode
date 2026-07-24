class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int max_val = 0;
        for (int x : nums) {
            max_val = max(max_val, x);
        }
        
        // Next power of 2 find karte hain FWHT ke liye
        int sz = 1;
        while (sz <= max_val) {
            sz <<= 1;
        }
        
        vector<long long> count(sz, 0);
        for (int x : nums) {
            count[x]++;
        }
        
        // Fast Walsh-Hadamard Transform (FWHT) function
        auto fwht = [](vector<long long>& a) {
            int n = a.size();
            for (int len = 1; 2 * len <= n; len <<= 1) {
                for (int i = 0; i < n; i += 2 * len) {
                    for (int j = 0; j < len; ++j) {
                        long long u = a[i + j];
                        long long v = a[i + len + j];
                        a[i + j] = u + v;
                        a[i + len + j] = u - v;
                    }
                }
            }
        };
        
        vector<long long> a = count;
        fwht(a);
        
        // Triple XOR ke liye frequency ko cube kar dete hain frequency domain me
        vector<long long> c(sz);
        for (int i = 0; i < sz; ++i) {
            c[i] = a[i] * a[i] * a[i];
        }
        
        // Inverse FWHT
        fwht(c);
        for (int i = 0; i < sz; ++i) {
            c[i] /= sz;
        }
        
        // Count kitne unique XOR values non-zero hain
        int unique_count = 0;
        for (int i = 0; i < sz; ++i) {
            if (c[i] > 0) {
                unique_count++;
            }
        }
        
        return unique_count;
    }
};