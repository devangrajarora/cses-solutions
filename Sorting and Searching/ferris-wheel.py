n, x = map(int, input().split())
weight = list(map(int, input().split()))
weight.sort()
i, j, ans = 0, len(weight)-1, 0
while(i <= j):
	if i != j and weight[i] + weight[j] <= x:
		i += 1
	j -= 1 
	ans += 1
print(ans)