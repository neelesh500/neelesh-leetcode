class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        
        
        auto gcd = [](long long a, long long b, auto& self) -> long long {
            return b == 0 ? a : self(b, a % b, self);
        };
        
        auto lcm = [&](long long a, long long b) -> long long {
            if (a == 0 || b == 0) return 0;
           
            return (a / gcd(a, b, gcd)) * b;
        };

        long long low = 1, high = 2e15, ans = high;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = 0;
            
            for (int i = 1; i < (1 << n); ++i) {
                long long current_lcm = 1;
                int set_bits = 0;
                
                for (int j = 0; j < n; ++j) {
                    if ((i >> j) & 1) {
                        set_bits++;
                        current_lcm = lcm(current_lcm, coins[j]);
                        if (current_lcm > mid) {
                            current_lcm = -1;
                            break;
                        }
                    }
                }
                
                if (current_lcm != -1 && current_lcm <= mid) {
                    if (set_bits % 2 == 1) {
                        count += mid / current_lcm;
                    } else {
                        count -= mid / current_lcm;
                    }
                }
            }
            if (count >= k) {
                ans = mid;
                high = mid - 1; 
            } else {
                low = mid + 1;  
            }
        }
        
        return ans;
    }
};