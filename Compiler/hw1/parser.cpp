#include <iostream>
#include <vector>

using namespace std;

typedef struct Token Token;
struct Token {
    string type;
    string value;
};
vector<Token> tok;

int scanID(string s, unsigned int i);
bool scanner(string s);
int match(int, string);
string peko(int);
int primary_tail(int);
int stmt(int);
int stmts(int);
int primary(int);
bool program();

int main() {
    string s;
    char tmp;
    while (cin >> tmp) {
        s.push_back(tmp);
    }

    if (!scanner(s)) {
        printf("invalid input\n");
    } else {
        if (program()) {
            for (unsigned int i = 0; i < tok.size() - 1; i++) {
                cout << tok[i].type << ' ' << tok[i].value << endl;
            }
        } else {
            printf("invalid input\n");
        }
    }

    return 0;
}

int scanID(string s, unsigned int i) {
    string tmp;
    char c = s.at(i);
    Token t;
    t.type = "ID";

    while ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a') ||
           (c <= '9' && c >= '0') || (c == '_')) {
        tmp.push_back(c);
        i++;
        if (i < s.size()) {
            c = s.at(i);
        } else {
            break;
        }
    }
    t.value = tmp;
    tok.push_back(t);

    return i;
}

bool scanner(string s) {
    unsigned int i = 0;
    while (i < s.size()) {
        char c = s.at(i);
        if ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a') || (c == '_')) {
            i = scanID(s, i);
        } else {
            switch (c) {
                case '\"': {
                    Token t;
                    string val;
                    t.type = "STRLIT";
                    val.push_back('\"');
                    i++;
                    c = s.at(i);
                    while (c != '\"') {
                        val.push_back(c);
                        i++;
                        if (i >= s.size()) {
                            return false;
                        }
                        c = s.at(i);
                    }
                    val.push_back('\"');
                    t.value = val;
                    tok.push_back(t);
                    i++;
                    break;
                }
                case '(': {
                    Token t;
                    t.type = "LBR";
                    t.value = "(";
                    tok.push_back(t);
                    i++;
                    break;
                }
                case ')': {
                    Token t;
                    t.type = "RBR";
                    t.value = ")";
                    tok.push_back(t);
                    i++;
                    break;
                }
                case '.': {
                    Token t;
                    t.type = "DOT";
                    t.value = ".";
                    tok.push_back(t);
                    i++;
                    break;
                }
                default:
                    return false;
            }
        }
    }
    Token end;
    end.type = "$";
    end.value = "$";

    tok.push_back(end);
    return true;
}

int match(int index, string cmp) {
    if (index == -1) {
        return -1;
    } else if (tok[index].type == cmp) {
        return index + 1;
    } else {
        return -1;
    }
}

string peko(int index) {
    return tok[index].type;
}

int primary_tail(int index) {
    if (index == -1) return -1;

    string s = peko(index);
    if (s == "DOT") {
        index = match(index, "DOT");
        index = match(index, "ID");
        index = primary_tail(index);
    } else if (s == "LBR") {
        index = match(index, "LBR");
        index = stmt(index);
        index = match(index, "RBR");
        index = primary_tail(index);
    } else {
    }

    return index;
}

int primary(int index) {
    if (index == -1) return -1;

    index = match(index, "ID");
    index = primary_tail(index);

    return index;
}

int stmt(int index) {
    if (index == -1) return -1;

    string s = peko(index);

    if (s == "STRLIT") {
        index = match(index, "STRLIT");
    } else if (s == "ID") {
        index = primary(index);
    } else if (s == "RBR") {
    } else {
        index = -1;
    }

    return index;
}

int stmts(int index) {
    if (index == -1) return -1;

    string s = peko(index);

    if (s == "STRLIT" || s == "ID") {
        index = stmt(index);
        index = stmts(index);
    } else if (s == "$") {
    } else {
        index = -1;
    }

    return index;
}

bool program() {
    int index = 0;
    int sol;

    sol = stmts(index);

    if (sol != -1) {
        return true;
    } else {
        return false;
    }
}