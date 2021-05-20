#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD 1000000007
#define fi first
#define se second
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define repe(i,n) for(int i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(int i = a ; i < b ; i++)
#define repeb(i,a,b) for(int i = a ; i <= b ; i++)
#define rfor(i,n,a) for(ll i = n ; i >= a ; i--)
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define vvi vector<vi>
#define pii pair <ll,ll>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a,b) cout << a << " " << b << endl
#define p3(a,b,c) cout << a << " " << b << " " << c << endl
#define watch(x) cout << (#x) << " is " << (x) << endl
#define w(x) ll x; cin>>x; while(x--)

    template <typename T1, typename T2>
inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
{
	return os << "(" << p.first << ", " << p.second << ")";
}

    template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
{
	bool first = true;
	for(unsigned int i = 0; i < v.size(); i++)
	{
		if(!first)
			os << " ";
		os << v[i];
		first = false;
	}
	return os;
}

/*-------------------------------------------------*/

// read once, read again, think, code

void solve() {

	int n, m; cin >> n >> m;

	vi a(n+1);
	rep(i,n) cin >> a[i];

	vvi dp(n+1, vi(m+1));

	// initialization
	if(a[0] == 0) {
		repeb(j,1,m) dp[0][j] = 1;
	} else {
		dp[0][a[0]] = 1;
	}

	for(int i = 0 ; i < n ; i++) {
		if(a[i] != 0) {
			for(int k = max(1,a[i]-1) ; k <= min(m,a[i]+1) ; k++) {
				dp[i+1][k] = (dp[i+1][k] + dp[i][a[i]]) % MOD; 
			}

		} else {

			repeb(j,1,m) {
				for(int k = max(1,j-1) ; k <= min(m,j+1) ; k++) {
					dp[i+1][k] = (dp[i+1][k] + dp[i][j]) % MOD; 
				}
			}
		}
	}

	int ans = 0;

	if(a[n-1] == 0) {
		repeb(j,1,m) {
			ans = (ans + dp[n-1][j]) % MOD;
		}

	} else {
		ans = dp[n-1][a[n-1]];
	}


	p1(ans);
}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
	freopen("/home/devang/input.txt","r",stdin);
	freopen("/home/devang/output.txt","w",stdout);
    #endif

    //w(tc)
	solve();
	
	return 0;
}