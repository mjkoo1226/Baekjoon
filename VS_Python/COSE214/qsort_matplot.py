import random
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# ----- Randomized Quicksort 코드 -----

def swap(A, i, j):
    A[i], A[j] = A[j], A[i]

def Partition(A, p, r, states):
    x = A[r]
    i = p - 1
    for j in range(p, r):
        if A[j] <= x:
            i += 1
            swap(A, i, j)
            states.append(A.copy())
    swap(A, i + 1, r)
    states.append(A.copy())
    return i + 1
            
def Randomized_Partition(A, p, r, states):
    i = random.randrange(p, r + 1)
    swap(A, r, i)
    states.append(A.copy())
    return Partition(A, p, r, states)
    
def Randomized_Quicksort(A, p, r, states):
    if p < r:
        q = Randomized_Partition(A, p, r, states)
        Randomized_Quicksort(A, p, q - 1, states)
        Randomized_Quicksort(A, q + 1, r, states)

# ----- 시각화 -----

def animate_sort(A):
    states = [A.copy()]  # 정렬 중간 상태 저장

    Randomized_Quicksort(A, 0, len(A) - 1, states)

    fig, ax = plt.subplots()
    bar_rects = ax.bar(range(len(A)), states[0], align="edge")

    ax.set_xlim(0, len(A))
    ax.set_ylim(0, int(max(A) * 1.1))
    ax.set_title("Randomized Quicksort Visualization")

    def update(frame):
        for rect, val in zip(bar_rects, states[frame]):
            rect.set_height(val)

    anim = animation.FuncAnimation(fig, update, frames=len(states), interval=300, repeat=False)
    plt.show()

# ----- 실행 예시 -----

array = [random.randint(1, 100) for _ in range(20)]  # 1~100 사이 랜덤한 수 20개
animate_sort(array)
