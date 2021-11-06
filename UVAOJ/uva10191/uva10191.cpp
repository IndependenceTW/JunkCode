#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int onTime = 600;

class TimeBlock
{
public:
    TimeBlock(int startH, int startM, int endH, int endM)
    {
        start_time = startH * 60 + startM - onTime;
        end_time = endH * 60 + endM - onTime;
    }
    friend bool cmp(TimeBlock *a, TimeBlock *b);
    int operator-(TimeBlock other)
    {
        return other.start_time - end_time;
    }
    int getEnd()
    {
        return end_time;
    }

private:
    int start_time;
    int end_time;
};
TimeBlock *tb[101];

bool cmp(TimeBlock *a, TimeBlock *b)
{
    if (a->start_time != b->start_time)
    {
        return a->start_time < b->start_time;
    }
    else
    {
        return a->end_time < b->end_time;
    }
}

int main()
{
    int n;
    int days = 1;
    TimeBlock first(10, 0, 10, 0);
    TimeBlock last(18, 0, 18, 0);
    while (cin >> n)
    {
        string app;
        int time[4];
        int longest = 0;
        int longestIndex;
        for (int i = 0; i < n; i++)
        {
            scanf("%d:%d %d:%d", time, time + 1, time + 2, time + 3);
            getline(cin, app);
            tb[i] = new TimeBlock(time[0], time[1], time[2], time[3]);
        }
        sort(tb, tb + n, cmp);

        //begin case
        longest = first - *(tb[0]);
        longestIndex = -1;

        for (int i = 0; i < n - 1; i++)
        {
            int nap = *(tb[i]) - *(tb[i + 1]);
            if (nap > longest)
            {
                longest = nap;
                longestIndex = i;
            }
        }

        //end case
        {
            int nap = *(tb[n - 1]) - last;
            if (nap > longest)
            {
                longest = nap;
                longestIndex = n - 1;
            }
        }

        if (longestIndex == -1)
        {
            printf("Day #%d: the longest nap starts at 10:00 and will last for ", days);
            if (longest / 60 != 0)
            {
                printf("%d hours and ", longest / 60);
                longest %= 60;
            }
            printf("%d minutes.\n", longest);
        }
        else
        {
            int time = tb[longestIndex]->getEnd();
            printf("Day #%d: the longest nap starts at %d:%02d and will last for ", days, (time + onTime) / 60, (time + onTime) % 60);
            if (longest / 60 != 0)
            {
                printf("%d hours and ", longest / 60);
                longest %= 60;
            }
            printf("%d minutes.\n", longest);
        }

        days++;
    }
    return 0;
}