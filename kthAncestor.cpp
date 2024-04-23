BinaryTreeNode<int> *solve(BinaryTreeNode<int> *root, int target, int &k)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == target)
    {
        return root;
    }
    BinaryTreeNode<int> *left = solve(root->left, target, k);
    BinaryTreeNode<int> *right = solve(root->right, target, k);
    if (left == NULL && right != NULL)
    {
        k--;
        if (k == 0)
        {
            // k=INT_MAX;// so that it doesnot interfare in later calls
            // replacing above line will work too just make it k==0
            return root;
        }
        return right; // if condn doesnot match return left
    }
    if (left != NULL && right == NULL)
    {
        k--;
        if (k == 0)
        {
            // k=INT_MAX;// so that it doesnot interfare in later calls
            return root;
        }
        return left;
    }
    return NULL;
}
int findKthAncestor(BinaryTreeNode<int> *root, int targetNodeVal, int k)
{
    // Write your code here.
    BinaryTreeNode<int> *ans = solve(root, targetNodeVal, k);
    if (ans == NULL || ans->data == targetNodeVal) // it means we are geting same node as ancestor in case of rooot node
        return -1;
    else
        return ans->data;
}