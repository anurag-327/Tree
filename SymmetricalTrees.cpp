/*****************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

******************************************************/
bool issymmetrical(BinaryTreeNode<int> *left, BinaryTreeNode<int> *right)
{
    if (left == NULL || right == NULL)
        return left == right;

    if (left->data != right->data)
        return false;

    return (left->data == right->data && issymmetrical(left->left, right->right) && issymmetrical(left->right, right->left));
}

bool isSymmetric(BinaryTreeNode<int> *root)
{
    // Write your code here.
    if (root == NULL)
        return true;

    if (root->left == NULL and root->right == NULL)
        return false;
    bool ans = issymmetrical(root->left, root->right);
    return (ans);
}