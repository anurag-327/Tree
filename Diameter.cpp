/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int diameter(TreeNode<int> *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int lh = diameter(root->left, maxi);
    int rh = diameter(root->right, maxi);
    maxi = max(maxi, lh + rh);
    return (1 + max(lh, rh));
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Write Your Code Here.
    int maxi = 0;
    diameter(root, maxi);
    return maxi;
}