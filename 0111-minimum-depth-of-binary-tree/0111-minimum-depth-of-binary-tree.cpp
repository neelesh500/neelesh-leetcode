class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr){
        return 0;
    }
    if (root->left==nullptr&& root->right==nullptr){
        return 1;
    }
    if(root->left==nullptr){
        return 1 + minDepth(root->right);
    }
    if(root->right==nullptr){
        return 1 + minDepth(root->left);
    }
    return 1 +std::min(minDepth(root->left),minDepth(root->right));
    }

};