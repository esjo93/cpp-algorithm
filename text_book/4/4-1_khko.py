N = int(input())
directions = list(input().split(' '))

# 동, 남, 서, 북
dx=[0 , 1, -0, -1]
dy=[1, 0, -1, 0]

locs=[0,0]
for direction in directions:

    if (direction=='R') and (locs[1]<N-1):
        locs[0]+=dx[0]
        locs[1]+=dy[0]
    elif (direction=='D') and (locs[0]<N-1):
        locs[0]+=dx[1]
        locs[1]+=dy[1]
    elif (direction=='L') and (locs[1]>0):
        locs[0]+=dx[2]
        locs[1]+=dy[2]
    elif (direction=='U') and (locs[0]>0):
        locs[0]+=dx[3]
        locs[1]+=dy[3]
    else:
        pass

for loc in locs:
    print(loc+1, end=' ')