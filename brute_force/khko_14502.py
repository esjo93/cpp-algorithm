# matrix of simulation and directions of list(right, down, left, up)
def count_areas(matrix, directions):
    # trick for while loop
    before_virus=0
    after_virus=1
    while before_virus!=after_virus:
        # count the safety
        before_virus=sum(i.count(0) for i in matrix)
        # moving the virus
        for i, row in enumerate(matrix):
            for j, element in enumerate(row):
                if element==2:
                    dr=j+directions[0][0]
                    dd=i+directions[1][0]
                    dl=j+directions[2][0]
                    du=i+directions[3][0]
                    # right
                    if j+directions[0][1]<=len(matrix):
                        if (matrix[i+directions[0][0]][j+directions[0][1]] != 1) and (matrix[i+directions[0][0]][j+directions[0][1]] != 2):
                            matrix[i+directions[0][0]][j+directions[0][1]]=2
                    # down
                    if i+directions[1][0]<=len(matrix[0]):
                        if (matrix[i+directions[1][0]][j+directions[1][1]] != 1) and (matrix[i+directions[1][0]][j+directions[1][1]] != 2):
                            matrix[i+directions[1][0]][j+directions[1][1]]=2
                    # left
                    if j+directions[2][1]>=0:
                        if (matrix[i+directions[2][0]][j+directions[2][1]] != 1) and (matrix[i+directions[2][0]][j+directions[2][1]] != 2):
                            matrix[i+directions[2][0]][j+directions[2][1]]=2
                    # up 
                    if i+directions[3][0]>=0:
                        if (matrix[i+directions[3][0]][j+directions[3][1]] != 1) and (matrix[i+directions[3][0]][j+directions[3][1]] != 2):
                            matrix[i+directions[3][0]][j+directions[3][1]]=2
        after_virus=sum(i.count(0) for i in matrix)
    return after_virus

if __name__=="__main__":
    

    m, n = list(map(int, input().split(' ')))
    matrix=[]
    for i in range(m):
        matrix.append(list(map(int, input().split(' '))))
        assert len(matrix[i])==n, 'The # of column is not equal to inputs'
    assert len(matrix)==m, 'The # of row is not equal to inputs'

    zero_xys=[]
    one_xys=[]
    two_xys=[]
    for i, row in enumerate(matrix):
        for j, element in enumerate(row):
            if element==0:
                zero_xys.append((i, j))
            elif element==1:
                one_xys.append((i, j))
            elif element==2:
                two_xys.append((i, j))
            else:
                print('Wrong inputs, not 0, 1 or 2')
                raise ValueError

    cnts=[]
    # directions of right, down, left, up
    directions=[(0 ,1), (1, 0), (0, -1), (-1, 0)]

    for i, zero_xy_1 in enumerate(zero_xys):
        for j, zero_xy_2 in enumerate(zero_xys):
            for k, zero_xy_3 in enumerate(zero_xys):
                    if (zero_xy_1 != zero_xy_2) and (zero_xy_3 != zero_xy_1) and (zero_xy_3 != zero_xy_2):
                        matrix_cp=matrix.copy()
                        matrix_cp[zero_xy_1[0]][zero_xy_1[1]]=1
                        matrix_cp[zero_xy_2[0]][zero_xy_2[1]]=1
                        matrix_cp[zero_xy_3[0]][zero_xy_3[1]]=1

                        cnts.append(count_areas(matrix_cp, directions))

    print(max(cnts))

