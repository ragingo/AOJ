#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <numeric>

using namespace std;

struct room_info
{
  int b;
  int f;
  int r;
  int v;
};

namespace
{

const int MAX_BUILDING = 4;
const int MAX_FLOOR = 3;
const int MAX_ROOM = 10;

} // namespace

static bool operator<(const room_info &lhs, const room_info &rhs)
{
  return tie(lhs.b, lhs.f, lhs.r) < tie(rhs.b, rhs.f, rhs.r);
}

int main()
{
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<room_info> input;
  while (n--)
  {
    room_info info;
    cin >> info.b >> info.f >> info.r >> info.v;
    input.emplace_back(info);
  }

  sort(input.begin(), input.end());

  for (int b = 0; b < MAX_BUILDING; b++)
  {
    if (b > 0)
    {
      cout << "####################" << endl;
    }

    for (int f = 0; f < MAX_FLOOR; f++)
    {
      for (int r = 0; r < MAX_ROOM; r++)
      {
        auto result =
            accumulate(input.begin(), input.end(), 0, [=](auto &val, auto &it) {
              if (it.b == b + 1 && it.f == f + 1 && it.r == r + 1)
              {
                return val + it.v;
              }
              return val;
            });
        cout << " " << result;
      }

      cout << endl;
    }
  }

  return 0;
}