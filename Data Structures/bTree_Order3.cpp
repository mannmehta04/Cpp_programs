#include <iostream>

const int T = 3;

class Node {
public:
    int keys[2 * T - 1];
    Node* children[2 * T];
    int num_keys;
    bool is_leaf;

    Node() {
        num_keys = 0;
        is_leaf = true;
    }

    Node(int key) {
        keys[0] = key;
        num_keys = 1;
        is_leaf = true;
    }

    void insertNonFull(int key) {
        int i = num_keys - 1;
        if (is_leaf) {
            while (i >= 0 && keys[i] > key) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = key;
            num_keys++;
        } else {
            while (i >= 0 && keys[i] > key) {
                i--;
            }
            if (children[i + 1]->num_keys == 2 * T - 1) {
                splitChild(i + 1, children[i + 1]);
                if (keys[i + 1] < key) {
                    i++;
                }
            }
            children[i + 1]->insertNonFull(key);
        }
    }

    void splitChild(int i, Node* y) {
        Node* z = new Node();
        z->is_leaf = y->is_leaf;
        z->num_keys = T - 1;
        for (int j = 0; j < T - 1; j++) {
            z->keys[j] = y->keys[j + T];
        }
        if (!y->is_leaf) {
            for (int j = 0; j < T; j++) {
                z->children[j] = y->children[j + T];
            }
        }
        y->num_keys = T - 1;
        for (int j = num_keys; j >= i + 1; j--) {
            children[j + 1] = children[j];
        }
        children[i + 1] = z;
        for (int j = num_keys - 1; j >= i; j--) {
            keys[j + 1] = keys[j];
        }
        keys[i] = y->keys[T - 1];
        num_keys++;
    }

    Node* search(int key) {
        int i = 0;
        while (i < num_keys && key > keys[i]) {
            i++;
        }
        if (keys[i] == key) {
            return this;
        }
        if (is_leaf) {
            return nullptr;
        }
        return children[i]->search(key);
    }
};

int main() {
    // create and initialize B-tree here
    // Node* root = nullptr;
    Node* root = new Node;
    root->num_keys = 0;
    root->is_leaf = true;


    // insert elements
    root->insertNonFull(5);
    root->insertNonFull(8);
    root->insertNonFull(12);
    root->insertNonFull(7);

    // perform search
    int key_to_search;
    std::cout << "Enter key to search: ";
    std::cin >> key_to_search;

    Node* result = root->search(key_to_search);
    if (result == nullptr) {
        std::cout << "Key not found\n";
    } else {
        std::cout << "Key found\n";
    }

    return 0;
}
