#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure.

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> *root)
{

    // Write your code here.
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<pair<BinaryTreeNode<int> *, int>> todo;
    map<int, int> mapp;
    todo.push({root, 0});
    while (!todo.empty())
    {
        auto front = todo.front();
        todo.pop();
        BinaryTreeNode<int> *node = front.first;
        int line = front.second;
        mapp[line] = node->data;
        if (node->left != NULL)
            todo.push({node->left, line - 1});

        if (node->right != NULL)
            todo.push({node->right, line + 1});
    }
    for (auto it : mapp)
    {
        ans.push_back(it.second);
    }
    return ans;
}