#include <bits/stdc++.h>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void fillRandom(vector<int>& arr, int size) {
    arr.resize(size);
    for (int i = 0; i < size; i++) arr[i] = rand() % 1000;
}

void fillSorted(vector<int>& arr, int size) {
    arr.resize(size);
    for (int i = 0; i < size; i++) arr[i] = i + 1;
}

void fillReverseSorted(vector<int>& arr, int size) {
    arr.resize(size);
    for (int i = 0; i < size; i++) arr[i] = size - i;
}

int main() {
    srand(time(0));
    vector<int> sizes = {10, 50, 100, 500, 1000, 5000,10000};
    cout << "Bubble Sort - Average Execution Time (ms)\n";
    cout << "----------------------------------------\n";

    for (int size : sizes) {
        vector<int> arr;
        double totalTime = 0;

        // Random Array
        fillRandom(arr, size);
        for (int i = 0; i < 5; i++) {
            auto start = high_resolution_clock::now();
            bubbleSort(arr);
            auto end = high_resolution_clock::now();
            totalTime += duration<double, milli>(end - start).count();
        }
        cout << "Random (" << size << "): " << totalTime / 5 << " ms\n";

        // Sorted Array
        fillSorted(arr, size);
        totalTime = 0;
        for (int i = 0; i < 5; i++) {
            auto start = high_resolution_clock::now();
            bubbleSort(arr);
            auto end = high_resolution_clock::now();
            totalTime += duration<double, milli>(end - start).count();
        }
        cout << "Sorted (" << size << "): " << totalTime / 5 << " ms\n";

        // Reverse-Sorted Array
        fillReverseSorted(arr, size);
        totalTime = 0;
        for (int i = 0; i < 5; i++) {
            auto start = high_resolution_clock::now();
            bubbleSort(arr);
            auto end = high_resolution_clock::now();
            totalTime += duration<double, milli>(end - start).count();
        }
        cout << "Reverse-Sorted (" << size << "): " << totalTime / 5 << " ms\n";
        cout << "----------------------------------------\n";
    }

    return 0;
}