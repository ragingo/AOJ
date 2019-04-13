// problem: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_B&lang=jp
// result: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3331313#2
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    stringstream output;

    while (true)
    {
        int n, x;
        cin >> n >> x;

        if (n == 0 && x == 0)
        {
            break;
        }

        int count = 0;

        for (int a = 1; a <= n - 1; ++a)
        {
            for (int b = a + 1; b <= n; ++b)
            {
                int c = x - a - b;
                if (b < c && c <= n)
                {
                    ++count;
                }
            }
        }

        output << count << endl;
    }

    cout << output.str() << flush;
}