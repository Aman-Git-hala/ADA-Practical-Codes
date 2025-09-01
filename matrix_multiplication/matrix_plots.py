import matplotlib.pyplot as plt

sizes = [2, 4, 8, 16, 32, 64, 128]
iterative_times = [10, 70, 550, 4500, 38000, 310000, 2550000]
strassen_times = [15, 90, 600, 3200, 21000, 140000, 900000]

plt.figure(figsize=(8,5))
plt.plot(sizes, iterative_times, marker='o', label='Iterative Multiplication')
plt.plot(sizes, strassen_times, marker='s', label='Strassen Recursive')
plt.xlabel('Matrix Dimension (n)')
plt.ylabel('Execution Time (microseconds)')
plt.title('Matrix Multiplication: Strassen vs Iterative (n = 2^k)')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('matrix_strassen_comparison.png', dpi=300)
plt.show()
