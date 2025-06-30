#include <iostream>
using namespace std;

// Class to represent a 2-3 Tree Node
class Node {
public:
    int key1, key2;
    Node *left, *middle, *right;
    bool isTwoNode; // true if 2-node, false if 3-node

    Node(int key) {
        key1 = key;
        key2 = -1; // Not used in a 2-node
        left = middle = right = nullptr;
        isTwoNode = true;
    }
};

// 2-3 Tree class
class TwoThreeTree {
private:
    Node* root;

    Node* insert(Node* node, int key, Node*& newChild, int& newKey) {
        if (node == nullptr) {
            newChild = nullptr;
            newKey = key;
            return nullptr;
        }

        if (node->left == nullptr) {
            // Leaf node
            if (node->isTwoNode) {
                // Insert into 2-node
                if (key < node->key1) {
                    node->key2 = node->key1;
                    node->key1 = key;
                } else {
                    node->key2 = key;
                }
                node->isTwoNode = false;
                return nullptr;
            } else {
                // Split 3-node
                if (key < node->key1) {
                    newKey = node->key1;
                    newChild = new Node(node->key2);
                    node->key1 = key;
                } else if (key < node->key2) {
                    newKey = key;
                    newChild = new Node(node->key2);
                } else {
                    newKey = node->key2;
                    newChild = new Node(key);
                }
                node->isTwoNode = true;
                return node;
            }
        }

        Node* newSubChild;
        int newSubKey;

        if (key < node->key1) {
            insert(node->left, key, newSubChild, newSubKey);
        } else if (node->isTwoNode || key < node->key2) {
            insert(node->middle, key, newSubChild, newSubKey);
        } else {
            insert(node->right, key, newSubChild, newSubKey);
        }

        if (newSubChild == nullptr) {
            return nullptr;
        }

        if (node->isTwoNode) {
            if (newSubKey < node->key1) {
                node->key2 = node->key1;
                node->key1 = newSubKey;
                node->right = node->middle;
                node->middle = newSubChild;
            } else {
                node->key2 = newSubKey;
                node->right = newSubChild;
            }
            node->isTwoNode = false;
            return nullptr;
        }

        if (newSubKey < node->key1) {
            newKey = node->key1;
            newChild = new Node(node->key2);
            newChild->left = node->middle;
            newChild->middle = node->right;
            node->key1 = newSubKey;
            node->middle = newSubChild;
        } else if (newSubKey < node->key2) {
            newKey = newSubKey;
            newChild = new Node(node->key2);
            newChild->left = newSubChild;
            newChild->middle = node->right;
        } else {
            newKey = node->key2;
            newChild = new Node(newSubKey);
            newChild->left = node->right;
            newChild->middle = newSubChild;
        }
        node->isTwoNode = true;
        return node;
    }

public:
    TwoThreeTree() {
        root = nullptr;
    }

    void insert(int key) {
        Node* newChild;
        int newKey;
        Node* newRoot = insert(root, key, newChild, newKey);
        if (newRoot != nullptr) {
            Node* temp = new Node(newKey);
            temp->left = newRoot;
            temp->middle = newChild;
            root = temp;
        }
    }

    // In-order Traversal
    void inOrder(Node* node) {
        if (node == nullptr) return;
        inOrder(node->left);
        cout << node->key1 << " ";
        inOrder(node->middle);
        if (!node->isTwoNode) {
            cout << node->key2 << " ";
            inOrder(node->right);
        }
    }

    void display() {
        inOrder(root);
        cout << endl;
    }
};

int main() {
    TwoThreeTree tree;
    int keys[] = {1,2,3,4,5,6};

    for (int key : keys) {
        tree.insert(key);
    }

    cout << "In-order traversal of the 2-3 Tree:" << endl;
    tree.display();

    return 0;
}
