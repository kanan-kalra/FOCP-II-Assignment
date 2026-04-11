#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    for (int l = 1; l <= n; l++) {
        int count = 0;

        for (int i = 0; i < n; ) {
            if (s[i] == '1') {
                count++;
                i = i + l;   
            } else {
                i++;     
            }
        }

        if (count <= k) {
            cout << l;
            break;
        }
    }

    return 0;
}
