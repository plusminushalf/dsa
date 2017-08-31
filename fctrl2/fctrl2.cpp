#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/*
 * Question:
 *
 * You are asked to calculate factorials of some small positive integers.
 *
 * Input:
 * An integer t, 1<=t<=100, denoting the number of testcases, followed by t lines, each containing a single integer n, 1<=n<=100.
 *
 * Output:
 * For each integer n given at input, display a line with the value of n!
 *
 * Example:
 *
 * Sample input:
 * 4
 * 1
 * 2
 * 5
 * 3
 *
 * Sample output:
 * 1
 * 2
 * 120
 * 6
 */

/*
 * function to print vector in reverse order
 * beacuse numeber 123 is save as 321 in vector form
 * this is due to the fact that it is easy to multiplication and summation
 */
void printVector(vector<int> v) {
    vector<int>::reverse_iterator it;
    for(it = v.rbegin(); it != v.rend(); ++it) {
        cout << *it;
    }
}

/*
 * function to multiply a vector representation of a number a with a unit digit i
 * Logic:
 *  11  (carry layer)
 *  958
 *   *2
 *  ---
 * 1918
 */
vector<int> multiply(vector<int> v, int i) {
    vector<int>::iterator it;
    vector<int> r;
    int carry = 0, num = 0;
    for(it = v.begin(); it != v.end(); ++it) {
        num = (*it * i) + carry;
        carry = num / 10;
        num = num % 10;
        r.push_back(num);
    }
    if (carry) {
        r.push_back(carry);
    }
    return r;
}

/*
 * function to add to vector representation of numbers
 */
vector<int> sum(vector<int> a, vector<int> b) {
    vector<int> s;
    vector<int>::iterator ia, ib;
    ia = a.begin();
    ib = b.begin();
    int carry = 0, temp = 0;
    while(ia != a.end() && ib != b.end()) {
        temp = *ia + *ib + carry;
        s.push_back(temp%10);
        carry = temp/10;
        ia++;
        ib++;
    }
    while(ia != a.end()) {
        temp = *ia + carry;
        s.push_back(temp%10);
        carry = temp/10;
        ia++;
    }
    while(ib != b.end()) {
        temp = *ib + carry;
        s.push_back(temp%10);
        carry = temp/10;
        ib++;
    }
    if (carry) {
        s.push_back(carry);
    }
    return s;
}

/*
 * function to multiply vector implementation of a number with another number which is not in vector representation
 * logic:
 *   234
 *   *23
 *   ---
 *   702
 * +4680
 * -----
 *  5382
 *
 * I have broken 234*3 part in another function multiply to makes things easier
 *
 */
vector<int> multiplyNum(vector<int> v, int num) {
    vector<int> res, temp;
    int k = 0;
    while(num) {
        temp = multiply(v, num%10);
        for (int i = 0; i < k; ++i) {
            temp.insert(temp.begin(), 0);
        }
        k++;
        num = num/10;
        res = sum(res, temp);
    }
    return res;
}

int main() {
    // your code goes here
    int t, n;
    // take number of test cases as inout
    cin >> t;
    // repeat the loop for all the test cases
    while(t--) {
        // take the number input
        cin >> n;
        // vector representation of factorial will be saved in this variable
        vector<int> fact;
        // we make the value of factorial as 1 by default
        fact.push_back(1);
        for(int i = 2; i <= n; ++i) {
            // calculating fact as fact(i-1)*i
            fact = multiplyNum(fact, i);
        }
        // printing vector
        printVector(fact);
        cout << "\n";
    }
}
