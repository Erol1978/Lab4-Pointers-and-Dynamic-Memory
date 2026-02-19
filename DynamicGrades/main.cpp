#include <iostream>
#include <iomanip>
using namespace std;

void getScores(double* arr, int size) {
    for (int i = 0; i < size; i++) {
        double x;
        while (true) {
            cout << "Enter score " << (i + 1) << ": ";
            cin >> x;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Try again.\n";
                continue;
            }

            if (x < 0) {
                cout << "Score cannot be negative. Try again.\n";
                continue;
            }

            arr[i] = x;
            break;
        }
    }
}

void sortScores(double* arr, int size) {
    for (int pass = 0; pass < size - 1; pass++) {
        for (int i = 0; i < size - 1 - pass; i++) {
            if (arr[i] > arr[i + 1]) {
                double temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

double calculateAverage(const double* arr, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) sum += arr[i];
    return sum / size;
}

int main() {
    int n;
    cout << "How many test scores would you like to enter? ";
    cin >> n;

    if (cin.fail() || n <= 0) {
        cout << "Error: size must be a positive number.\n";
        return 0;
    }

    double* scores = new double[n];

    getScores(scores, n);
    sortScores(scores, n);
    double avg = calculateAverage(scores, n);

    cout << fixed << setprecision(2);
    cout << "\nThe sorted scores are: ";
    for (int i = 0; i < n; i++) cout << scores[i] << " ";
    cout << "\nThe average score is: " << avg << endl;

    delete[] scores;
    scores = nullptr;

    return 0;
}
