class Solution {
public:
    Node* connect(Node* root) {
        if (!root || !root->left || !root->right) return root;

        // Connect left child to right child
        root->left->next = root->right;

        // Connect right child to the next left child (if available)
        if (root->next)
            root->right->next = root->next->left;

        // Recurse for left and right subtree
        connect(root->left);
        connect(root->right);

        return root;
    }
};
