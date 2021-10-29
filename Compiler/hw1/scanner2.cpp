#include <iostream>

using namespace std;

void scanner(string);
int scanDigit(string, int);

int main() {
    string input;
    char c;

    while (cin >> c) {
        input.push_back(c);
    }

    scanner(input);

    return 0;
}

void scanner(string s) {
    int i = 0;
    while (i < s.size()) {
        char c = s.at(i);

        if (c >= '1' && c <= '9') {
            i = scanDigit(s, i);
        } else {
            switch (c) {
                case '0': {
                    printf("NUM 0\n");
                    i++;
                    break;
                }
                case '+': {
                    printf("PLUS\n");
                    i++;
                    break;
                }
                case '-': {
                    printf("MINUS\n");
                    i++;
                    break;
                }
                case '*': {
                    printf("MUL\n");
                    i++;
                    break;
                }
                case '/': {
                    printf("DIV\n");
                    i++;
                    break;
                }
                case '(': {
                    printf("LPR\n");
                    i++;
                    break;
                }
                case ')': {
                    printf("RPR\n");
                    i++;
                    break;
                }
            }
        }
    }
}

int scanDigit(string s, int i) {
    string num;
    char c = s.at(i);

    while (c <= '9' && c >= '0') {
        num.push_back(c);
        i++;
        if (i < s.size()) {
            c = s.at(i);
        } else {
            break;
        }
    }

    cout << "NUM " << num << endl;
    return i;
}