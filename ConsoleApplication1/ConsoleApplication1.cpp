#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        a[i] = min + rand() % (max - min + 1);
    }
}

void Print(int* a, int size) {
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << setw(4) << a[i];
    }
    cout << endl;
}

void Task1_1(int* a, int size, int& n) {
    int minAbs = abs(a[0]);
    for (int i = 0; i < size; i++) {
        if (abs(a[i + 1]) < minAbs) {
            minAbs = abs(a[i + 1]);
            n = i + 1;
        }
    }
}

void Task1_2(int* a, int size, int& sum) {
    sum = 0;
    int n = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] < 0) {
            n = i;
            break;
        }
    }
    for (int i = n; i < size; i++) {
        sum += abs(a[i]);
    }
}

void Task1_3(int* a, int size) {
    int ld, rd;
    cout << "enter min value of interval: "; cin >> ld;
    cout << "enter max value of interval: "; cin >> rd;
    int n = 0;
    for (int i = 0; i < size - n; i++) {
        if (ld <= a[i] && a[i] <= rd) {
            for (int j = i; j < size - 1; j++) {
                a[j] = a[j + 1];
            }
            i--;
            n++;
        }
    }
    for (int i = size - n; i < size; i++) {
        a[i] = 0;
    }
}

int main() {
    srand((unsigned)time(NULL));

    int size;
    cout << "size = "; cin >> size;
    int min = -10; int max = 10;
    int a[size];
    int n = 0;
    int sum = 0;

    Create(a, size, min, max);
    Print(a, size);
    Task1_1(a, size, n);
    cout << "index minimal Abs = " << n << endl;
    Task1_2(a, size, sum);
    cout << "sum from the first negative = " << sum << endl;
    Task1_3(a, size);
    Print(a, size);
    return 0;
}