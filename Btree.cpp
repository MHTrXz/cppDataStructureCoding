//
// Created by MHTrXz on 12/1/2022.
//

#include <iostream>
#include <stack>

using namespace std;

struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(char data) {
    struct Node *node = new struct Node();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void inOrder(Node *head)
{
    if (head->left != nullptr) inOrder(head->left);
    cout << head->data;
    if (head->right != nullptr) inOrder(head->right);
}

void preOrder(Node *head)
{
    cout << head->data;
    if (head->left != nullptr) preOrder(head->left);
    if (head->right != nullptr) preOrder(head->right);
}

void postOrder(Node *head)
{
    if (head->left != nullptr) postOrder(head->left);
    if (head->right != nullptr) postOrder(head->right);
    cout << head->data;
}

void depthFirst(Node *head)
{
    cout << head->data;
    if (head->left != nullptr) depthFirst(head->left);
    if (head->right != nullptr) depthFirst(head->right);
}


void breadthFirstCalc(Node *head)
{
    cout << head->left->data;
    cout << head->right->data;
    if (head->left != nullptr) breadthFirstCalc(head->left);
    if (head->right != nullptr) breadthFirstCalc(head->right);
}

void breadthFirst(Node *head)
{
    cout << head->data;
    breadthFirstCalc(head);
}

int search(string str, int start, int end, char value)
{
    int i;
    for (i = start; i <= end; i++) {
        if (str[i] == value)
            return i;
    }
    return -1;
}

Node* buildTree(string in, string pre, int inStart = 0, int inEnd = 0)
{
    if (inEnd == 0) inEnd = in.length();
    static int preIndex = 0;

    if (inStart > inEnd)
        return nullptr;

    Node *tNode = newNode(pre[preIndex++]);

    if (inStart == inEnd)
        return tNode;

    int inIndex = search(in, inStart, inEnd, tNode->data);

    tNode->left = buildTree(in, pre, inStart, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

    return tNode;
}

int main()
{
    Node *root = newNode('2');
    root->left = newNode('1');
    root->right = newNode('3');

    inOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;

    inOrder(buildTree("BAC", "BCA"));
}