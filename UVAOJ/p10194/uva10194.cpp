#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Team
{
public:
    Team(string s)
    {
        name = s;
        point = 0;
        gamePlayed = 0;
        wins = 0;
        ties = 0;
        losses = 0;
        dif = 0;
        scored = 0;
        against = 0;
    }

    void win(int scoredPt, int againstPt)
    {
        point += 3;
        wins++;
        gamePlayed++;
        scored += scoredPt;
        against += againstPt;
        dif = dif + scoredPt - againstPt;
    }

    void loss(int scoredPt, int againstPt)
    {
        losses++;
        gamePlayed++;
        scored += scoredPt;
        against += againstPt;
        dif = dif + scoredPt - againstPt;
    }

    void tie(int scoredPt)
    {
        point++;
        ties++;
        gamePlayed++;
        scored += scoredPt;
        against += scoredPt;
    }

    void print()
    {
        cout << name << ' ';
        printf("%dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", point, gamePlayed, wins, ties, losses, dif, scored, against);
    }

    friend bool compare(Team *a, Team *b);
    string name;

private:
    //member data
    int point;
    int gamePlayed;
    int wins;
    int ties;
    int losses;
    int dif;
    int scored;
    int against;
};

bool compare(Team *a, Team *b)
{
    if (a->point != b->point)
    {
        return a->point > b->point;
    }
    else if (a->wins != b->wins)
    {
        return a->wins > b->wins;
    }
    else if (a->dif != b->dif)
    {
        return a->dif > b->dif;
    }
    else if (a->scored != b->scored)
    {
        return a->scored > b->scored;
    }
    else if (a->gamePlayed != b->gamePlayed)
    {
        return a->gamePlayed < b->gamePlayed;
    }
    else
    {
        string::iterator it1 = a->name.begin();
        string::iterator it2 = b->name.begin();
        for (; it1 != a->name.end() && it2 != a->name.end();)
        {
            char c = *it1;
            char d = *it2;
            if (c >= 'A' && c <= 'Z')
            {
                c = c - 'A' + 'a';
            }
            if (d >= 'A' && d <= 'Z')
            {
                d = d - 'A' + 'a';
            }
            if (c != d)
            {
                return c < d;
            }
            it1++;
            it2++;
        }
        if (it1 == a->name.end())
        {
            return true;
        }
        if (it2 == a->name.end())
        {
            return false;
        }
        return true;
    }
}

int main()
{
    int n;
    string tmp;

    cin >> n;
    getline(cin, tmp);
    for (int i = 0; i < n; i++)
    {
        string tournament;
        int t;
        int g;

        getline(cin, tournament);
        cin >> t;
        Team *teams[t];
        getline(cin, tmp);
        for (int j = 0; j < t; j++)
        {
            string tmp;
            getline(cin, tmp);
            teams[j] = new Team(tmp);
        }

        cin >> g;
        getline(cin, tmp);
        for (int j = 0; j < g; j++)
        {
            string t1 = "";
            string t2 = "";
            string stoscore = "";
            int t1ID;
            int t2ID;
            int loc[3];
            int score1;
            int score2;
            int k;

            getline(cin, tmp);
            //string process
            loc[0] = tmp.find('#');
            loc[1] = tmp.find('@');
            loc[2] = tmp.find_last_of('#');

            //team 1
            for (k = 0; k < loc[0]; k++)
            {
                t1 += tmp.at(k);
            }
            //score 1
            for (k = loc[0] + 1; k < loc[1]; k++)
            {
                stoscore += tmp.at(k);
            }
            score1 = stoi(stoscore);
            //score 2
            stoscore = "";
            for (k = loc[1] + 1; k < loc[2]; k++)
            {
                stoscore += tmp.at(k);
            }
            score2 = stoi(stoscore);
            //team 2;
            for (k = loc[2] + 1; k < tmp.size(); k++)
            {
                t2 += tmp.at(k);
            }

            for (int k = 0; k < t; k++)
            {
                if (teams[k]->name == t1)
                {
                    t1ID = k;
                }
                if (teams[k]->name == t2)
                {
                    t2ID = k;
                }
            }

            //team 1 win
            if (score1 > score2)
            {
                teams[t1ID]->win(score1, score2);
                teams[t2ID]->loss(score2, score1);
            }
            //team 2 win
            else if (score1 < score2)
            {
                teams[t1ID]->loss(score1, score2);
                teams[t2ID]->win(score2, score1);
            }
            //tie
            else
            {
                teams[t1ID]->tie(score1);
                teams[t2ID]->tie(score2);
            }
        }

        sort(teams, teams + t, compare);

        if (i != 0)
        {
            cout << endl;
        }
        cout << tournament << endl;
        for (int j = 0; j < t; j++)
        {
            printf("%d) ", j + 1);
            teams[j]->print();
        }
    }
    return 0;
}