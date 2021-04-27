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
#define vc vector<char>
#define vvc vector<vc>

int dr4[] = {0,1,0,-1}, dc4[] = {1,0,-1,0};
int dr8[] = {0,1,1,1,0,-1,-1,-1}, dc8[] = {1,1,0,-1,-1,-1,0,1};

/*-------------------------------------------------*/

// read once, read again, think, code

ll ans = 0;

void printBoard(vvc &board) {
	rep(i,8) {
    	rep(j,8) {
    		cout << board[i][j];
    	} cout << "\n";
    }
}

void backtrack(vvc &board, int r, int c, int cnt) {

	if(cnt == 8) {
		ans++;
		return;
	}

	if(r == 8) return;

	if(board[r][c] != '*') {

		bool ok = true;
		rep(i,8) {
			if(board[r][i] == 'Q' or board[i][c] == 'Q') {
				ok = false;
				break;
			}
		}

		int i = r, j = c, ii = r, jj = c, iii = r, jjj = c, iiii = r, jjjj = c;
		while(ok and ((i>=0 and j>=0) or (ii<8 and jj<8) or (iii>=0 and jjj<8) or (iiii<8 and jjjj>=0))) {
			if(i>=0 and j>=0) {
				if(board[i][j] == 'Q') {
					ok = false;
					break;
				} else {
					i--, j--;
				}	
			}

			if(ii<8 and jj<8) {
				if(board[ii][jj] == 'Q') {
					ok = false;
					break;
				} else {
					ii++, jj++;
				}	
			}

			if(iii>=0 and jjj<8) {
				if(board[iii][jjj] == 'Q') {
					ok = false;
					break;
				} else {
					iii--, jjj++;
				}	
			}

			if(iiii<8 and jjjj>=0) {
				if(board[iiii][jjjj] == 'Q') {
					ok = false;
					break;
				} else {
					iiii++, jjjj--;
				}	
			}
		}

		if(ok) {
			board[r][c] = 'Q';
			// p3("laga do: ",r,c);
			backtrack(board, r+1, 0, cnt+1);
			board[r][c] = '.';
		}
	}

	(c == 7) ? backtrack(board, r+1, c, cnt) : backtrack(board, r, c+1, cnt);
	

}

void solve() {

    vvc board(8, vc(8));
    string s;
    rep(i,8) {
    	cin >> s;
    	rep(j,s.size()) {
    		board[i][j] = s[j];
    	}
    }
    // p1(ans);
	backtrack(board,0,0,0);    
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