class Solution {
    int ans = INT_MIN;
    
    private:
    int find(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int l = std::max(0, find(root->left));
        int r = std::max(0, find(root->right));
        
        int curr = l + r + root->val;
        ans = std::max(ans, curr);
        
        return std::max(l, r) + root->val;
    }
    
public:
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN; // Reset for multiple test cases if needed
        find(root);
        return ans;
    }
};