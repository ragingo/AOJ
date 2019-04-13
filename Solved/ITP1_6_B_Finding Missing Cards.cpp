#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  multimap<char, int> table;
  while (n--) {
    char type;
    int num;
    cin >> type >> num;
    table.emplace(type, num);
  }

  char keys[] = {'S', 'H', 'C', 'D'};
  for (auto& key : keys) {
    auto key_iter = table.equal_range(key);

    for (int i=1; i<=13; i++) {
      auto it = find_if(key_iter.first, key_iter.second, [&](auto a){ return a.second == i; });
      if (it == key_iter.second) {
        cout << key_iter.first->first << " " << i << endl;
      }
    }
  }
}
