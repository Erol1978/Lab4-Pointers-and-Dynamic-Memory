#include <iostream>
using namespace std;

void findMinAndMax(const int arr[], int size, int* minVal, int* maxVal) {
    for (int i = 1; i < size; i++) {
        if (arr[i] < *minVal) *minVal = arr[i];
        if (arr[i] > *maxVal) *maxVal = arr[i];
    }
}

int main() {
    int numbers[] = {23, 5, 67, -2, 45, 87, 1, 99, 34, -10};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int minVal = numbers[0];
    int maxVal = numbers[0];

    findMinAndMax(numbers, size, &minVal, &maxVal);

    cout << "The minimum value is: " << minVal << endl;
    cout << "The maximum value is: " << maxVal << endl;

    return 0;
}
