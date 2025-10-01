import matplotlib.pyplot as plt

n_values = [10, 20, 40, 60, 80, 100]
dp_times = [50, 180, 750, 2600, 4800, 8500]
greedy_times = [10, 20, 35, 55, 70, 95]

plt.figure(figsize=(9,5))
plt.plot(n_values, dp_times, marker='o', label='0/1 Knapsack (DP Top-Down)')
plt.plot(n_values, greedy_times, marker='s', label='Fractional Knapsack (Greedy)')
plt.xlabel('Number of Items (n)')
plt.ylabel('Execution Time (microseconds)')
plt.title('0/1 Knapsack (DP) vs Fractional Knapsack (Greedy)')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('knapsack_comparison.png', dpi=300)
plt.show()
