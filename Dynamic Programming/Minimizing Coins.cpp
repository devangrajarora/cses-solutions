#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD 1000000007
#define fi first
#define se second
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define repe(i,n) for(ll i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(ll i = a ; i < b ; i++)
#define repeb(i,a,b) for(ll i = a ; i <= b ; i++)
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

// O(N*M) space

void solve() {

    ll n, x; cin >> n >> x;
    vvi dp(n+1, vi(x+1));

    vi c(n+1);
    for(int i = 1 ; i <= n ; i++) {
    	cin >> c[i];
    }

    // no coins available
    for(int j = 1 ; j <= x ; j++) {
    	dp[0][j] = INT_MAX;
    }

    for(int i = 1 ; i <= n ; i++) {
    	for(int j = 1 ; j <= x ; j++) {

    		int include = (c[i] <= j and dp[i][j-c[i]] != INT_MAX) ? 1 + dp[i][j-c[i]] : INT_MAX;
    		int exclude = dp[i-1][j];
    		dp[i][j] = min(include, exclude);
    	}
    }

    int ans = dp[n][x] == INT_MAX ? -1 : dp[n][x];
    p1(ans);
}

void solve1() {

	ll n, x;
	cin >> n >> x;
	vi dp(x+1,INT_MAX);
	dp[0] = 0; // target sum is 0

	vi c(n);
	rep(i,n) cin >> c[i];

	rep(i,n) {
		repeb(j,1,x) {
			int include = (c[i] <= j and dp[j-c[i]] != INT_MAX) ? 1 + dp[j-c[i]] : INT_MAX;
    		int exclude = dp[j];
    		dp[j] = min(include, exclude);
		}
	}

	int ans = dp[x] == INT_MAX ? -1 : dp[x];
    p1(ans);
    // p1(dp);
}

int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
    freopen("/home/devang/input.txt","r",stdin);
    freopen("/home/devang/output.txt","w",stdout);
    #endif

    //w(tc)
    	solve1();
	
	return 0;
}