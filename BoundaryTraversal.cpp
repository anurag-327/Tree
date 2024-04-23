#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void getleaf(TreeNode<int> *root, vector<int> &leaf)
{
    if (root->left == NULL && root->right == NULL)
    {
        leaf.push_back(root->data);
        return;
    }
    if (root->left)
        getleaf(root->left, leaf);
    if (root->right)
        getleaf(root->right, leaf);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> ans;
    if (root == NULL)
        return ans;

    ans.push_back(root->data);
    TreeNode<int> *curr = root->left;

    // left boundary
    while (curr)
    {
        if (curr->left != NULL || curr->right != NULL)
            ans.push_back(curr->data);
        if (curr->left != NULL)
            curr = curr->left;
        else
            curr = curr->right;
    }

    // leaf nodes
    vector<int> leaf;
    getleaf(root, leaf);
    for (auto it : leaf)
        ans.push_back(it);

    // right boundary
    curr = root->right;
    vector<int> temp;
    while (curr)
    {
        if (curr->left != NULL || curr->right != NULL)
            temp.push_back(curr->data);
        if (curr->right != NULL)
            curr = curr->right;
        else
            curr = curr->left;
    }
    reverse(temp.begin(), temp.end());
    for (auto it : temp)
        ans.push_back(it);

    return ans;
}