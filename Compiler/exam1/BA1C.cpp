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
void error();
int match(int, string);
string peko(int);
int htmlDocument(int);
int htmlElement(int);
int htmlContent(int);
int htmlAttributeList(int);
int htmlAttribute(int);
int htmlCharData(int);
int attribute(int);

int main() {
    string input;
    getline(cin, input);
    scanner(input);
    htmlDocument(0);
    cout << "valid" << endl;
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

    Token t;
    t.type = "$";
    t.value = "$";
    tok.push_back(t);
}

int saveTok(string ty, string val, int index) {
    Token t;
    t.type = ty;
    t.value = val;
    tok.push_back(t);
    index++;
    return index;
}

void error() {
    cout << "invalid" << endl;
    exit(0);
}

int match(int index, string cmp) {
    if (tok[index].type == cmp) {
        return index + 1;
    } else {
        error();
        return -1;
    }
}

string peko(int index) {
    return tok[index].type;
}

int htmlDocument(int index) {
    if (peko(index) == "TAG_OPEN") {
        index = htmlElement(index);
        index = htmlDocument(index);
    } else if (peko(index) == "$") {
        return index;
    } else {
        error();
    }
    cout << "htmlDocument" << endl;
    return index;
}
int htmlElement(int index) {
    index = match(index, "TAG_OPEN");
    index = match(index, "TAG_NAME");
    index = htmlAttributeList(index);
    index = match(index, "TAG_CLOSE");
    index = htmlContent(index);
    index = match(index, "TAG_OPEN_SLASH");
    index = match(index, "TAG_NAME");
    index = match(index, "TAG_CLOSE");
    cout << "htmlElement" << endl;
    return index;
}
int htmlContent(int index) {
    if (peko(index) == "HTML_TEXT") {
        index = htmlCharData(index);
        index = htmlContent(index);
    } else if (peko(index) == "TAG_OPEN") {
        index = htmlElement(index);
        index = htmlContent(index);
    } else {
        return index;
    }
    cout << "htmlContent" << endl;
    return index;
}
int htmlAttributeList(int index) {
    if (peko(index) == "TAG_NAME") {
        index = htmlAttribute(index);
        index = htmlAttributeList(index);
    } else {
        return index;
    }
    cout << "htmlAttributeList" << endl;
    return index;
}
int htmlAttribute(int index) {
    index = match(index, "TAG_NAME");
    index = match(index, "TAG_EQUALS");
    index = attribute(index);
    cout << "htmlAttribute" << endl;
    return index;
}

int htmlCharData(int index) {
    index = match(index, "HTML_TEXT");
    cout << "htmlCharData" << endl;
    return index;
}

int attribute(int index) {
    if (peko(index) == "DOUBLE_QUOTE_STRING") {
        index = match(index, "DOUBLE_QUOTE_STRING");
    } else if (peko(index) == "SINGLE_QUOTE_STRING") {
        index = match(index, "SINGLE_QUOTE_STRING");
    } else {
        error();
    }
    cout << "attribute" << endl;
    return index;
}