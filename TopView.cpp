#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<pair<TreeNode<int> *, int>> todo;
    map<int, int> mapp;
    todo.push({root, 0});
    while (!todo.empty())
    {
        auto front = todo.front();
        todo.pop();
        TreeNode<int> *node = front.first;
        int line = front.second;
        if (mapp.find(line) == mapp.end())
            mapp[line] = node->val;
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