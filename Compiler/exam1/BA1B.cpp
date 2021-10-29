#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct Token Token;
struct Token {
    string type;
    string value;
};
vector<Token> tok;

void scanner(string);
int saveTok(string, string, int);
string scanStr(string, int);

int main() {
    string input;
    getline(cin, input);
    scanner(input);
    for (int i = 0; i < tok.size(); i++) {
        cout << tok.at(i).type << ' ' << tok.at(i).value << endl;
    }
    return 0;
}

void scanner(string s) {
    int i = 0;
    bool TagMode = false;
    while (i < s.size()) {
        char c = s.at(i);

        if (c == '<') {
            i++;
            c = s.at(i);
            if (c == '/') {
                i = saveTok("TAG_OPEN_SLASH", "</", i);
            } else {
                saveTok("TAG_OPEN", "<", i);
            }
            TagMode = true;
        } else if (c == '>') {
            i = saveTok("TAG_CLOSE", ">", i);
            TagMode = false;
        } else if (c == '=') {
            i = saveTok("TAG_EQUALS", "=", i);
        } else if (c == '\'' && TagMode) {
            i++;
            string val;
            c = s.at(i);
            while (c != '\'') {
                val.push_back(c);
                i++;
                c = s.at(i);
            }
            i = saveTok("SINGLE_QUOTE_STRING", val, i);
        } else if (c == '\"' && TagMode) {
            i++;
            string val;
            c = s.at(i);
            while (c != '\"') {
                val.push_back(c);
                i++;
                c = s.at(i);
            }
            i = saveTok("DOUBLE_QUOTE_STRING", val, i);
        } else if (c == ' ') {
            i++;
            continue;
        } else if (TagMode) {
            string val;
            while (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9') {
                val.push_back(c);
                i++;
                c = s.at(i);
            }
            saveTok("TAG_NAME", val, i);
        } else {
            string val;
            while (c != '<') {
                val.push_back(c);
                i++;
                c = s.at(i);
            }
            saveTok("HTML_TEXT", val, i);
        }
    }
}

int saveTok(string ty, string val, int index) {
    Token t;
    t.type = ty;
    t.value = val;
    tok.push_back(t);
    index++;
    return index;
}
