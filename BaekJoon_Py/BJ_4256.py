import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)

testcase = int(input())

for _ in range(testcase):
    n = int(input())
    preorder = list(map(int, input().split()))
    inorder = list(map(int, input().split()))

    inorder_map = {}
    for idx in range(n):
        inorder_map[inorder[idx]] = idx

    result = []

    def make_postorder(in_start, in_end, pre_start, pre_end):
        if in_start > in_end or pre_start > pre_end:
            return

        root = preorder[pre_start]
        idx = inorder_map[root]
        left_size = idx - in_start

        make_postorder(in_start, idx - 1, pre_start + 1, pre_start + left_size)
        make_postorder(idx + 1, in_end, pre_start + left_size + 1, pre_end)

        result.append(str(root))

    make_postorder(0, n - 1, 0, n - 1)

    sys.stdout.write(" ".join(result) + "\n")
