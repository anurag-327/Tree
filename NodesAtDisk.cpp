/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    // mark parents of each node to traverse in reverse order also and then do levcel order on tree with extra node of parent
    void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->left)
            {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right)
            {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, bool> vis;
        unordered_map<TreeNode *, TreeNode *> parent;
        markParents(root, parent);
        queue<TreeNode *> q;
        q.push(target);
        int dis = 0;
        vis[target] = true;
        while (!q.empty())
        {
            if (dis++ == k)
                break;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                vis[curr] = true;
                if (curr->left && !vis[curr->left])
                {
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if (curr->right && !vis[curr->right])
                {
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                // moving towards parent also
                if (parent[curr] && !vis[parent[curr]])
                {
                    q.push(parent[curr]);
                    vis[parent[curr]] == true;
                }
            }
        }
        int size = q.size();
        vector<int> ans;
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};