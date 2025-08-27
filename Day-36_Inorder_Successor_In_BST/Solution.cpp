//Brute Force Approach
void inorder(Node* root, Node* x, Node*& prev, int& ans) {
    if (!root) return;
    
    inorder(root->left, x, prev, ans);

    if (prev == x && ans == -1) { // Found the successor
        ans = root->data;
        return;
    }
    prev = root;

    inorder(root->right, x, prev, ans);
}

int inOrderSuccessor(Node *root, Node *x) {
    Node* prev = nullptr;
    int ans = -1;
    inorder(root, x, prev, ans);
    return ans;
}

//Optimized Approach
if (!root || !x) return -1;

    // Case 1: x has a right subtree → successor is leftmost of right subtree
    if (x->right) {
        Node* curr = x->right;
        while (curr->left) curr = curr->left;
        return curr->data;
    }

    // Case 2: No right subtree → go up the tree
    Node* succ = nullptr;
    Node* curr = root;
    while (curr) {
        if (x->data < curr->data) {
            succ = curr;
            curr = curr->left;
        } else if (x->data > curr->data) {
            curr = curr->right;
        } else {
            break;
        }
    }

    return succ ? succ->data : -1;