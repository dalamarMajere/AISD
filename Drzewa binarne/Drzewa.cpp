#include <iostream>
#include <cmath>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d = 0, Node* l = NULL, Node* r = NULL) : data(d), left(l), right(r) {};
};

struct NodeCalc {
    char op;
    int number;
    node_calc* left;
    node_calc* right;
    node_calc(char o = NULL, int n = NULL){
        op =o;
        number = 0;
        left = NULL;
        right = NULL;
    }
};

int Size = 0;


void Insert(Node* &leaf, int x) {
    if (leaf->data > x) {
        if (leaf->left == NULL) {
            leaf->left = new Node{x};
        }
        else {
            Insert(leaf->left, x);
        }
    }
    else {
        if (leaf->right == NULL) {
            leaf->right = new Node{x};
        }
        else {
            Insert(leaf->right, x);
        }
    }
}

void InsertTree(int x, Node* &leaf) {
    if (leaf == NULL) {
        leaf = new Node{x};
    }
    else {
        Insert(leaf, x);
    }
}


bool Search(Node* leaf, int x) {
    if (leaf == NULL) return false;
    if (leaf->data == x) return true;

    return Search(leaf->left, x) || Search(leaf->right, x);
}

int NodeCount(Node* leaf) {
    if (leaf == NULL) return 0;

    return NodeCount(leaf->left) + NodeCount(leaf->right) + 1;
}

int LeavesCount(Node* leaf) {
    if (leaf == NULL) return 0;
    if (leaf->left == NULL && leaf->right == NULL)
        return 1;

    return LeavesCount(leaf->left) + LeavesCount(leaf->right);
}

int RightChildrenCount(Node* leaf) {
    if (leaf == NULL) return 0;


    RightChildrenCount(leaf->left);
    return RightChildrenCount(leaf->right) + 1;
}

int TreeHeight(Node* leaf) {
    if (leaf == NULL) return 0;

    return max(TreeHeight(leaf->left), TreeHeight(leaf->right)) + 1;
}

bool isBalanced(Node* leaf) {
    if (leaf == NULL) return true;

    int rightNode = 0;
    int leftNode = 0;

    if (leaf->left != NULL) {
        leftNode += TreeHeight(leaf->left) + 1;
    }
    else {
        rightNode += TreeHeight(leaf->right) + 1;
    }

    return (rightNode - leftNode) < 2;
}

bool isBST(Node* leaf) {

    bool ret = true;

    if (leaf->left != NULL) {
        if (leaf->data < leaf->left->data)
            return false;
        ret = isBST(leaf->left);
    }
    if (leaf->right != NULL) {
        if (leaf->data >= leaf->right->data)
            return false;
        ret = isBST(leaf->right);
    }

    return ret;
}


void Print(Node* leaf, int depth, char t) {
    if (leaf == NULL) return;

    for (int i = 1; i <= depth; i++)
        cout << ".";
    cout << leaf->data;
    cout << "\n";

    Print(leaf->left, depth + 1, 'l');
    Print(leaf->right, depth + 1, 'r');
}

void DeleteTree(Node* &leaf) {

    if (leaf->left != NULL) {
        DeleteTree(leaf->left);
    }
    if (leaf->right != NULL) {
        DeleteTree(leaf->right);
    }

    if (leaf->left == NULL && leaf->right == NULL) {
        delete leaf;
        leaf = NULL;
    }
}

void inorder_a(Node* leaf) {
    if (leaf->left != NULL) {
        inorder_a(leaf->left);
    }
    if (leaf->left != 0 && leaf->data - p->leaf->data < 2) {
        p->left->data += 2;
    }
    if (leaf->right != NULL) {
        inorder_a(leaf->right);
    }
}

void inorder_b(Node* leaf) {
    if (leaf->left != NULL) {
        inorder_b(leaf->left);
    }
    if (p->left == 0)
        p->right = 0;
    if (leaf->right != NULL) {
        inorder_b(leaf->right);
    }
}

void preorder_a(Node* leaf) {
    if (leaf->left != 0 && leaf->data - p->leaf->data < 2) {
        p->left->data += 2;
    }
    if (leaf->left != NULL) {
        preorder_a(leaf->left);
    }
    if (leaf->right != NULL) {
        preorder_a(leaf->right);
    }
}

void preorder_b(Node* leaf) {
    if (p->left == 0)
        p->right = 0;
    if (leaf->left != NULL) {
        preorder_b(leaf->left);
    }
    if (leaf->right != NULL) {
        preorder_b(leaf->right);
    }
}

void postorder_a(Node* leaf) {
    if (leaf->left != NULL) {
        postorder_a(leaf->left);
    }
    if (leaf->right != NULL) {
        postorder_a(leaf->right);
    }
    if (leaf->left != 0 && leaf->data - p->leaf->data < 2) {
        p->left->data += 2;
    }
}

void postorder_b(Node* leaf) {

    if (leaf->left != NULL) {
        postorder_b(leaf->left);
    }
    if (leaf->right != NULL) {
        postorder_b(leaf->right);
    }
    if (p->left == 0)
        p->right = 0;
}

Node* mirrorTree(Node* node) {
    if (node == NULL)
        return;

    Node* temp = new node{node->data};

	if (node->left != NULL)
		tmp->right = mirrorTree(node->left);
	if (node->right != NULL)
		tmp->left = mirrorTree(node->right);

	return tmp;
}

int eval(NodeCalc* node) {
    if (node->left == NULL && node->right == NULL) {
        return node->number;
    }
    if (node->op == '-')
        return eval(node->left) - eval(node-right);
    if (node->op == '+')
        return eval(node->left) + eval(node-right);
    if (node->op == '*')
        return eval(node->left) * eval(node-right);
    if (node->op == '/' )
        return eval(node->left) / eval(node-right);
}

Node* create_perfect_tree(int* a, const int k) {

    int ind = (int)(pow(2, k) - 1) / 2;
	Node* newNode = new Node{a[ind]};

	if (k > 1)
	{
		newNode->left = create_perfect_tree(a, k - 1);
		newNode->right = create_perfect_tree(a + index + 1, k - 1);
	}

	return newNode;
}


int main() {
    Node* root = NULL;
    int input[] = { 1, 5, 4, 2, 3, 6, 7};
    int N = 7;
    for (int i = 0; i < N; i++) {
        InsertTree(input[i], root);
    }

    cout << "Szukam 4..." << (Search(root, 4) == true ? "Znalazlem" : "Nie ma takiego elementu") << "\n";
    cout << "Szukam 10..." << (Search(root, 10) == true ? "Znalazlem" : "Nie ma takiego elementu") << "\n";
    Print(root, 0, 'v');

    cout << "\n";

    cout << "Liczba wiezcholkow: " << NodeCount(root) << "\n";
    cout << "Liczba lisci: " << LeavesCount(root) << "\n";
    cout << "Liczba prawych potomkow: " << RightChildrenCount(root) << "\n";
    cout << "Wysokosc drzewa: " << TreeHeight(root) << "\n";
    cout << "Czy jest zbalansowane? " << isBalanced(root) << "\n";
    cout << "Czy is BST?" << isBST(root) << "\n";

    Node* root1 = NULL;
    int input1[] = { 2, 3, 1 };
    for (int i = 0; i < 3; i++) {
        InsertTree(input1[i], root1);
    }
    Print(root1, 0, 'v');
    cout << "Czy jest zbalansowane? " << isBalanced(root1) << "\n";

    DeleteTree(root);
    cout << NodeCount(root) << "\n";
    return 0;
}
