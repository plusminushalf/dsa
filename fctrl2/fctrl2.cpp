#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void printVector(vector<int> v) {
    vector<int>::reverse_iterator it;
    for(it = v.rbegin(); it != v.rend(); ++it) {
        cout << *it;
    }
}

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
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> fact;
        fact.push_back(1);
        for(int i = 2; i <= n; ++i) {
            fact = multiplyNum(fact, i);
        }
        printVector(fact);
        cout << "\n";
    }
}
