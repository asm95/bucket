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
#define  mod        (ll)((1e9) + 7)
#define  inf        INT_MAX

int min (int a, int b) { return a < b ? a : b; }
int max (int a, int b) { return a > b ? a : b; }

int n, x;
int coins[20], tb[10005];

int dp (int change) {
    if (change == 0) return 1;
    if (tb[change] != -1) return tb[change];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (change - coins[i] >= 0) {
            ans += dp (change - coins[i]);
            ans %= mod;
        }
    }
    return tb[change] = ans % mod;
}

int main (void) {
    scanf ("%d %d", &n, &x);
    memset (tb, -1, sizeof (tb));
    for (int i = 0; i < n; i++) scanf ("%d", &coins[i]);

    printf("%d\n", dp (x));

    return 0;
}
