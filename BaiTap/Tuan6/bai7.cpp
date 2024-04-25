#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int random() {
    return rand() % 50;
}
void in(int a[], int N) {
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                int sum = a[i] + a[j] + a[k];
                if (sum % 25 == 0) {
                    cout << a[i] << " " << a[j] << " " << a[k] << endl;
                }
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    int a[N];
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        a[i] = random();
    }
    in(a, N);
    return 0;
}

