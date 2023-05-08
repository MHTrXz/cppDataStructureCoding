//
// Created by MHTrXz on 11/4/2022.
//

#include "iostream"

#define MAX 1000

using namespace std;

class Stack {

public:

    int top;

    string a[MAX];    //Maximum size of Stack

    Stack() {
        top = -1;
    }

    bool push(string x);

    string pop();

    bool isEmpty();

    bool isFull();
};

bool Stack::push(string x) {
    if (Stack::isFull()) {
        cout << "Stack Overflow";
        return false;
    } else {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

string Stack::pop() {
    if (Stack::isEmpty()) {
        cout << "Stack Underflow";
        return "";
    } else {
        string x = a[top--];
        return x;
    }
}

bool Stack::isEmpty() {
    return (top < 0);
}

bool Stack::isFull() {
    return (top >= (MAX - 1));
}


string changeOp(string inp, bool isPost)  // isPost = true => infix2postfix & isPost = false => infix2prefix
{
    struct Stack s;

    int key = 0;
    while (true) {
        char str = inp[key++];
        if (str == ')') {
            string a = s.pop();
            string op = s.pop();
            string b = s.pop();
            s.pop();
            if (isPost)
                s.push((op + b + a));
            else
                s.push((b + a + op));
        } else {
            string charPush;
            charPush += str;
            s.push(charPush);
        }
        if (key == inp.size())
            break;
    }
    return s.pop();
}

string change2infix(string inp, bool isPost)  // isPost = true => postfix2infix & isPost = false => prefix2infix
{
    struct Stack s;

    int key;
    if (isPost)
        key = 0;
    else
        key = inp.size() - 1;

    while (true) {
        string charPush;
        char str;
        if (isPost)
            str = inp[key++];
        else
            str = inp[key--];

        if (str != '+' & str != '-' & str != '*' & str != '/') {
            s.push(charPush + str);
        } else {
            string a = s.pop();
            string b = s.pop();
            s.push("(" + a + (charPush + str) + b + ")");
        }
        if (((key == inp.size()) & isPost) | ((key == -1) & !isPost))
            break;
    }
    return s.pop();
}

int calcChangedOp(string inp, bool isPost)  // isPost = true => postfix calc & isPost = false => prefix calc
{
    struct Stack s;

    int key;
    if (isPost)
        key = 0;
    else
        key = inp.size() - 1;

    while (true) {
        string charPush;
        int pstr;
        if (isPost)
            pstr = inp[key++];
        else
            pstr = inp[key--];
        string str;
        str += pstr;

        if (str != "+" & str != "-" & str != "*" & str != "/") {
            s.push(str);
        } else {
            int a = stoi(s.pop());
            int b = stoi(s.pop());

            if (str == "+") {
                s.push(to_string(a + b));
            } else if (str == "-") {
                s.push(to_string(a - b));
            } else if (str == "*") {
                s.push(to_string(a * b));
            } else {
                s.push(to_string(a / b));
            }
        }
        if (((key == inp.size()) & isPost) | ((key == -1) & !isPost))
            break;
    }
    return stoi(s.pop());
}

int main() {

    string inp;
    cin >> inp;

//    cout<<calcChangedOp(inp, true);
//    cout<<calcChangedOp(inp, false);

//    cout<<changeOp(inp, true);
//    cout<<changeOp(inp, false);

//    cout<<change2infix(inp, true);
//    cout<<change2infix(inp, false);

}