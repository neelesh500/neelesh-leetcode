class Solution {
public:
int diameter=0;
int diameterOfBinaryTree(TreeNode*root){
    MaxpathBT(root);
    return diameter;
}
int MaxpathBT(TreeNode*root){
    if (root==NULL)
    return 0;
    int LP=MaxpathBT(root->left);
        int RP=MaxpathBT(root->right);
        int maxdiameter=LP+RP;
        diameter=max(diameter,maxdiameter);

        return max(LP,RP)+1;

}
        
    
};