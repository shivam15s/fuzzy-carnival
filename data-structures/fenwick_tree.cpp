#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vi vector <int>
#define vvi vector <vi>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<ll, ll>
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
#define MOD 1000000007
using namespace std;

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

int main(){

#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    

    // cerr<<"\nTime elapsed: "<<1000*clock()/CLOCKS_PER_SEC<<"ms\n";
    return 0;
}
