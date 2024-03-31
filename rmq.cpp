#include <iostream>
#include <vector>

struct Node {
    Node* left;
    Node* right;
    int l;
    int r;
    int val;
    Node() {};
    Node(int l, int r): l(l), r(r) {}
};

void buildRmqTreeUtil(Node* root,  const std::vector<int>& arr, int l, int r) {
    root->l = l;
    root->r = r;
    if (l == r) {
        root->val = arr[l];
        return;
    }
    Node* left = new Node(l, (l + r) / 2);
    Node* right = new Node(((l + r) / 2) + 1, r);
    buildRmqTreeUtil(left, arr, l, (l + r) / 2);
    buildRmqTreeUtil(right, arr, ((l + r) / 2) + 1, r);
    root->left = left;
    root->right = right;
    root->val = std::min(root->left->val, root->right->val);
}

Node* buildRmqTree(const std::vector<int>& arr) {
    Node* root = new Node();
    buildRmqTreeUtil(root, arr, 0, arr.size() - 1);
    return root;
}

int rmq(const Node* root, int l, int r) {
    if (root->l == l && root->r == r) {
        return root->val;
    }
    if (r <= root->left->r) {
        return rmq(root->left, l, r);
    }
    if (l >= root->right->l) {
        return rmq(root->right, l, r);
    }
    return std::min(rmq(root->left, l, root->left->r), rmq(root->right, root->right->l, r));
}


int main() {
    std::vector<int> arr = {3, 5, 7, 1, 2, 6, 4, 2};
    Node* root = buildRmqTree(arr);
    std::cout << rmq(root, 0, 6) << std::endl;
    std::cout << rmq(root, 0, 2) << std::endl;
    std::cout << rmq(root, 4, 6) << std::endl;
    return 0;
}
