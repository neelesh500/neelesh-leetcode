class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        
        // Distribute the first two elements
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        
        // Loop through the remaining elements starting from index 2
        for (int i = 2; i < nums.size(); i++) {
            // Compare the last elements of arr1 and arr2
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }
        
        // Concatenate arr2 to the end of arr1
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        
        return arr1;
    }
};