#include <iostream>

using namespace std;


int main(){
    int daytab[2][12] = {
  {31,28,31,30,31,30,31,31,30,31,30,31},
  {31,29,31,30,31,30,31,31,30,31,30,31}
};
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 12; j++){
            cout << daytab[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

