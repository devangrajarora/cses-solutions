n, q = map(int,input().split())
nums = list(map(int,input().split()))
 
pos = [0 for _ in range(n+2)]
 
for i, num in enumerate(nums):
	pos[num] = i 

ans = 1
for i in range(2,n+1):
	if pos[i] < pos[i-1]:
		ans += 1
		
for query in range(q):
 
	a, b = map(int,input().split())
	a -= 1
	b -= 1

	if a == b:
		print(ans)
		continue

	num1, num2 = min(nums[a],nums[b]), max(nums[a],nums[b])

	if pos[num1] < pos[num1-1]:
		ans -= 1
	if pos[num1] > pos[num1+1]:
		ans -= 1
	if num2-num1 != 1 and pos[num2] < pos[num2-1]:
		ans -= 1
	if pos[num2] > pos[num2+1]:
		ans -= 1

	pos[nums[a]], pos[nums[b]] = pos[nums[b]], pos[nums[a]]
	nums[a], nums[b] = nums[b], nums[a]
 
	if pos[num1] < pos[num1-1]:
		ans += 1
	if pos[num1] > pos[num1+1]:
		ans += 1
	if num2-num1 != 1 and pos[num2] < pos[num2-1]:
		ans += 1
	if pos[num2] > pos[num2+1]:
		ans += 1
	
	print(ans)