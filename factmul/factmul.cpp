#include <iostream>
#include <math.h>
using namespace std;


/*
 * Question:
 *
 * You need to find the product of first n factorials 1! * 2! * ... * n! modulo 109546051211.
 *
 * Input:
 * One integer n (1 <= n <= 10000000)
 * Output:
 * The answer.
 *
 * Example:
 * Input:
 * 5
 * Output:
 * 34560
 */

// fact has is used to store factorial of anumber % 109546051211
long long int fact_hash[10000000] = {0};

// constant which hich module will be taken
const long long int MODULO = 109546051211;

/*
 * function to calculate product of two large number modulo 109546051211
 * Logic: we have to get c = a*b
 * c = (a*2)*(b/2)
 * if b is orr then it splits as
 * c = a + a*2*b/2 (where b is not even)
 * hence c can be written as
 * c = a + d*f
 * not we can again go recusrively for d*f
 * now to do a*2 and b/2 we use bit shifting operators
 * a*2 == a << 1
 * b/2 == b >> 1
 *
 * we are taking modulo at every step, this is because of these two properties:
 * (a*b) % c === (a%c)*(b%c)
 * also,
 * (a + b) % c === (a%c) + (b%c)
 */
long long int product(long long int a, long long int b) {
    long long int l = 0;
    while (b) {
        // check if b is odd
        if (b&1) {
            // add a if b is odd
            l = l + a;
            // to prevent overflow we keep on taking modulo at every addition
            if (l > MODULO) {
                l = l - MODULO;
            }
        }

        // multiply a into 2
        a = a << 1;
        // divide a by 2
        b = b >> 1;

        // since we multiplied a with 2. we take it's modulo to prevent from overflow
        if (a > MODULO) {
            a = a - MODULO;
        }
    }
    return l;
}

/*
 * function to calculate factorial of a number, it assumes that yoou are calling this function incrementally
 * since it relias of fact(i-1) to be pre calculated and saved in the global variable fact_hash
 */
long long int fact(int i) {
    if (i <= 1) {
        return fact_hash[0];
    }
    fact_hash[i] = product(fact_hash[i-1], i);
    return fact_hash[i];
}

int main() {
    // your code goes here

    // input n
    long long int n;
    // final product % 109546051211
    long long int prod = 1;
    // take the input
    cin >> n;
    // initialise factorial of zero and one as 1
    // since function fact(i) assumes fact(i-1) pre-calculated
    fact_hash[0] = 1;
    fact_hash[1] = 1;
    // this magic number comes by calculating where the modulo becomes 0 for the first time
    // since once module is zero modulo for all the numbers after that will be zero
    if (n >= 587117) {
        cout << 0;
        return 0;
    }

    // let's run our loop and get the work done :D
    for (long long int i = 0; i <= n; ++i) {
        long long int k = fact(i);
        prod = product(k, prod);
    }
    cout << prod;
    return 0;

}
