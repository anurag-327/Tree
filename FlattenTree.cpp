TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    TreeNode<int> *curr = root;
    while (curr != NULL)
    {
        if (curr->left != NULL)
        {
            TreeNode<int> *prev = curr->left;
            while (prev->right)
            {
                prev = prev->right;
            }
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
    return root;
}

// Morris traversal logic- connect right of right most node to root->right;
// and right most node of left tree to right of root and