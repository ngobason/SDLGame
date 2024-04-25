#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int random_less_than_N(int N) {
    srand(time(NULL));
    return rand() % N;
}

int main() {
    int N;
    cin >> N;
    cout << random_less_than_N(N);
    return 0;
}
