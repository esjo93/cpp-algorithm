num_str=input('')
result=0
for num in num_str:
    num=int(num)
    if num==0 or num==1 or result==0:
        result+=num
    else:
        result*=num
print(result)