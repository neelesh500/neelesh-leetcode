#pragma GCC optimize("O2")

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();
        if (n % 2 != 0) return false;

        char st[n];
        int top = -1;

        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st[++top] = ch;
            } else {
                if (top == -1) return false;
                
                char last = st[top--];
                if ((ch == ')' && last != '(') ||
                    (ch == ']' && last != '[') ||
                    (ch == '}' && last != '{')) {
                    return false;
                }
            }
        }

        return top == -1;
    }
};