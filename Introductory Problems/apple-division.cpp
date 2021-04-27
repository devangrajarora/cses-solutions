#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
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

ull ans, n, sum = 0;

void rec(vi &a, int i, ull currSum) {
	if(i == n) {
		ull diff = (sum >= 2*currSum) ? sum - 2*currSum : 2*currSum - sum;
		ans = min(ans,diff);
		return;
	}

	rec(a,i+1,currSum);
	rec(a,i+1,currSum+a[i]);
}

void solve() {

    cin >> n;
    vi a(n);
    rep(i,n) {
    	cin >> a[i];
    	sum += a[i];
    }
    ans = sum+1;
    rec(a,0,0);
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
    	// p1(cnt);
	
	return 0;
}