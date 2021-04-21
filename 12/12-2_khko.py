ls = list(input())
l_strs=[]
l_nums=[]
flag=False
for l in ls:
    for i in range(10):
        if l==str(i):
            flag=True
            break
    if flag:
        l_nums.append(int(l))
    else:
        l_strs.append(l)
    flag=False
print(''.join(sorted(l_strs))+str(sum(l_nums)))
