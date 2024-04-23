#include <bits/stdc++.h>
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    queue<BinaryTreeNode<int> *> todo;
    todo.push(root);
    vector<int> ans;
    if (root == NULL)
        return ans;
    while (!todo.empty())
    {
        // for(int i=0;i<todo.size();i++)
        // {
        BinaryTreeNode<int> *front = todo.front();
        todo.pop();
        if (front->left != NULL)
            todo.push(front->left);
        if (front->right != NULL)
            todo.push(front->right);
        ans.push_back(front->val);
        // }
    }
    return ans;
}