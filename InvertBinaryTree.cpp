class Solution
{
public:
    void solve(TreeNode *&root)
    {
        if (root == nullptr)
            return;
        solve(root->left);
        solve(root->right);

        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    TreeNode *invertTree(TreeNode *root)
    {
        solve(root);
        return root;
    }
};