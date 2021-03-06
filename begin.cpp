#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cassert>
#include <list>
#include <iomanip>
#include <math.h>
#include <deque>
#include <utility>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <climits>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <sstream>

using namespace std;

#define mpr make_pair
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <double, double> pdd;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <double> vd;
typedef vector <string> vs;
typedef map <string, int> mpsi;
typedef map <double, int> mpdi;
typedef map <int, int> mpii;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP_1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FOR(i, b, e) for (int i = (int)(b); i < (int)(e); i++)
#define EACH(it, A) for (__typeof__(A.begin()) it = A.begin(); it != it.end(); it++);
#define REACH(it, A) for (__typeof__(A.rbegin()) it = A.rbegin(); it != it.rend(); it++);

const double pi = acos(0.0) * 2.0;
const double eps = 1e-12;
const int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

long long pow(long long n, long long m, long long mod = 0){
    if(m < 0) return 0;
    long long ans = 1;
    long long k = n;
    while(m){
        if(m & 1) {
            ans *= k;
            if(mod) ans %= mod;
        }
        k *= k;
        if(mod) k %= mod;
        m >>= 1;
    }
    return ans;
}

struct baba
{
          int a, b, c, d;
};

bool operator < (const baba &x, const baba &y)
{ 
	return ((x.a < y.a) || (x.a == y.a && x.b < y.b)) 
      	|| (x.a == y.a && x.b == y.b && x.c < y.c) 
      	|| (x.a == y.a && x.b == y.b && x.c == y.c && x.d < y.d);
}

//==============================================================================================================

const int MAXN = ;

int init()
{
	return 0;
}

int main()
{
	freopen("in.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		init();
	}
	return 0;
}

int main()
{
	freopen("in.txt", "r", stdin);
	while (scanf("%d%d", &O, &X) != EOF)
	{
		init();
	}
	return 0;
}
