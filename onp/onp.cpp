#include <iostream>
#include <stack>
using namespace std;

bool isOperand(char c) {
    if (c != '('
            && c != ')'
            && c != '+'
            && c != '-'
            && c != '*'
            && c != '/'
            && c != '^'
       ) {
        return true;
    }
    return false;
}

int getPriority(char a) {
    if (a == '+') {
        return 1;
    }
    if (a == '-') {
        return 2;
    }
    if (a == '*') {
        return 3;
    }
    if (a == '/') {
        return 4;
    }
    if (a == '^') {
        return 5;
    }
    return 7;
}

void printStack(stack<char> a) {
    while(!a.empty()) {
        cout << a.top();
        a.pop();
    }
}

void rpn(char *s) {
    stack<char> operations;
    for (int i =0; s[i] != '\0'; ++i) {
        if (isOperand(s[i])) {
            cout << s[i];
        } else {
            if (s[i] == '(') {
                operations.push(s[i]);
            } else if (s[i] == ')') {
                while (operations.top() != '(') {
                    cout << operations.top();
                    operations.pop();
                }
                operations.pop();
            } else {
                while (!operations.empty()
                        && operations.top() != '('
                        && getPriority(operations.top()) > getPriority(s[i])
                      ) {
                    cout << operations.top();
                    operations.pop();
                }
                operations.push(s[i]);
            }
        }
    }
    while (!operations.empty()) {
        cout << operations.top();
        operations.pop();
    }
}

int main() {
    // your code goes here
    int t;
    char s[400];
    cin >> t;
    while(t--) {
        cin >> s;
        rpn(s);
        cout << endl;
    }
    return 0;
}
