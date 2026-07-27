#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        vector<int> left_candidates;
        int max_l = -1;
        for (int i = 0; i < n; ++i) {
            if (height[i] > max_l) {
                left_candidates.push_back(i);
                max_l = height[i];
            }
        }

        vector<int> right_candidates;
        int max_r = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (height[i] > max_r) {
                right_candidates.push_back(i);
                max_r = height[i];
            }
        }

        int max_water = 0;
        int i = 0;
        int j = 0;
        
        while (i < left_candidates.size() && j < right_candidates.size()) {
            int l_idx = left_candidates[i];
            int r_idx = right_candidates[j];

            if (l_idx >= r_idx) break;

            int h = min(height[l_idx], height[r_idx]);
            int width = r_idx - l_idx;
            max_water = max(max_water, width * h);

            if (height[l_idx] < height[r_idx]) {
                i++;
            } else {
                j++;
            }
        }

        return max_water;
    }
};