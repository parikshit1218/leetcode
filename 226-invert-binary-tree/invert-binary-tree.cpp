class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        // Base case
        if (root == NULL) {
            return NULL;
        }

        // Swap left and right children
        swap(root->left, root->right);

        // Invert left subtree
        invertTree(root->left);

        // Invert right subtree
        invertTree(root->right);

        return root;
    }
};