void solve(BinaryTreeNode<int> *root, int &cnt)
{
    if (root)
    {
        solve(root->left, cnt);
        if (root->left == NULL && root->right == NULL)
            cnt++;
        solve(root->right, cnt);
    }
}
int noOfLeafNodes(BinaryTreeNode<int> *root)
{
    // Write your code here.
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;

    int left = noOfLeafNodes(root->left);
    int right = noOfLeafNodes(root->right);
    return left + right;

    // int cnt=0;
    // solve(root,cnt);
    // return cnt;
}