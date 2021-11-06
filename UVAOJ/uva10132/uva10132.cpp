#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(string a, string b)
{
    return a.size() < b.size();
}

int main()
{
    int cases;
    cin >> cases;
    cin.ignore();
    cin.ignore();

    while (cases--)
    {
        string input;
        vector<string> files;
        vector<string> keys;
        map<string, int> appearTimes;
        int actualSize;

        while (getline(cin, input))
        {
            if (input.size() == 0)
            {
                break;
            }
            files.push_back(input);
        }

        sort(files.begin(), files.end(), cmp);
        actualSize = files.at(0).size() + files.at(files.size() - 1).size();

        // find appear the most time array
        for (int i = 0; i < files.size(); i++)
        {
            for (int j = 0; j < files.size(); j++)
            {
                if (i != j && files.at(i).size() + files.at(j).size() == actualSize)
                {
                    string result = files.at(i) + files.at(j);
                    if (appearTimes.find(result) == appearTimes.end())
                    {
                        keys.push_back(result);
                        appearTimes[result] = 0;
                    }
                    appearTimes[result]++;
                }
            }
        }

        string max = keys[0];
        for (int i = 1; i < keys.size(); i++)
        {
            string cmp = keys[i];
            if (appearTimes[max] < appearTimes[cmp])
            {
                max = cmp;
            }
        }

        cout << max << endl;

        if (cases)
        {
            cout << endl;
        }
    }
    return 0;
}