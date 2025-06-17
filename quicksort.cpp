#include <bits/stdc++.h>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    vector<int> sizes = {10, 50, 100, 500, 1000, 5000};
    cout << "Quick Sort - Average Execution Time (ms)\n";
    cout << "--------------------------------------\n";

    for (int size : sizes) {
        vector<int> arr;
        double totalTime = 0;

        // Random Array
        fillRandom(arr, size);
        for (int i = 0; i < 5; i++) {
            auto start = high_resolution_clock::now();
            quickSort(arr, 0, size - 1);
            auto end = high_resolution_clock::now();
            totalTime += duration<double, milli>(end - start).count();
        }
        cout << "Random (" << size << "): " << totalTime / 5 << " ms\n";

        // Sorted Array
        fillSorted(arr, size);
        totalTime = 0;
        for (int i = 0; i < 5; i++) {
            auto start = high_resolution_clock::now();
            quickSort(arr, 0, size - 1);
            auto end = high_resolution_clock::now();
            totalTime += duration<double, milli>(end - start).count();
        }
        cout << "Sorted (" << size << "): " << totalTime / 5 << " ms\n";

        // Reverse-Sorted Array
        fillReverseSorted(arr, size);
        totalTime = 0;
        for (int i = 0; i < 5; i++) {
            auto start = high_resolution_clock::now();
            quickSort(arr, 0, size - 1);
            auto end = high_resolution_clock::now();
            totalTime += duration<double, milli>(end - start).count();
        }
        cout << "Reverse-Sorted (" << size << "): " << totalTime / 5 << " ms\n";
        cout << "--------------------------------------\n";
    }

    return 0;
}