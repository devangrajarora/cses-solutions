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

void solve() {

	string s; cin >> s;
	vi freq(26,0);
	int n = s.size();

	string ans(n,'.');
	int st = 0, en = n-1;
	for(char c : s) freq[c - 'A']++;
	rep(i,26) {
		if(freq[i]%2) {
			if(n%2 and ans[n/2] == '.') {
				ans[n/2] = (char)('A'+i);
				freq[i]--;
			} else {
				p1("NO SOLUTION");
				return;
			}
		} 

		while(freq[i]) {
			ans[st] = ans[en] = (char)('A'+i);
			freq[i] -= 2;
			st++, en--;
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