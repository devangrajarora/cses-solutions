#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define fi first
#define se second
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define repe(i,n) for(ll i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(ll i = a ; i <= b ; i++)
#define pb push_back
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair <ll,ll>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a,b) cout << a << " " << b << endl
#define w(x) ll x; cin>>x; while(x--)

int dr4[] = {0,1,0,-1}, dc4[] = {1,0,-1,0};
int dr8[] = {0,1,1,1,0,-1,-1,-1}, dc8[] = {1,1,0,-1,-1,-1,0,1};

/*-------------------------------------------------*/

// read once, read again, think, code

bool comp(pii &a, pii &b) {
	return (a.se == b.se) ? a.fi < b.fi : a.se < b.se;
}

void solve() {

    ll n, currEnd = 0, ans = 1, st, en;
	vector<pii> movies;
	cin >> n;
	rep(i,n) {
		cin >> st >> en;
		movies.pb({st,en});
	}

	sort(movies.begin(), movies.end(), comp);
	currEnd = movies[0].se;
	repb(i,1,movies.size()-1) {
		if(movies[i].fi >= currEnd) {
			ans++;
			currEnd = movies[i].se;
		}
	}

	p1(ans);
}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    //w(tc)
    	solve();
	
	return 0;
}