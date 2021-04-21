nums=input()
zero_chunk=0
one_chunk=0
for i, num in enumerate(nums):
    num=int(num)
    if i==0 and num==0:
        zero_chunk+=1
        one_flag=False
    elif i==0 and num==1:
        one_chunk+=1
        one_flag=True
    else:
        pass

    if num==0 and one_flag==True:
        zero_chunk+=1
        one_flag=False
    elif num==1 and one_flag==False:
        one_chunk+=1
        one_flag=True
    else:
        pass
print(min(zero_chunk, one_chunk))