#include <iostream>
using namespace std;

void print_line(int M, int N) {
    for (int i = 0; i < M; ++i) {
        cout << " ";
    }
    for (int i = 0; i < N; ++i) {
        cout << "*";
    }
    cout << endl;
}

void print_triangle(int num_rows) {
    for (int i = 1; i <= num_rows; ++i) {
        print_line(num_rows - i, 2 * i - 1);
    }
}

int main() {
    int num_rows;
    cin >> num_rows;
    print_triangle(num_rows);
    return 0;
}
