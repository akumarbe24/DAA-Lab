#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

// Comparator for min-heap
struct compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Print Huffman Codes
void printCodes(Node* root, string code) {
    if (!root)
        return;

    // Leaf node
    if (root->left == NULL && root->right == NULL) {
        cout << root->ch << "\t\t" << code << endl;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cin >> n;

    vector<char> chars(n);
    vector<int> freq(n);

    for (int i = 0; i < n; i++)
        cin >> chars[i];

    for (int i = 0; i < n; i++)
        cin >> freq[i];

    priority_queue<Node*, vector<Node*>, compare> pq;

    for (int i = 0; i < n; i++)
        pq.push(new Node(chars[i], freq[i]));

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    Node* root = pq.top();

    cout << "Character\tHuffman Code\n";
    printCodes(root, "");

    return 0;
}
