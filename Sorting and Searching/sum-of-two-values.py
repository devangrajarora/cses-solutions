n, x = map(int,input().split())
a = list(map(int,input().split()))
dic, ok = {}, 0
for i,num in enumerate(a):
	if x-num in dic:
		print(dic[x-num],i+1)
		ok = 1
		break
	dic[num] = i+1 
if ok is 0:
	print("IMPOSSIBLE")