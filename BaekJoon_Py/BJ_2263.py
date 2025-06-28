import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000000)

n = int(input())
inorder = list(map(int, input().split()))
postorder = list(map(int, input().split()))
preorder = []

inorder_map = {}
for idx in range(len(inorder)):
    inorder_map[inorder[idx]] = idx

def make_preorder(in_start, in_end, post_start, post_end):
    if in_start > in_end or post_start > post_end:
        return

    root = postorder[post_end]
    preorder.append(root)

    idx = inorder_map[root]
    left_size = idx - in_start

    make_preorder(in_start, idx - 1, post_start, post_start + left_size - 1)
    make_preorder(idx + 1, in_end, post_start + left_size, post_end - 1)

make_preorder(0, n - 1, 0, n - 1)
print(*preorder)