# Dynamic Programming

### Dice Combinations

`dp[n] = numbers of ways to get n after getting a number from 1 to 6 in this turn`

dp[n] = dp[n-1] + dp[n-2] + dp[n-3] + dp[n-4] + dp[n-5] + dp[n-6]

Time complexity: O(N)
Space complexity: O(N)

Can also be done in constant space by storing just the last 6 values

### Minimizing Coins

#### \#1 O(N\*Target) space

Base case:

```
// if no coins are available we won't have a solution
dp[0][currTarget] = INT_MAX; // for 1 <= currTarget <= Target 

// if Target is 0, there are zero ways to collect coins
dp[i][0] = 0; // for 0 <= i <= n

```
dp[i][currTarget] = Minimum number of coins to make currTarget using just first i coins

dp[n][Target] -> final ans

```
int includeCoin = (1 + dp[i][target - c[i]]) if c[i] <= target and dp[i][target - c[i]] != INT_MAX else INT_MAX
int exclude = dp[i-1][target]
dp[i][target] = min(include, exclude)
```   

#### \#2 O(Target) space

We can maintain a single array of size Target, which will go through n iterations. \
`dp[currTarget]` in the i<sup>th</sup> iteration represents number of ways to get sum currTarget with first i coins.

```
int include = (1 + dp[target - c[i]]) if c[i] <= target and dp[i][target - c[i]] != INT_MAX else INT_MAX
int exclude = dp[target] // this value hasn't been updated yet and hence holds the ways of getting sum target with first i-1 coins

dp[target] = min(include, exclude)
```

### Coin Combinations I

#### \#1 O(N\*X) space dp

dp[i][target] = number of ways to get target where last included coin is any coin between 1<sup>st</sup> to i<sup>th</sup> coin.

dp[i][0] = 1 for all 1 <= i <= n because there is only one way to get target 0 ie empty set.
dp[n][target] means number of ways to get sum target where last coin can be any available coin

dp[n][X] is our final answer

```
int waysIfWeUseThisCoin = dp[n][target - c[i]]; // c[i] <= target
int waysIfWeDontUseThisCoin = dp[i-1][target];
dp[i][target] = (waysIfWeUseThisCoin + waysIfWeDontUseThisCoin) % MOD; 
```

#### \#2 O(X) space dp

dp[target] in the ith iteration is number of ways to get to target with some coin between 1<sup>st</sup> to i<sup>th</sup> as the last coin.

dp[target] = (dp[target] + dp[target - c[i]]) % MOD;

```
dp[0] = 1; // base case

for(int target = 1 ; target <= X ; target++) {
	for(int i = i ; i <= n ; i++) {
		if(target >= c[i]) {
			dp[target] += dp[target - c[i]]; // apply MOD here
		}
	} 	
}
```

### Removing Digits

dp[num] = min steps to get from num to 0
dp[num] = 1 + min { dp[num - j] | j is a digit in num }

### Array Description

In the previous problems we used `pull dp` ie using previously calculated dp entries to find current dp enteries. \
In this problem we use `push dp` ie using current dp entries to update future dp states.

`dp[i][j] = number of ways to fill array upto index i where a[i] = j`

initialization for index 0:

if a[0] == 0,
then we can have any possible value in place of a[0], hence `dp[0][j] = 1 for all 1 <= j <= m` \
else dp[0][a[0]] = 1, rest of the row is 0'\s

for any index i, \
if a[i] != 0, then the next element can only be one of [a[i]-1, a[i]+1]. Thus we add value of dp[i][a[i]] to dp[i+1][k] where k is in `[a[i]-1, a[i]+1]`.

if a[i] == 0, then there can be many values which can occupy a[i] to make a valid array upto index i. We go over the entire row, and for every j (1 <= j <= m), we add value of dp[i][j] to [ dp[i+1][j-1], dp[i+1][j+1] ].

Now dp[n-1][j] represents number of ways to fill the array till index n-1, where last element is j.

If a[n-1] != 0, then answer is dp[n-1][a[n-1]],
else if a[n-1] == 0, then answer is sum of dp[n-1][j] for j in [1,m]


### Counting Towers

Observation: \
For the top layer of the tower of height n:
1. It can either end with a tile of width 2
2. Or it can end with two tiles of width 1 each

ways<sub>n</sub> = waysWithTopWidth1<sub>n</sub> + waysWithTopWidth2<sub>n</sub>

#### \#1 O(N) DP

We precalculate results of all N upto 1e6

dp[i][0] = number of towers of height i ending with one tile of width 2
dp[i][1] = number of towers of height i ending with two tiles of width 1

-> Calculating number of towers of height i ending with width 2
1. If tower i-1 ends with tile of with 2, we can:
	i) extend that tile by height 1
	ii) add a new tile of dimensions 2x1

2. If tower i-1 end with 2 blocks of width 1, we can add a new tile if dimensions 2x1

Thus `dp[i][0] = 2*dp[i-1][0] + dp[i-1][1]`

-> Calculating number of towers of height i ending with two blocks of width 1
1. If tower i-1 ends with two tiles of with 1, we can:
	i)  either extend both blocks by height 1
	ii) extend left block by 1 and add block of 1x1 to the right tower
	iii) extend right block by 1 and add block of 1x1 to left tower
	iv) extend neither and add 1x1 blocks to both left and right tower

2. If tower i-1 end with a block of width 2, we can add 2 blocks of 1x1

Thus `dp[i][1] = 4*dp[i-1][1] + dp[i-1][0]`

```
dp[1][0] = 1;
dp[1][1] = 1;

for(int i = 2 ; i < N ; i++) {
	dp[i][0] = ((2*dp[i-1][0]) % MOD + dp[i-1][1]) % MOD;
	dp[i][1] = ((4*dp[i-1][1]) % MOD + dp[i-1][0]) % MOD;
}
```

Now each query can be answered in O(1) time.

Time complexity: O(N + T)

#### \#2 Matrix Exponentiation

![Matrix](/matrix.png)