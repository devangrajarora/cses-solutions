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
#define p3(a,b,c) cout << a << " " << b << " " << c << endl
#define w(x) ll x; cin>>x; while(x--)

int dr4[] = {0,1,0,-1}, dc4[] = {1,0,-1,0};
char moves[4] = {'R','U','L','D'};
int dr8[] = {0,1,1,1,0,-1,-1,-1}, dc8[] = {1,1,0,-1,-1,-1,0,1};

/*-------------------------------------------------*/

// read once, read again, think, code

int moveDown(string&, int, int, int, vvi&,int,int);
int moveRight(string&, int, int, int, vvi&,int,int);
int moveUp(string&, int, int, int, vvi&,int,int);
int moveLeft(string&, int, int, int, vvi&,int,int);

bool valid(int i, int j) {
	return (1 <= i and i <= 7 and 1 <= j and j <= 7);
}

bool isLooped(int x,int y, vvi &vis){
	if(x==1||x==7||y==1||y==7)return false;
	if(vis[x][y+1]==1&&vis[x][y-1]==1&&vis[x-1][y]==0&&vis[x+1][y]==0)return true;
	if(vis[x+1][y]==1&&vis[x-1][y]==1&&vis[x][y+1]==0&&vis[x][y-1]==0)return true;
	return false;
}

int backtrack(string &s, int idx, int r, int c, vvi &vis, int prevR, int prevC) {
	
	if(!valid(r,c)) return 0;
	// p2(r,c);

	if(r == 7 and c == 1) {
		return (idx==48);
	}

	if(idx == 48) return 0;
	if(isLooped(r,c,vis))return 0;

	
	vis[r][c] = 1;

	// can't go up, but can go right and left


	// can't go left, but can go up and down


	// can't go down, but can go left or right


	// can't go right, but can go up and down



	char ch = s[idx];
	int ans = 0;

	if(ch == '?') {

		ans += moveDown(s, idx+1, r+1, c, vis,r,c);
		ans += moveUp(s, idx+1, r-1, c, vis,r,c);
		ans += moveRight(s, idx+1, r, c+1, vis,r,c);
		ans += moveLeft(s, idx+1, r, c-1, vis,r,c);

	} else {

		if(ch == 'D' and valid(r+1,c) and !vis[r+1][c] ) {
			ans += moveDown(s, idx+1, r+1, c, vis,r,c);
		} else if(ch == 'U' and valid(r-1,c) and !vis[r-1][c]) {			
			ans += moveUp(s, idx+1, r-1, c, vis,r,c);
		} else if(ch == 'R' and valid(r,c+1) and !vis[r][c+1]) { 
			ans += moveRight(s, idx+1, r, c+1, vis,r,c);
		} else if(ch == 'L' and valid(r,c-1) and !vis[r][c-1]) {
			ans += moveLeft(s, idx+1, r, c-1, vis,r,c);
		}
	}

	vis[r][c] = 0;
	return ans;
}


int moveRight(string &s, int idx, int r, int c, vvi &vis, int prevR, int prevC) {
	if(!valid(r,c) or vis[r][c]) return 0;
	if ((!valid(r,c+1) or (valid(r,c+1) and vis[r][c+1])) and c+1 != prevC and valid(r+1,c) and !vis[r+1][c] and valid(r-1,c) and !vis[r-1][c]) {
		vis[r][c] = 0;
		return 0;
	} else {
		return backtrack(s, idx+1, r+1, c, vis,r,c);
	}
}

int moveLeft(string &s, int idx, int r, int c, vvi &vis, int prevR, int prevC) {
	if(!valid(r,c) or vis[r][c]) return 0;
	if ((!valid(r,c-1) or (valid(r,c-1) and vis[r][c-1])) and c-1 != prevC and valid(r+1,c) and !vis[r+1][c] and valid(r-1,c) and !vis[r-1][c]) {
		vis[r][c] = 0;
		return 0;
	} else {
		return backtrack(s, idx+1, r, c-1, vis,r,c);
	}
}

int moveUp(string &s, int idx, int r, int c, vvi &vis, int prevR, int prevC) {
	if(!valid(r,c) or vis[r][c]) return 0;
	if ((!valid(r-1,c) or (valid(r-1,c) and vis[r-1][c])) and r-1 != prevR and valid(r,c-1) and !vis[r][c-1] and valid(r,c+1) and !vis[r][c+1]) {
		vis[r][c] = 0;
		return 0;
	} else {
		return backtrack(s, idx+1, r-1, c, vis,r,c);
	}
}

int moveDown(string &s, int idx, int r, int c, vvi &vis, int prevR, int prevC) {
	if(!valid(r,c) or vis[r][c]) return 0;
	if ((!valid(r+1,c) or (valid(r+1,c) and vis[r+1][c])) and r+1 != prevR and valid(r,c-1) and !vis[r][c-1] and valid(r,c+1) and !vis[r][c+1]) {
		vis[r][c] = 0;
		return 0;
	} else {
		return backtrack(s, idx+1, r+1, c, vis,r,c);
	}
}


void solve() {

	string s;
	cin >> s;
	vvi vis(8,vi(8,0));
	int ans = backtrack(s,0,1,1,vis,0,0);

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
