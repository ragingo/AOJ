#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    //cout << fixed << std::setprecision(20);

    while (true)
    {
        int a, b, c;
        char op;
        cin >> a; cin >> op; cin >> b;
        switch (op)
        {
            case '+': c=a+b; break;
            case '-': c=a-b; break;
            case '*': c=a*b; break;
            case '/': c=a/b; break;
            case '?': return 0;
        }
        cout << c << endl;
    }
}
