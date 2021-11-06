#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef struct Photo Photo;
struct Photo
{
    string license, status;
    int fare, time, location;
};

Photo record[1000];
int fare[24];

bool cmp(Photo a, Photo b)
{
    if (a.license != b.license)
    {
        return a.license < b.license;
    }
    return a.time < b.time;
}

Photo toPhoto(string s)
{
    istringstream sin(s);
    string s_time;
    Photo tmp;
    sin >> tmp.license;
    sin >> s_time;
    sin >> tmp.status;
    sin >> tmp.location;

    //scantime
    int t[4];
    int now_t_index = 0;
    string buffer;
    for (int i = 0; i < s_time.size(); i++)
    {
        char c = s_time.at(i);
        if (c <= '9' && c >= '0')
        {
            buffer.push_back(c);
        }
        else
        {
            t[now_t_index++] = stoi(buffer);
            buffer = "";
        }
    }
    t[3] = stoi(buffer);

    //record the time
    tmp.fare = fare[t[2]];
    tmp.time = t[1] * 24 * 60 + t[2] * 60 + t[3];
    return tmp;
}

int main()
{
    int cases;
    string buffer;
    cin >> cases;

    while (cases--)
    {
        int numRecords = 0;

        for (int i = 0; i < 24; i++)
        {
            cin >> fare[i];
        }
        cin.ignore();
        while (getline(cin, buffer))
        {
            if (buffer.size() == 0)
            {
                break;
            }

            record[numRecords] = toPhoto(buffer);
            numRecords++;
        }

        sort(record, record + numRecords, cmp);

        map<string, int> bill;
        vector<string> index;
        string license;
        bool isEnter;
        for (int i = 0; i < numRecords;)
        {
            license = record[i].license;
            isEnter = false;
            while (record[i].license == license)
            {
                if (!isEnter)
                {
                    if (record[i].status == "enter")
                    {
                        isEnter = true;
                    }
                }
                if (isEnter)
                {
                    if (record[i].status == "exit")
                    {
                        isEnter = false;
                        if (bill.find(license) == bill.end())
                        {
                            bill[license] = 200;
                            index.push_back(license);
                        }
                        bill[license] += (record[i - 1].fare * abs(record[i].location - record[i - 1].location) + 100);
                    }
                }
                i++;
                if (i >= numRecords)
                {
                    break;
                }
            }
        }

        for (int i = 0; i < index.size(); i++)
        {
            cout << index[i];
            printf(" $%d.%02d\n", bill[index[i]] / 100, bill[index[i]] % 100);
        }
        if (cases)
        {
            cout << endl;
        }
    }
    return 0;
}