import matplotlib.pyplot as plt

n_values = [5, 10, 20, 25, 30, 35, 40]
recursive_times = [5, 10, 200, 1200, 13000, 150000, 1600000]
iterative_times = [1, 2, 3, 4, 5, 7, 9]
dp_topdown_times = [1, 2, 4, 5, 6, 7, 8]
dp_bottomup_times = [1, 2, 3, 4, 5, 6, 7]

plt.figure(figsize=(9,5))
plt.plot(n_values, recursive_times, marker='o', label='Recursive')
plt.plot(n_values, iterative_times, marker='s', label='Iterative')
plt.plot(n_values, dp_topdown_times, marker='^', label='DP Top-Down')
plt.plot(n_values, dp_bottomup_times, marker='d', label='DP Bottom-Up')
plt.xlabel('n')
plt.ylabel('Execution Time (microseconds)')
plt.title('Fibonacci Computation: Recursive vs Iterative vs DP')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('fibonacci_comparison.png', dpi=300)
plt.show()
