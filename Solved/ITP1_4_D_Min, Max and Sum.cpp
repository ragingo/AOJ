#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {
  int n;
  cin >> n;

  vector<int> v;
  int a;

  while (n--) {
    cin >> a;
    v.push_back(a);
  }
  
  int min = *min_element(v.begin(), v.end());
  int max = *max_element(v.begin(), v.end());
  int64_t sum = accumulate(v.begin(), v.end(), 0);
  cout << min << " " << max << " " << sum << endl;
}
