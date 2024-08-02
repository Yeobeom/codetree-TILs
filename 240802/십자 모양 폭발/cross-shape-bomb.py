n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
r,c = map(int, input().split())
r -= 1
c -= 1
temp = []

# 폭탄의 크기
count = arr[r][c] - 1

# 십자 모양으로 폭탄 터트리기
for i in range(max(0, r-count), min(n, r+count+1)):
    arr[i][c] = 0
for j in range(max(0, c-count), min(n, c+count+1)):
    arr[r][j] = 0

for col in range(n):
    for row in range(n-1, -1, -1):
        if arr[row][col] != 0:
            temp.append(arr[row][col])
            
    for row in range(n-1, -1, -1):
        if temp:
            arr[row][col] = temp.pop(0)
        else:
            arr[row][col] = 0

# 결과 출력
for row in arr:
    print(' '.join(map(str, row)))