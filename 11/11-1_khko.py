N=int(input())  
fears=list(map(int, input(' ').split()))
assert len(fears)==N, 'wrong inputs'
cnt=0
for fear in set(fears):
    if fear <= fears.count(fear): cnt+=1
print(cnt)
