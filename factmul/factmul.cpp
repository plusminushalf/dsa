#include <iostream>
#include <math.h>
using namespace std;

long long int hasrh[10000000] = {0};
long long int constent = 109546051211;

long long int prodt(long long int a, long long int b) {
    long long int l = 0;
    while (b) {
        if (b&1) {
            l = l + a;
            if (l > constent) {
                l = l - constent;
            }
        }

        a = a << 1;
        b = b >> 1;
        if (a > constent) {
            a = a -constent;
        }
    }
    return l;
}

long long int fact(int i) {
    if (i <= 1) {
        return hasrh[0];
    }
    hasrh[i] = prodt(hasrh[i-1], i);
    return hasrh[i];
}

int main() {
    // your code goes here
    long long int n;
    long long int prod = 1;
    cin >> n;
    hasrh[0] = 1;
    hasrh[1] = 1;
    if (n >= 587117) {
        cout << 0;
        return 0;
    }
    for (long long int i = 0; i <= n; ++i) {
        long long int k = fact(i);
        prod = prodt(k, prod);
    }
    cout << prod;
    return 0;

}
