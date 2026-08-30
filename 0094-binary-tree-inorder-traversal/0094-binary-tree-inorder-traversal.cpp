class Solution {
private:
    void inorder(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, result);   // 1. Left
        result.push_back(root->val);   // 2. Root
        inorder(root->right, result);  // 3. Right
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};