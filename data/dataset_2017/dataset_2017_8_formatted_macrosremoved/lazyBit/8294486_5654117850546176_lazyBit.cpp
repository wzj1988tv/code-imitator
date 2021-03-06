#include <bitset>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>

#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <string>

#include <algorithm>
#include <functional>
#include <list>
#include <map>
#include <numeric>
#include <utility>
#include <vector>
// #include <random>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;

typedef long long LL;           // NOTES:int64
typedef unsigned long long ULL; // NOTES:uint64
typedef unsigned uint;

const double pi = acos(-1.0); // NOTES:pi
const double eps = 1e-11;     // NOTES:eps
const int MAXI = 0x7fffffff;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const char colors[] = {'R', 'O', 'Y', 'G', 'B', 'V'};
const char dz[] = "SENW";
struct debugger {
  template <typename T> debugger &operator,(const T &v) {
    cerr << v << " ";
    return *this;
  }
} dbg;

void debugarr(int *arr, int n) {
  cout << "[";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << "]" << endl;
}

// R O Y G B V
vector<pair<int, int>> v;
int main() {

  freopen("input.txt", "r", stdin);
  ;
  // output;

  int n, i, j, k, l, m, t, s = 0, d, p;
  scanf("%d", &t);
  ;
  int c = 1;
  while (t--) {
    scanf("%d", &n);
    ;
    int a[1010];
    int b[1010];
    v.clear();
    for (i = 0; i < 6; i++) {
      scanf("%d", &a[i]);
      ;
    }
    d = 0;
    v.push_back(make_pair(a[0], 0));
    v.push_back(make_pair(a[2], 2));
    v.push_back(make_pair(a[4], 4));
    if (v[2].first > v[0].first + v[1].first) {
      printf("Case #%d: IMPOSSIBLE\n", c++);
      continue;
    }
    sort(v.begin(), v.end());
    while (d < n) {
      if (v[2].first > 0) {
        a[d++] = v[2].second;
        v[2].first--;

        if (v[1].first > 0) {
          a[d++] = v[1].second;
          v[1].first--;
        } else if (v[0].first > 0) {
          a[d++] = v[0].second;
          v[0].first--;
          if (v[2].first == 0)
            break;
        }
      } else {
        break;
      }
      // debugarr(a,d);
      // cout<<v[0].first<<endl;
      // if(d==4) break;
      // cout<<d<<endl;
    }
    s = 0;
    // cout<<v[0].first<<' '<<v[0].second<<endl;
    if (v[0].first > 0) {
      for (i = 0; i < d; i++) {
        b[s++] = a[i];
        if (v[0].first > 0 && a[i + 1] != v[0].second) {
          b[s++] = v[0].second;
          v[0].first--;
        }
        // cout<<v[0].first<<endl;
        // debugarr(b,s);
      }
      for (i = 0; i < s - 1; i++) {
        if (b[i] == b[i + 1]) {
          printf("Case #%d: IMPOSSIBLE\n", c++);
          break;
        }
      }
      if (i != s - 1)
        continue;
      if (b[s - 1] == b[0]) {
        printf("Case #%d: IMPOSSIBLE\n", c++);
        continue;
      }
      printf("Case #%d: ", c++);
      for (i = 0; i < s; i++) {
        printf("%c", colors[b[i]]);
      }
      cout << endl;
    } else if (a[d - 1] == a[0]) {
      printf("Case #%d: IMPOSSIBLE\n", c++);
    } else {
      printf("Case #%d: ", c++);
      for (i = 0; i < d; i++) {
        printf("%c", colors[a[i]]);
      }
      cout << endl;
    }
  }
  return (0);
}
