#include <iostream>
#include <string>

using namespace std;

int main()
{
    int counter[26][2];
    string input;

    while (getline(cin, input))
    {
        for (int i = 0; i < 26; i++)
        {
            counter[i][0] = 0;
            counter[i][1] = 0;
        }

        for (int i = 0; i < input.size(); i++)
        {
            char c = input.at(i);
            int index = (int)(c - 'a');
            counter[index][0]++;
        }
        getline(cin, input);
        for (int i = 0; i < input.size(); i++)
        {
            char c = input.at(i);
            int index = (int)(c - 'a');
            counter[index][1]++;
        }

        for (int i = 0; i < 26; i++)
        {
            char c = i + 'a';
            for (int j = 0; j < min(counter[i][0], counter[i][1]); j++)
            {
                cout << c;
            }
        }
        cout << endl;
    }
    return 0;
}