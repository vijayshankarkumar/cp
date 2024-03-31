#include <iostream>
#include <string>
#include <vector>

struct  Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};


void serializeBT(Node* root, std::vector<std::string>& data) {
    if (root == nullptr) {
        data.push_back("null");
        return;
    }
    data.push_back(std::to_string(root->val));
    serializeBT(root->left, data);
    serializeBT(root->right, data);
}

Node* deserializeBT(std::vector<std::string>& data, int& idx) {
    if (idx >= data.size() || data[idx] == "null") {
        idx++;
        return nullptr;
    }

    Node* root = new Node(std::stoi(data[idx]));
    idx++;
    root->left = deserializeBT(data, idx);
    root->right = deserializeBT(data, idx);
    return root;
}


int main () {
    Node* root = new Node(1);
    Node* l1 = new Node(2);
    Node* r1 = new Node(3);
    root->left = l1;
    root->right = r1;
    Node* l2 = new Node(4);
    Node* r2 = new Node(5);
    r1->left = l2;
    r1->right = r2;
    Node* l3 = new Node(6);
    l2->left = l3;
    Node* l4 = new Node(7);
    Node* r4 = new Node(8);
    l3->left = l4;
    l3->right = r4;
    Node* r5 = new Node(9);
    r4->right = r5;

    std::vector<std::string> data;
    serializeBT(root, data);
    for (auto& it : data) {
        std::cout << it << ", ";
    }
    std::cout << std::endl;
    
    int idx = 0;
    Node* newRoot = deserializeBT(data, idx);

    std::vector<std::string> tada;
    serializeBT(newRoot, tada);
    for (auto& it : tada) {
        std::cout << it << ", ";
    }
    std::cout << std::endl;
    return 0;
}
