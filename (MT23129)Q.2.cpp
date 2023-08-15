#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Function to insert a node into the BST
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

void rangeQuery(Node* root, int minValue, int maxValue, vector<int>& ans) {
    if (root == nullptr) {
        return;
    }

    if (root->key > minValue) {
        rangeQuery(root->left, minValue, maxValue, ans);
    }

    // Add the roots key in the result vector if it is within the range
    if (root->key >= minValue && root->key <= maxValue) {
        ans.push_back(root->key);
    }

    if (root->key < maxValue) {
        rangeQuery(root->right, minValue, maxValue, ans);
    }
}

// display the elements of the vector
void displayVector(const vector<int>& vec) {
    for (int ans : vec) {
        cout << ans << " ";
    }
    cout << endl;
}

int main() {
    Node* root = nullptr;

    // Insert elements into the BST
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 35);
    root = insert(root, 15);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);

    
    int minValue = 35;
    int maxValue = 60;
    vector<int> ans;
    rangeQuery(root, minValue, maxValue, ans);

    // Display the elements within the range
    cout << "Values within the range [" << minValue << ", " << maxValue << "]: ";
    displayVector(ans);

    return 0;
}
