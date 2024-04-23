class Solution
{
public:
    bool solve(TreeNode *root, int targetSum, int sum)
    {
        if (root == NULL)
        {
            return false;
        }
        sum += root->val;
        if (root->left == NULL && root->right == NULL)
        {
            if (targetSum == sum)
                return true;
        }
        bool lh = solve(root->left, targetSum, sum);
        bool rh = solve(root->right, targetSum, sum);
        return (lh || rh);
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return false;
        return solve(root, targetSum, 0);
    }
};