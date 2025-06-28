import sys
input = sys.stdin.readline

n = int(input())
A, B, C, D, E, F, = map(int, input().split())

three_face = [A+C+E, A+B+C, A+D+B, A+E+D, F+C+E, F+B+C, F+D+B, F+E+D]
two_face = [A+E, A+C, A+B, A+D, F+E, F+C, F+B, F+D, B+C, C+E, E+D, D+B]
one_face = [A, B, C, D, E, F]

three_face.sort()
two_face.sort()
one_face.sort()

least_sum = 0

if n == 1 :
    least_sum += A + B + C + D + E + F
    least_sum -= one_face[5]
else :
    least_sum += three_face[0] * 4
    least_sum += two_face[0] * (8 * n - 12)
    least_sum += one_face[0] * (5 * n * n - 16 * n + 12)

print(least_sum)

