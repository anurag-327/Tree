#include <bits/stdc++.h>
/************************************************************

Following is the Binary Tree node class

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, vector<int>> mp;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        TreeNode<int> *temp = q.front().first;
        int hd = q.front().second;
        q.pop();
        mp[hd].push_back(temp->data);
        if (temp->left)
            q.push({temp->left, hd - 1});
        if (temp->right)
            q.push({temp->right, hd + 1});
    }

    for (auto it : mp)

    {

        ans.insert(ans.end(), it.second.begin(), it.second.end());
    }
    return ans;
}