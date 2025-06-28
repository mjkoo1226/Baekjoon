import sys
input = sys.stdin.readline

n = int(input())

# 왼쪽, 오른쪽 자식 노드 정보 저장
left = {}
right = {}

# 모든 노드와 부모 노드 집합 생성
all_nodes = set(range(1, n + 1))
child_nodes = set()

for _ in range(n):
    node, l, r = map(int, input().split())
    left[node] = l
    right[node] = r
    if l != -1:
        child_nodes.add(l)
    if r != -1:
        child_nodes.add(r)

# 루트 노드 찾기: 자식 노드로 등장하지 않는 노드
root = list(all_nodes - child_nodes)[0]

# 최대 깊이 계산용 변수
coor = [[] for _ in range(n + 1)]
x = 1

# 중위 순회 함수
def inorder(node, y):
    global x
    if node == -1:
        return

    # 왼쪽 순회
    inorder(left[node], y + 1)

    # 현재 노드 처리
    coor[y].append(x)
    x += 1

    # 오른쪽 순회
    inorder(right[node], y + 1)

# 중위 순회 시작
inorder(root, 1)

# 최대 너비와 레벨 계산
max_width = 0
best_level = 0

for level in range(1, n + 1):
    if coor[level]:
        width = coor[level][-1] - coor[level][0] + 1
        if width > max_width:
            max_width = width
            best_level = level

print(best_level, max_width)