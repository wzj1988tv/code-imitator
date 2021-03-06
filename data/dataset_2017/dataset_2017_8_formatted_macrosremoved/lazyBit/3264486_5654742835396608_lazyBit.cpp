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

char str[50];

long long pow2(int a, long long int b) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y);
    }
    y = (y * y);
    b /= 2;
  }
  return x;
}
LL dist[2];
int main() {
  // #ifndef ONLINE_JUDGE
  //        input;
  //        output;
  //    #endif
  int i, j, l, m, t, s = 0, d;
  LL n, k, x, x1, level, used, prevLevel, rem;
  scanf("%d", &t);
  ;
  int c = 1;
  while (t--) {
    cin >> n;
    cin >> k;
    x = n;
    x1 = n;
    level = log2(k);
    dist[0] = 1;
    dist[1] = 0;
    LL tempx, tempx1;
    LL tempdist[2];
    for (i = 1; i <= level; i++) {
      tempdist[0] = 0;
      tempdist[1] = 0;
      if (x & 1) {
        tempx = x / 2;
        tempx1 = tempx;
        tempdist[0] = 2 * dist[0];
      } else {
        tempx = (x - 1) / 2;
        tempx1 = tempx + 1;
        tempdist[0] = dist[0];
        tempdist[1] = dist[0];
      }

      if (dist[1] > 0) {
        if (!(x1 & 1)) {
          tempx = (x1 - 1) / 2;
          tempx1 = x1 / 2;
          tempdist[0] += dist[1];
          tempdist[1] += dist[1];
        } else {
          tempx1 = x1 / 2;
          tempdist[1] += 2 * dist[1];
        }
      }
      x = tempx;
      x1 = tempx1;
      dist[0] = tempdist[0];
      dist[1] = tempdist[1];
    }
    prevLevel = pow2(2, level) - 1;
    rem = k - prevLevel;
    // cout<<x<<' '<<x1<<' '<<dist[0]<<' '<<dist[1]<<endl;
    if (rem > dist[1]) {
      used = x;
    } else {
      used = x1;
    }
    // debug(prevLevel,rem,x,x1,used);
    // cout<<used<<endl;
    if (used & 1) {
      cout << "Case #" << c++ << ": " << used / 2 << " " << used / 2 << endl;
    } else {
      cout << "Case #" << c++ << ": " << used / 2 << " " << (used - 1) / 2
           << endl;
    }
  }
  return (0);
}
