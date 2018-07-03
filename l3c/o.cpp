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


int n, coins[10005];
int tb[10005];

int dp (int index) {
    if (index >= n) return 0;
    if (tb[index] != -1) return tb[index];
    return tb[index] = max (
        coins[index] + dp (index + 2),
        dp (index + 1));
}

int main (void) {
    scanf ("%d", &n);
    memset (tb, -1, sizeof (tb));
    for (int i = 0; i < n; i++) scanf ("%d", &coins[i]);

    printf("%d\n", dp (0));

    return 0;
}
