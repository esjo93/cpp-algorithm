rows, num_block = list(map(int, input().split(' ')))
assert rows <= 100, "wrong inputs"
assert 1 <= num_block <= 7, "wrong inputs"

cnt_blocks = list(map(int, input().split(' ')))

cnt = 0
if num_block == 1:
    for i in range(2):
        # first case
        if i == 0:
            for j in range(len(cnt_blocks)):
                cnt += 1
        # second cse
        else:
            for j in range(len(cnt_blocks)-4+1):
                if len(set(cnt_blocks[j:j+4])) == 1:
                    cnt += 1
elif num_block == 2:
    for i in range(len(cnt_blocks)-2+1):
        if len(set(cnt_blocks[i:i+2])) == 1:
            cnt += 1
elif num_block == 3:
    for i in range(2):
        # first case
        if i == 0:
            for j in range(len(cnt_blocks)-3+1):
                if (len(set(cnt_blocks[j:j+2])) == 1) and (cnt_blocks[j+1]+1 == cnt_blocks[j+2]):
                    cnt += 1
        # second case
        elif i == 1:
            for j in range(len(cnt_blocks)-2+1):
                if cnt_blocks[j] == cnt_blocks[j+1]+1:
                    cnt += 1
elif num_block == 4:
    for i in range(2):
        # first case
        if i == 0:
            for j in range(len(cnt_blocks)-3+1):
                if (len(set(cnt_blocks[j+1:j+3])) == 1) and (cnt_blocks[j] == cnt_blocks[j+1]+1):
                    cnt += 1
        # second case
        else:
            for j in range(len(cnt_blocks)-2+1):
                if cnt_blocks[j]+1 == cnt_blocks[j+1]:
                    cnt += 1
elif num_block == 5:
    for i in range(4):
        # first case
        if i == 0:
            for j in range(len(cnt_blocks)-3+1):
                if len(set(cnt_blocks[j:j+3])) == 1:
                    cnt += 1
        # second case
        elif i == 1:
            for j in range(len(cnt_blocks)-2+1):
                if cnt_blocks[j] == cnt_blocks[j+1]+1:
                    cnt += 1
        # third case
        elif i == 2:
            for j in range(len(cnt_blocks)-3+1):
                if (cnt_blocks[j] == cnt_blocks[j+2]) and (cnt_blocks[j] == cnt_blocks[j+1]+1):
                    cnt += 1
        # fourth case
        else:
            for j in range(len(cnt_blocks)-2+1):
                if cnt_blocks[j]+1 == cnt_blocks[j+1]:
                    cnt += 1
elif num_block == 6:
    for i in range(4):
        # first case
        if i == 0:
            for j in range(len(cnt_blocks)-3+1):
                if len(set(cnt_blocks[j:j+3])) == 1:
                    cnt += 1
        # second case
        elif i == 1:
            for j in range(len(cnt_blocks)-2+1):
                if cnt_blocks[j] == cnt_blocks[j+1]:
                    cnt += 1
        # third case
        elif i == 2:
            for j in range(len(cnt_blocks)-3+1):
                if (cnt_blocks[j+1] == cnt_blocks[j+2]) and (cnt_blocks[j]+1 == cnt_blocks[j+1]):
                    cnt += 1
        # fourth case
        else:
            for j in range(len(cnt_blocks)-2+1):
                if cnt_blocks[j] == cnt_blocks[j+1]+2:
                    cnt += 1
else:
    for i in range(4):
        # first case
        if i == 0:
            for j in range(len(cnt_blocks)-3+1):
                if len(set(cnt_blocks[j:j+3])) == 1:
                    cnt += 1
        # second case
        elif i == 1:
            for j in range(len(cnt_blocks)-2+1):
                if cnt_blocks[j]+2 == cnt_blocks[j+1]:
                    cnt += 1

        # third case
        elif i == 2:
            for j in range(len(cnt_blocks)-3+1):
                if (cnt_blocks[j] == cnt_blocks[j+1]) and (cnt_blocks[j] == cnt_blocks[j+2]+1):
                    cnt += 1
        # fourth case
        else:
            for j in range(len(cnt_blocks)-2+1):
                if cnt_blocks[j] == cnt_blocks[j+1]:
                    cnt += 1
print(cnt)
