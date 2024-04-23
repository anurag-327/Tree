#include <bits/stdc++.h>
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
TreeNode<int> *buildtree2(vector<int> preorder, int prestart, int preend, vector<int> inorder, int instart, int inend, map<int, int> imap)
{
    if (prestart > preend || instart > inend)
        return NULL;

    TreeNode<int> *root = new TreeNode<int>(preorder[prestart]);
    int inroot = imap[root->data];
    int numsleft = inroot - instart;

    root->left = buildtree2(preorder, prestart + 1, prestart + numsleft, inorder, instart, inroot - 1, imap);
    root->right = buildtree2(preorder, prestart + numsleft + 1, preend, inorder, inroot + 1, inend, imap);
    return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    //    Write your code here
    map<int, int> imap;
    for (int i = 0; i < inorder.size(); i++)
    {
        imap[inorder[i]] = i;
    }
    TreeNode<int> *root = buildtree2(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, imap);
    return root;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *buildTreeHelper(vector<int> &postorder, int pstart, int pend, vector<int> &inorder, int istart, int iend, unordered_map<int, int> imap)
    {
        if (pstart > pend || istart > iend)
            return NULL;
        TreeNode *root = new TreeNode(postorder[pend]);
        int index = istart;
        while (inorder[index] != root->val)
            index++;
        int numsleft = index - istart;
        root->left = buildTreeHelper(postorder, pstart, pstart + numsleft - 1, inorder, istart, index - 1, imap);
        root->right = buildTreeHelper(postorder, pstart + numsleft, pend - 1, inorder, index + 1, iend, imap);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> imap;
        return buildTreeHelper(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, imap);
    }
};