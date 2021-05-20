#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int MOD = 1000000007;
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

void solve() {

	int n, x; cin >> n >> x;
    vvi dp(n+1,vi(x+1));

    repe(i,n) dp[i][0] = 1;

    vi c(n+1);
    rep(i,n) cin >> c[i+1];

    for(int target = 1 ; target <= x ; target++) {
    	for(int i = 1 ; i <= n ; i++) {
    		int include = (c[i] <= target) ? dp[n][target - c[i]] : 0;
    		int exclude = dp[i-1][target];
    		dp[i][target] = (include + exclude) % MOD;
    	}
    }


    p1(dp[n][x]);
}

void solve1() {

	int n, x; cin >> n >> x;
	vi dp(x+1);
	dp[0] = 1;

	vi c(n);
	rep(i,n) cin >> c[i];

	for(int target = 1 ; target <= x ; target++) {
		for(int i = 0 ; i < n ; i++) {
			if(c[i] <= target) {
				dp[target] = (dp[target] + dp[target - c[i]]) % MOD;
			}
		}
	}

	p1(dp[x]);
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