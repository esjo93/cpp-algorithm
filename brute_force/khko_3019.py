rows, num_block= list(map(int, input().split(' ')))
assert rows<=100, "wrong inputs"
assert 1<=num_block<=7, "wrong inputs"

cnt_blocks=list(map(int, input().split(' ')))
cols=max(cnt_blocks)
matrix=[[ 1 if i<=cnt_block else 0 for j, cnt_block in enumerate(cnt_blocks)] for i in range(rows)]
print(matrix)

num_transform=[2, 1, 4, 4, 4, 4, 4]
for i in range(num_transform[num_block-1]):
