// result: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3325536#1

#include <iostream>

using namespace std;

//#define MY_DEGUB

#ifdef MY_DEGUB
inline void mat_dump(int* mat, int rows, int cols)
{
    cout << "====================" << endl;
    cout << rows << "x" << cols << " matrix dump" << endl;
    cout << "====================" << endl;

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            int offset = r * cols;
            cout << " " << *(mat + offset + c);
        }
        cout << endl;
    }
}
#else
inline void mat_dump(int *mat, int rows, int cols)
{
}
#endif

inline void mat_load(int *mat, int rows, int cols)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            int offset = r * cols;
            cin >> *(mat + offset + c);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int *mat_a = new int[n * m]();
    int *mat_b = new int[m]();
    int *mat_c = new int[n]();

    mat_load(mat_a, n, m);
    mat_load(mat_b, m, 1);

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            int offset = r * m;
            *(mat_c + r) += *(mat_a + offset + c) * *(mat_b + c);
        }
    }

    // debug
    mat_dump(mat_a, n, m);
    mat_dump(mat_b, m, 1);
    mat_dump(mat_c, n, 1);

    // result
    for (int r = 0; r < n; r++)
    {
        cout << *(mat_c + r) << endl;
    }

    delete[] mat_a;
    delete[] mat_b;
    delete[] mat_c;
}

/* stdin data
3 4
1 2 0 1
0 3 0 1
4 1 1 0
1
2
3
0
*/
