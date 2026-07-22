/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int dfs(TreeNode* node, int currentSum) {
        if (!node) return 0;
        
        // Binary number ko update karo: sum = (sum * 2) + node->val
        currentSum = (currentSum << 1) | node->val;
        
        // Agar yeh leaf node hai, toh accumulated sum return kar do
        if (!node->left && !node->right) {
            return currentSum;
        }
        
        // Left aur right subtrees se sum nikal kar add kar lo
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};