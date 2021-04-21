N = input()
row=int(N[1])
column=N[0]
# 8가지 경우의 수: 동(상하), 남, 서, 북 순서
drows=[1, -1, 2, 2, 1, -1, -2, -2, -2]
dcols=[2, 2, 1, -1, -2, -2, 1, -1]

locs=[row-1, ord(column)-97]
nlocs=[0, 0]
cnt=0
for drow, dcols in zip(drows, dcols):
    nlocs[0]=locs[0]+drow
    nlocs[1]=locs[1]+dcols
    if (0<=nlocs[0]<=8) and (0<=nlocs[1]<=8):
        cnt+=1
print(cnt)
