#include <iostream>
using namespace std;

const int MAX = 10000001;

int primeCount[MAX];

int main() {

    
    for (int i = 2; i < MAX; i++) 
	{
        if (primeCount[i] == 0) 
		{ 
            for (int j = i; j < MAX; j += i) 
			{
                primeCount[j]++;
            }
        }
    }

    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);

        int k = primeCount[n];

        int ans = 1;
        for (int i = 0; i < k; i++) 
		{
            ans = ans * 2;
        }

        printf("%d\n", ans);
    }

    return 0;
}
