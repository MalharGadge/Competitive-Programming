#include <bits/stdc++.h> 

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define inf INT_MAX
#define all(c) (c).begin(), (c).end()
const ll mod = 1000000007;
 
// SegT for sum queries
#define maxn (int)1e6

int n,t[4*maxn];

// a is the given array , v is the current vertex , tl and tr define the curr segment
// initially v=1 , tl = 0 , tr = n-1; to build the tree

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

// returns sum a[l..r]
// initially v = 1,tl = 0,tr = n-1;

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }

    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

// for the assign as : a[pos] = new_val

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
        // to update the tree
    }
}















