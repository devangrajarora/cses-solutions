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

ll solve(ll x, ll y) {

    ll ans = 0;
    // cin >> x >> y;
    if(x == 1 and y == 1) {
    	// p1(1);
    	return 1;
    }

    if(x > y) {
    	ans = (x%2) ? powl(x-1,2)+1 + (y-1) : powl(x,2) - (y-1);
    } else {
    	ans = (y%2) ? powl(y,2) - (x-1) : powl(y-1,2)+1 + (x-1);
    }

    return ans;
}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    w(tc) {
    	ll x, y;
    	cin >> x >> y;
        p1(solve(x,y));
     }
	
	return 0;
}