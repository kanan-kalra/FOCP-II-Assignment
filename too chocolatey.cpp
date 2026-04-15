#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    int T;
    cin >> T;

    while (T--) 
    {
        int N;
        cin >> N;

        vector<int> a(N);

        for (int i = 0; i < N; i++) 
        {
            cin >> a[i];
        }

        // Sort in decreasing order
        sort(a.begin(), a.end(), greater<int>());

        long long alex = 0, bob = 0;
        bool alexTurn = true;

        int i = 0;

        while (i < N) 
        {
            int value = a[i];
            int count = 0;

            // Count same values
            while (i < N && a[i] == value) 
            {
                count++;
                i++;
            }

            // A value can be taken maximum 2 times
            int take = min(count, 2);

            for (int j = 0; j < take; j++) 
            {
                if (alexTurn)
                    alex += value;
                else
                    bob += value;

                alexTurn = !alexTurn;
            }
        }

        if (alex > bob)
            cout << "Alex" << endl;
        else
            cout << "Bob" << endl;
    }

    return 0;
}
