#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vi vector <int>
#define vvi vector <vi>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
#define MOD 1000000007
using namespace std;

const int N = 2e5;
int n;
int t[2*N];

void build (){
	for (int i = n-1; i>0; i--) t[i] = t[i<<1] + t[(i<<1) | 1]; 
}

void modify (int p, int value){
	for (t[p+=n]=value; p>1; p>>=1) t[p>>1]=t[p]+t[p^1];
}

int query (int l, int r){
	int res = 0;
	for (l+=n, r+=n; l<r; l>>=1, r>>=1){
		if (l&1) res+=t[l++];
		if (r&1) res+=t[--r];
	}
	return res;
}
