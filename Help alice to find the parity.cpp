#include <iostream>
using namespace std;

int main() {
    int L, R;
    cin >> L >> R;

    int X = 0;

    for (int i = L; i <= R; i++) {
        X = X ^ i;
    }

    if (X % 2 == 0)
        cout << "even";
    else
        cout << "odd";

    return 0;
}
