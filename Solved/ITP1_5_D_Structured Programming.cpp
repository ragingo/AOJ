#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  for (int i = 1; i <= n; i++)
  {
    if (i % 3 == 0 || i % 10 == 3) {
      cout << " " << i;
    }
    else {
      int x = i;
      while (x) {
        x /= 10;
        if (x % 10 == 3) {
          cout << " " << i;
          break;
        }
      }
    }
  }
  
  cout << endl;
}
