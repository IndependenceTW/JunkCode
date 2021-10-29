#include <iostream>

using namespace std;

void s1(string, int);
void s2(string, int);
void s3(string, int);
void s4(string, int);
void error();

int main()
{
    string s;
    cin >> s;
    s1(s, 0);

    return 0;
}

void s1(string s, int i)
{
    char c = s.at(i);
    switch (c)
    {
    case 'a':
        s2(s, i + 1);
        break;

    case 'b':
        s3(s, i + 1);
        break;

    default:
        error();
        break;
    }
}

void s2(string s, int i)
{
    char c = s.at(i);

    while (c == 'a')
    {
        i++;
        c = s.at(i);
    }

    if (c == 'b')
    {
        s4(s, i + 1);
    }
    else
    {
        error();
    }
}

void s3(string s, int i)
{
    char c = s.at(i);

    while (c == 'a')
    {
        i++;
        c = s.at(i);
    }

    if (c == 'c')
    {
        s4(s, i + 1);
    }
    else if (c == '$')
    {
        cout << "YES s3" << endl;
    }
    else
    {
        error();
    }
}

void s4(string s, int i)
{
    char c = s.at(i);
    if (c == '$')
    {
        cout << "YES s4" << endl;
    }
    else
    {
        error();
    }
}

void error()
{
    cout << "NO" << endl;
    exit(0);
}