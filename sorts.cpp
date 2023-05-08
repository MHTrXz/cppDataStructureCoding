//
// Created by MHTrXz on 1/8/2023.
//

#include <bits/stdc++.h>

using namespace std;

struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

class Sort {
public:
    static void Selection(int arr[], int length) {
        for (int i = 0; i < length; i++) {
            int index = i;
            int num = arr[i];
            for (int j = 1 + i; j < length; j++) {
                if (arr[j] > num) {
                    num = arr[j];
                    index = j;
                }
            }
            arr[index] = arr[i];
            arr[i] = num;
        }
    }

    static void Bubble(int arr[], int length) {
        int i, j, temp;
        for (i = 0; i < length - 1; i++)
            for (j = 0; j < length - i - 1; j++)
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
    }

    static void Insertion(int arr[], int length) {
        int i, j, temp;
        for (i = 1; i < length; i++) {
            temp = arr[i];
            while (j >= 0 && arr[i] > temp)
                arr[i + 1] = arr[j--];
            arr[j + 1] = temp;
        }
    }

    static void Merge(int arr[], int start, int end) {
        int mid;
        if (start < end) {
            mid = (start + end) / 2;
            Merge(arr, start, mid);
            Merge(arr, mid + 1, end);
            MergeHandler(arr, start, end, mid);
        }
    }

    static void quickSort(int arr[], int start, int end)
    {
        if (start >= end)
            return;
        int p = Partition(arr, start, end);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }

    static void inOrder(Node *head)
    {
        if (head->left != nullptr) inOrder(head->left);
        cout << head->data;
        if (head->right != nullptr) inOrder(head->right);
    }

private:
    static void MergeHandler(int arr[], int start, int end, int mid) {
        int i = start, j = mid + 1, k = 0, temp[end - start + 1];
        while (i <= mid && j <= end) {
            if (arr[i] < arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        while (j <= end) {
            temp[k++] = arr[j++];
        }
        for (i = start; i <= end; i++) {
            arr[i] = temp[i - start];
        }
    }

    static int Partition(int arr[], int start, int end)
    {
        int pivot = arr[start];
        int count = 0;
        for (int i = start + 1; i <= end; i++) {
            if (arr[i] <= pivot)
                count++;
        }
        int pivotIndex = start + count;
        swap(arr[pivotIndex], arr[start]);
        int i = start, j = end;
        while (i < pivotIndex && j > pivotIndex) {
            while (arr[i] <= pivot)
                i++;
            while (arr[j] > pivot)
                j--;
            if (i < pivotIndex && j > pivotIndex)
                swap(arr[i++], arr[j--]);
        }
        return pivotIndex;
    }

};