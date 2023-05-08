//
// Created by MHTrXz on 12/16/2022.
//

#include <iostream>

using namespace std;

struct Node {
    int data;
    int balFact;
    Node *left;
    Node *right;
};

class avlTree {
private :
    Node *root;
public :
    avlTree()
    {
        root = nullptr;
    }

    ~avlTree()
    {
        delTree(root);
    }


    void setroot(Node *calc)
    {
        root = calc;
    }

    static Node *buildTree(Node *calc, int data, int *h)
    {
        Node *node1, *node2;

        if (!calc) {
            calc = new Node;
            calc->data = data;
            calc->left = nullptr;
            calc->right = nullptr;
            calc->balFact = 0;
            *h = 1;
            return (calc);
        } else if (data < calc->data) {
            calc->left = buildTree(calc->left, data, h);
            if (*h) {
                switch (calc->balFact) {
                    case 1 :
                        node1 = calc->left;
                        if (node1->balFact == 1) {
                            calc->left = node1->right;
                            node1->right = calc;
                            calc->balFact = 0;
                            calc = node1;
                        } else {
                            node2 = node1->right;
                            node1->right = node2->left;
                            node2->left = node1;
                            calc->left = node2->right;
                            node2->right = calc;
                            if (node2->balFact == 1)
                                calc->balFact = -1;
                            else
                                calc->balFact = 0;
                            if (node2->balFact == -1)
                                node1->balFact = 1;
                            else
                                node1->balFact = 0;
                            calc = node2;
                        }
                        calc->balFact = 0;
                        *h = 0;
                        break;

                    case 0 :
                        calc->balFact = 1;
                        break;
                    case -1 :
                        calc->balFact = 0;
                        *h = 0;
                }
            }
        } else if (data > calc->data) {
            calc->right = buildTree(calc->right, data, h);

            if (*h) {
                switch (calc->balFact) {
                    case 1 :
                        calc->balFact = 0;
                        *h = false;
                        break;
                    case 0 :
                        calc->balFact = -1;
                        break;
                    case -1 :
                        node1 = calc->right;
                        if (node1->balFact == -1) {
                            calc->right = node1->left;
                            node1->left = calc;
                            calc->balFact = 0;
                            calc = node1;
                        } else {
                            node2 = node1->left;
                            node1->left = node2->right;
                            node2->right = node1;
                            calc->right = node2->left;
                            node2->left = calc;
                            if (node2->balFact == -1)
                                calc->balFact = 1;
                            else
                                calc->balFact = 0;
                            if (node2->balFact == 1)
                                node1->balFact = -1;
                            else
                                node1->balFact = 0;
                            calc = node2;
                        }
                        calc->balFact = 0;
                        *h = false;
                }
            }
        }
        return (calc);
    }

    static void delTree(Node *calc)
    {
        if (calc != nullptr) {
            delTree(calc->left);
            delTree(calc->right);
        }
        delete (calc);
    }


    Node *insert(int data, int *h)
    {
        root = buildTree(root, data, h);
        return root;
    }
    
    Node *deleteData(Node *calc, int data, int *h)
    {
        Node *node;
        if (calc == nullptr) {
            return (calc);
        } else {
            if (data < calc->data) {
                calc->left = deleteData(calc->left, data, h);
                if (*h)
                    calc = balRight(calc, h);
            } else {
                if (data > calc->data) {
                    calc->right = deleteData(calc->right, data, h);
                    if (*h)
                        calc = balLeft(calc, h);
                } else {
                    node = calc;
                    if (node->right == nullptr) {
                        calc = node->left;
                        *h = true;
                        delete (node);
                    } else {
                        if (node->left == nullptr) {
                            calc = node->right;
                            *h = true;
                            delete (node);
                        } else {
                            node->right = del(node->right, node, h);
                            if (*h)
                                calc = balLeft(calc, h);
                        }
                    }
                }
            }
        }
        return (calc);
    }


    static Node *del(Node *success, Node *node, int *h)
    {
        if (success->left != nullptr) {
            success->left = del(success->left, node, h);
            if (*h)
                success = balRight(success, h);
        } else {
            Node *temp = success;
            node->data = success->data;
            success = success->right;
            delete (temp);
            *h = 1;
        }
        return (success);
    }


    static Node *balRight(Node *calc, int *h)
    {
        Node *temp1, *temp2;
        switch (calc->balFact) {
            case 1 :
                calc->balFact = 0;
                break;
            case 0 :
                calc->balFact = -1;
                *h = 0;
                break;
            case -1 :
                temp1 = calc->right;
                if (temp1->balFact <= 0) {
                    calc->right = temp1->left;
                    temp1->left = calc;
                    if (temp1->balFact == 0) {
                        calc->balFact = -1;
                        temp1->balFact = 1;
                        *h = 0;
                    } else {
                        calc->balFact = temp1->balFact = 0;
                    }
                    calc = temp1;
                } else {
                    temp2 = temp1->left;
                    temp1->left = temp2->right;
                    temp2->right = temp1;
                    calc->right = temp2->left;
                    temp2->left = calc;
                    if (temp2->balFact == -1)
                        calc->balFact = 1;
                    else
                        calc->balFact = 0;
                    if (temp2->balFact == 1)
                        temp1->balFact = -1;
                    else
                        temp1->balFact = 0;
                    calc = temp2;
                    temp2->balFact = 0;
                }
        }
        return (calc);
    }

    static Node *balLeft(Node *calc, int *h)
    {
        Node *temp1, *temp2;
        switch (calc->balFact) {
            case -1 :
                calc->balFact = 0;
                break;
            case 0 :
                calc->balFact = 1;
                *h = 0;
                break;
            case 1 :
                temp1 = calc->left;
                if (temp1->balFact >= 0) {
                    calc->left = temp1->right;
                    temp1->right = calc;
                    if (temp1->balFact == 0) {
                        calc->balFact = 1;
                        temp1->balFact = -1;
                        *h = 0;
                    } else {
                        calc->balFact = temp1->balFact = 0;
                    }
                    calc = temp1;
                } else {
                    temp2 = temp1->right;
                    temp1->right = temp2->left;
                    temp2->left = temp1;
                    calc->left = temp2->right;
                    temp2->right = calc;
                    if (temp2->balFact == 1)
                        calc->balFact = -1;
                    else
                        calc->balFact = 0;
                    if (temp2->balFact == -1)
                        temp1->balFact = 1;
                    else
                        temp1->balFact = 0;
                    calc = temp2;
                    temp2->balFact = 0;
                }
        }
        return (calc);
    }


    void display(Node *calc)
    {
        if (calc) {
            display(calc->left);
            cout << calc->data << " ";
            display(calc->right);
        }
    }

};

