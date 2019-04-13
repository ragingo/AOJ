#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);

    while (true)
    {
        int h, w;
        cin >> h >> w;
        if (h == 0 && w == 0)
            break;

        vector<char> board(w * h);
        fill(board.begin(), board.end(), '#');

        for (int r = 0; r < h; r++)
        {
            for (int c = 0; c < w; c++)
            {
                if (r == 0 && c == 0)
                {
                    continue;
                }
                char *current = (board.data() + r + c);
                char prev = *(board.data() + r + c - 1);
                if (prev == '#')
                {
                    *current = '.';
                }
            }
        }

        for (int r = 0; r < h; r++)
        {
            for (int c = 0; c < w; c++)
            {
                cout << *(board.data() + r + c);
            }
            cout << endl;
        }

        cout << endl;
    }
}
