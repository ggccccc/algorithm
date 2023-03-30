//
// Created by Administrator on 2023/3/20.
//
#include<vector>
#include<random>
#include<algorithm>
#include<iostream>

using namespace std;

class BubbleSort {
public:

    static void bubbleSort(vector<int> &arr) {
        if (arr.empty() || arr.size() < 2) {
            return;
        }
        for (int i = arr.size() - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr, j, j + 1);
                }
            }
        }
    }

    static void swap(vector<int> &arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    static void generateRandomArray(vector<int> &arr, int maxSize, int maxValue) {
        arr.resize(rand() % maxSize);
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = rand() % maxValue;
        }
    }

    static bool isEqual(const vector<int> &arr1, const vector<int> &arr2) {
        for (int i = 0; i < arr1.size(); i++) {
            if (arr1[i] != arr2[i]) {
                return false;
            }
        }
        return true;
    }

    static void comparator(vector<int> &arr) {
        sort(arr.begin(), arr.end());
    }
};

int main() {
    int testTime = 50;
    int maxSize = 100;
    int maxValue = 10000;
    bool success = true;
    for (int i = 0; i < testTime; i++) {
        vector<int> arr1;
        BubbleSort::generateRandomArray(arr1, maxSize, maxValue);
        vector<int> arr2 = arr1;
        BubbleSort::bubbleSort(arr1);
        BubbleSort::comparator(arr2);
        if (!BubbleSort::isEqual(arr1, arr2)) {
            success = false;
            break;
        }
    }
    if (success) {
        cout << "That's good" << endl;
    } else {
        cout << "Why???" << endl;
    }
}