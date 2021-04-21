N, M, K = map(int, input().split(' '))
data = list(map(int, input().split(' ')))

n1=max(data)
data.remove(n1)
n2=max(data)
total=[]
cnt=0
while len(total)!=M:
    if ((cnt%K)==0) and (cnt!=0):
        total.append(n2)
    else:
        total.append(n1)
    cnt+=1
print(sum(total))