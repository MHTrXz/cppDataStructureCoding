//
// Created by MHTrXz on 11/16/2022.
//

#include <iostream>

#define SIZE 500

using namespace std;

class Que {

private:

    int list[2][SIZE]{};

    int front;

    int rear;

public:

    Que() {
        front = 0;
        rear = 0;
    }

    bool isEmpty() {
        if (rear == front) {
            return true;
        } else {
            return false;
        }
    }

    bool isFull() {
        if (rear == SIZE) {
            return true;
        } else {
            return false;
        }
    }

    int getElement(int index) {
        for (int i = front; i < rear; ++i) {
            if (list[0][i] == index) {
                return list[1][i];
            }
        }
        return 0;
    }


    void addElement(int v, int p) {
        if (isFull()) {
            cout << "Que overflow!";
        } else {
            list[0][rear] = p;
            list[1][rear++] = v;
        }
    }

    void insertElement(int v, int p) {
        for (int i = front; i < rear; ++i) {
            if (list[0][i] == p) {
                list[1][i] += v;
                return;
            }
        }
        addElement(v, p);
    }

    int *deleteElement() {
        static int out[2];
        out[0] = list[0][front];
        out[1] = list[1][front++];
        return out;
    }

    void echo() {
        string out;
        for (int i = front; i < rear; ++i) {
            out += to_string(list[1][i]) + "x^" + to_string(list[0][i]) + " + ";
        }
        cout << out << endl;
    }

    int mohasebe(int x) {
        int out = 0;
        int *a;
        while (!isEmpty()) {
            a = deleteElement();
            int calc = 1;
            for (int i = 0; i < a[0]; ++i) {
                calc *= x;
            }
            out += calc * a[1];
        }
        return out;
    }

    void jam(Que que) {
        for (int i = que.front; i < que.rear; ++i) {
            insertElement(que.list[1][i], que.list[0][i]);
        }
    }

    void tafriq(Que que) {
        bool status;
        for (int i = que.front; i < que.rear; ++i) {
            status = true;
            for (int j = front; j < rear; ++j) {
                if (que.list[0][i] == list[0][j]) {
                    list[1][j] -= que.list[1][i];
                    status = false;
                    break;
                }
            }
            if (status) {
                addElement(-que.list[1][i], que.list[0][i]);
            }
        }
    }

    void zarb(Que que) {
        struct Que test;
        for (int j = front; j < rear; ++j) {
            for (int i = que.front; i < que.rear; ++i) {
                test.insertElement(que.list[1][i] * list[1][j], que.list[0][i] + list[0][j]);
            }
            deleteElement();
        }
        while (!test.isEmpty()) {
            int *testP = test.deleteElement();
            addElement(testP[1], testP[0]);
        }
    }
};


int main() {
    Que test1 = *new Que();
    test1.insertElement(2, 5);
    test1.insertElement(2, 4);
    test1.insertElement(2, 3);
    test1.insertElement(7, 2);
    test1.insertElement(1, 0);

    Que test2 = *new Que();
    test2.insertElement(4, 6);
    test2.insertElement(4, 5);
    test2.insertElement(2, 3);
    test2.insertElement(5, 0);



    cout<<test1.getElement(4)<<endl;
    cout<<test1.mohasebe(5);
    test1.jam(test2);
    test1.tafriq(test2);
    test1.zarb(test2);

    test1.echo();
    test2.echo();
}