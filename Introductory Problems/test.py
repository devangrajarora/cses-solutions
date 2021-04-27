fo = open("output.txt",'r')
a = fo.readlines()
ans = 0
for s in a:
	if s == "7 7":
		ans += 1
print(ans)