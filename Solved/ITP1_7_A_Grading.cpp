#include <iostream>

using namespace std;

inline bool is_between(int v, int begin, int end)
{
    return begin <= v && v <= end;
}

struct score_info
{
    char score;
    int lower;
    int upper;
    bool retry_enable;
    int retry;
    char mod_score;
};

int main()
{
    score_info table[] = {
        {'A', 80, 100, false, -1, -1},
        {'B', 65, 79, false, -1, -1},
        {'C', 50, 64, false, -1, -1},
        {'D', 30, 49, true, 50, 'C'},
        {'F', 0, 29, false, -1, -1},
        {'F', -2, -2, false, -1, -1},
    };

    while (true)
    {
        int m, f, r;
        cin >> m >> f >> r;

        if (m == -1 && f == -1 && r == -1)
        {
            break;
        }

        char score = 'F';

        if (m == -1 || f == -1)
        {
            cout << score << endl;
            continue;
        }

        int mf = m + f;

        for (auto& item : table)
        {
            if (is_between(mf, item.lower, item.upper))
            {
                if (item.retry_enable)
                {
                    score = r >= item.retry ? item.mod_score : item.score;
                }
                else
                {
                    score = item.score;
                }
                break;
            }
        }

        cout << score << endl;
    }
}