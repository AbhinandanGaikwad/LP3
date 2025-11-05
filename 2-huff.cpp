#include <bits/stdc++.h>
using namespace std;

// Node structure for Huffman Tree
struct Node {
    char ch;              // Character
    int freq;             // Frequency
    Node *left, *right;   // Child pointers

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Comparator for priority queue (min-heap)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; // smallest frequency first
    }
};

// Recursive function to print Huffman Codes
void printCodes(Node* root, string code) {
    if (!root) return;

    // Leaf node = actual character
    if (!root->left && !root->right) {
        cout << root->ch << " : " << code << endl;
        return;
    }

    // Left edge → 0, Right edge → 1
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

// Function to build Huffman Tree
void huffmanEncoding(vector<char>& chars, vector<int>& freq) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Step 1: Create a leaf node for each character
    for (int i = 0; i < chars.size(); i++) {
        pq.push(new Node(chars[i], freq[i]));
    }

    // Step 2: Build Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* merged = new Node('$', left->freq + right->freq); // '$' = internal node
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    // Step 3: Print Huffman Codes
    Node* root = pq.top();
    cout << "\nHuffman Codes:\n";
    printCodes(root, "");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> chars(n);
    vector<int> freq(n);

    cout << "Enter characters:\n";
    for (int i = 0; i < n; i++) cin >> chars[i];

    cout << "Enter frequencies:\n";
    for (int i = 0; i < n; i++) cin >> freq[i];

    huffmanEncoding(chars, freq);

    return 0;
}
