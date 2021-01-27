#include <iostream>
#include <cmath>

using namespace std;

struct tree
{
    int data;
    tree* left;
    tree* right;

    tree(int _data = 0, tree* _left = NULL, tree* _right = NULL) {
        data = _data;
        left = _left;
        right = _right;
    }
};

void Insert(tree* &leaf, int x) {
    if (leaf->data > x) {
        if (leaf->left == NULL) {
            leaf->left = new tree{x};
        }
        else {
            Insert(leaf->left, x);
        }
    }
    else {
        if (leaf->right == NULL) {
            leaf->right = new tree{x};
        }
        else {
            Insert(leaf->right, x);
        }
    }
}

void InsertTree(int x, tree* &leaf) {
    if (leaf == NULL) {
        leaf = new tree{x};
    }
    else {
        Insert(leaf, x);
    }
}

bool Szukaj(tree* node, int key) {
    if (node == NULL) {
        return NULL;
    }

    if (node->data == key)
        return true;

    if (node->data < key) {
        Szukaj(node->right, key);
    }
    else Szukaj(node->left, key);
}

//Zad. 5
/*
    a)
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6
               \
                7
    b)
             4
           /   \
          2     6
         / \   / \
        1   3 5   7

    c)
              1
               \
                6
               / \
              2   7
               \
                4
               / \
              3   5

Zad. 6

      2
       \
        3
         \
          4
           \
            5
             \
              6
               \
                7

    b)
             5
           /   \
          2     6
         / \     \
        1   3     7

    c)
                6
               / \
              2   7
               \
                4
               / \
              3   5

*/


int main() {

    return 0;
}
