class Solution {

    int ans = Integer.MIN_VALUE;
    private int find(TreeNode root) {
        if(root == null) 
        return 0;

        int l = Math.max(0,find(root.left));
        int r = Math.max(0,find(root.right));

        int curr = l + r + root.val;
        ans = Math.max(ans,curr);

        return Math.max(l,r) + root.val;
    }
    public int maxPathSum(TreeNode root) {
        find(root);
        return ans;
    }
}