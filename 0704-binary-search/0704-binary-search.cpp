class Solution {
public:
    int search(vector<int>& n, int target) {
        int l = 0;  // l=left
        int r = n.size() - 1; //r= right
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (n[mid] == target) {
                return mid;
            } 
            else if (n[mid] < target) {
                l = mid + 1;
            } 
            else {
                r = mid - 1;
            }
        }
        return -1;
    }
};