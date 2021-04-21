N, M = list(map(int, input().split(' ')))
l=[]
for _ in range(N):
    l.append(min(list(map(int, input().split(' ')))))
print(max(l))