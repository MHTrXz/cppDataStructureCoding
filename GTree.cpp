//
// Created by MHTrXz on 12/8/2022.
//

#include <vector>
#include <stack>
#include <queue>
#include <iostream>

#define SIZE 500

using namespace std;

struct Node {
    int value;
    vector<Node *> child;
};

Node *newNode(int value) {
    Node *temp = new Node;
    temp->value = value;
    return temp;
}

void BreadthFirst(Node *root) {
    if (root == nullptr)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        while (n > 0) {
            Node *p = q.front();
            q.pop();
            cout << p->value << " ";
            for (int i = 0; i < p->child.size(); i++)
                q.push(p->child[i]);
            n--;
        }
    }
}

void DepthFirstHandle(Node *root, stack<Node *> &q) {
    if (root == nullptr)
        return;
    q.pop();
    cout << root->value << " ";
    for (int i = root->child.size() - 1; i >= 0; i--) {
        q.push(root->child[i]);
    }
    DepthFirstHandle(q.top(), q);
}

void DepthFirst(Node *root) {
    stack<Node *> q;
    q.push(root);
    DepthFirstHandle(root, q);
}

int main() {
    /*   Let us create below tree
    *               10
    *         /   /     \     \
    *        2   34     56    100
    *       / \         |   /  |  \
    *      77  88       1  7   8   9
    */
    Node *root = newNode(10);
    (root->child).push_back(newNode(2));
    (root->child).push_back(newNode(34));
    (root->child).push_back(newNode(56));
    (root->child).push_back(newNode(100));
    (root->child[0]->child).push_back(newNode(77));
    (root->child[0]->child).push_back(newNode(88));
    (root->child[2]->child).push_back(newNode(1));
    (root->child[3]->child).push_back(newNode(7));
    (root->child[3]->child).push_back(newNode(8));
    (root->child[3]->child).push_back(newNode(9));

    cout << "Breadth-first\n";
    BreadthFirst(root);
    cout << endl << endl;
    cout << "Depth-first\n";
    DepthFirst(root);
    return 0;
}