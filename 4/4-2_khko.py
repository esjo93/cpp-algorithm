N = int(input())
H, M, S=0, 0, 0
cnt=0
while N+1!=H:
    
    if S==60:
        S=0
        M+=1
    elif M==60:
        M=0
        H+=1
    else:
        pass
    S+=1
    if ('3' in str(H)) or ('3' in str(M)) or ('3' in str(S)):
        cnt+=1
print(cnt)
