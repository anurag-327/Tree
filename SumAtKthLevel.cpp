void solve(BinaryTreeNode<int> *root, int i, int k, int &ans)
{
    if (root == NULL)
        return;
    if (i == k)
    {
        ans += root->data;
    }
    solve(root->left, i + 1, k, ans);
    solve(root->right, i + 1, k, ans);
}
int sumAtKthLevel(BinaryTreeNode<int> *root, int k)
{
    // Write your code here.
    int ans;
    solve(root, 1, k, ans);
    return ans;
}