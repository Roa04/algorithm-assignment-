#include <bits/stdc++.h>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
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
    vector<int> sizes = {10, 50, 100, 500, 1000, 5000, 10000,50000,100000};
    cout << "Merge Sort - Average Execution Time (ms)\n";
    cout << "---------------------------------------\n";

    for (int size : sizes) {
        vector<int> arr;
        double totalTime = 0;

        // Random Array
        fillRandom(arr, size);
        for (int i = 0; i < 5; i++) {
            auto start = high_resolution_clock::now();
            mergeSort(arr, 0, size - 1);
            auto end = high_resolution_clock::now();
            totalTime += duration<double, milli>(end - start).count();
        }
        cout << "Random (" << size << "): " << totalTime / 5 << " ms\n";

        // Sorted Array
        fillSorted(arr, size);
        totalTime = 0;
        for (int i = 0; i < 5; i++) {
            auto start = high_resolution_clock::now();
            mergeSort(arr, 0, size - 1);
            auto end = high_resolution_clock::now();
            totalTime += duration<double, milli>(end - start).count();
        }
        cout << "Sorted (" << size << "): " << totalTime / 5 << " ms\n";

        // Reverse-Sorted Array
        fillReverseSorted(arr, size);
        totalTime = 0;
        for (int i = 0; i < 5; i++) {
            auto start = high_resolution_clock::now();
            mergeSort(arr, 0, size - 1);
            auto end = high_resolution_clock::now();
            totalTime += duration<double, milli>(end - start).count();
        }
        cout << "Reverse-Sorted (" << size << "): " << totalTime / 5 << " ms\n";
        cout << "---------------------------------------\n";
    }

    return 0;
}