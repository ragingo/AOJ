// problem: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_C&lang=jp
// result: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3331500#2
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int rows, cols;
    cin >> rows >> cols;

    int table[101 * 101] = {};

    for (int r = 0; r < rows + 1; r++)
    {
        int offset = cols * r;

        for (int c = 0; c < cols + 1; c++)
        {
            if (c < cols && r < rows)
            {
                cin >> table[offset + r + c];

                // 最終列に書き込む
                table[offset + r + cols] += table[offset + r + c];
            }

            // 最終行に書き込む
            if (r < rows)
            {
                table[rows * (cols + 1) + c] += table[offset + r + c];
            }
        }
    }

    for (int r = 0; r < rows + 1; ++r)
    {
        for (int c = 0; c < cols + 1; ++c)
        {
            int offset = cols * r;
            if (c > 0)
            {
                cout << " ";
            }
            cout << table[offset + r + c];
        }
        cout << endl;
    }
}