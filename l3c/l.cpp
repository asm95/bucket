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

ll n;
ll tb[1000005];

ll dp (ll x) {
    if (x == 0ll) return 1ll;
    if (x == 1ll) return 0ll;
    if (tb[x] != -1ll) return tb[x];
    tb[x] = ((x - 1ll) * (dp (x - 1ll) + dp (x - 2ll))) % mod;
    return tb[x];
}

int main (void) {
    memset (tb, -1ll, sizeof (tb));
    scanf ("%lld", &n);
    printf("%lld\n", dp (n));

    return 0;
}
