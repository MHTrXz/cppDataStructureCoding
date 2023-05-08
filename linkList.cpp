#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class LinkedList {

private:
    Node *head;

public:
    LinkedList() {
        head = NULL;
    }

    int getSize();

    int get(int index);

    int searchData(int data);

    void insert(int data);

    void insertMiddle(int data, int index);

    void deleteByIndex(int index);

    void deleteByData(int data);

    string display();

    void reverse();
};

int size = 0;


void LinkedList::insert(int data) {
    Node *newNode = new Node();

    newNode->data = data;
    newNode->next = head;

    head = newNode;

    size++;
}

void LinkedList::insertMiddle(int data, int index) {
    Node *newNode = new Node();
    newNode->data = data;

    if (head == NULL) {
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        size++;
        return;
    }

    Node *temp = head;

    while (--index) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    size++;
}

int LinkedList::searchData(int data) {
    Node *search = head;
    int key = 0;
    while (search->data != data) {
        key++;
        if (key == getSize())
            break;
        search = search->next;
    }
    return key;
}

int LinkedList::get(int index) {
    if (getSize() <= index) {
        cout << "invalid index";
        return 0;
    }

    Node *search = head;
    int key = 0;
    while (key == index) {
        key++;
        search = search->next;
    }
    return search->data;
}

void LinkedList::deleteByData(int data) {
    if (getSize() <= data) {
        cout << "invalid index";
        return;
    }
    Node *pre = head;
    Node *current = pre->next;

    while (current->data != data) {
        pre = pre->next;
        current = current->next;
    }

    Node *next = current->next;
    pre->next = next;
    size --;
}

void LinkedList::deleteByIndex(int index) {
    if (getSize() < 2) {
        return;
    }

    index = getSize() - index;

    Node *pre = head;

    while (index == 1) {
        pre = pre->next;
        index--;
    }

    Node *current = pre->next;
    Node *next = current->next;
    pre->next = next;
    size --;
}

void LinkedList::reverse() {
    Node *current = head;
    Node *pre = NULL, *next = NULL;
    while (current) {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    head = pre;
}

string LinkedList::display() {
    Node *node = head;
    int index = 0;
    string output = "\n[ ";
    while (node != NULL) {
        output += to_string(index++) + " => " + to_string(node->data) + ", ";
        node = node->next;
    }
    output += " ]\n";
    return output;
}

int LinkedList::getSize() {
    return size;
}

int main() {
    int index, NodeNum, data, wwd;
    LinkedList *list = new LinkedList();

    cout << "Enter the node numbers : ";
    cin >> NodeNum;
    for (int i = 0; i <= NodeNum; i++) {
        cin >> data;
        list->insert(data);
    }
    cout << list->display();
    cout << "Enter command : ";
    cin >> wwd;
    while (wwd != 1) {
        if (wwd == 2) {
            cout << "index?  ";
            cin >> index >> data;
            list->insertMiddle(data, index);
        } else if (wwd == 3)list->display();
        else if (wwd == 4) {
            cout << "index? ";
            cin >> index;
            list->deleteByIndex(index);
            cout << list->display();
        } else if (wwd == 5) {
            list->reverse();
            cout << list->display();
        } else if (wwd == 6) {
            cout << "data? ";
            cin >> index;
            cout << list->searchData(index);
            cout << list->display();
        }
        cout << "Enter 1 for exist or Enter command : ";
        cin>>wwd;
    }

    return 0;
}