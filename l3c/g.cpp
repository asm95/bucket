#include <bits/stdc++.h>

using namespace std;

#define  un         unsigned
#define  ll         long long
#define  ull        unsigned long long
#define  ii         pair < int, int >
#define  vi         vector < int >
#define  vii        vector < ii >
#define  pb         push_back
#define  mp         make_pair
#define  mt         make_tuple
#define  ff         first
#define  ss         second
#define  PRINT(x)   {cout<<#x<<": "<<x<<"\n";}
#define  SET(k,v)   memset((k), (v), sizeof((k)))
#define  CPY(d,s,n) memcpy((d), (s), (n))
#define  mod        (1e9) + 7
#define  inf        INT_MAX

int min (int a, int b) { return a < b ? a : b; }
int max (int a, int b) { return a > b ? a : b; }

int n, x;
int tb[1005], coins[1005];

int dp (int value) {
    if (value == 0) return 0;
    if (tb[value] != -1) return tb[value];

    int ans = inf;
    for (int i = 0; i < n; i++) {
        if (value - coins[i] >= 0) {
            ans = min (ans, 1 + dp (value - coins[i]));
            tb[value] = ans;
        }
    }
    return ans;
}

int main (void) {
    memset (tb, -1, sizeof (tb));
    scanf ("%d %d", &n, &x);
    for (int i = 0; i < n; i++) scanf ("%d", &coins[i]);

    printf("%d\n", dp (x));

    return 0;
}
