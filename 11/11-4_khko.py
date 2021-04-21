N=int(input())  
coins=sorted(list(map(int, input(' ').split())))
assert len(coins)==N, 'wrong inputs'
cnt=0
num=0
flag=True
while flag:
    cnt+=1
    num+=1
    flag=False
    for i, coin in enumerate(coins):
        if i+num < N:
            if sum(coins[i:i+num]) == cnt: 
                print('in the middle')
                flag=True
    
    if num==N: 
        print('at the end')
        flag=False
print(cnt)
