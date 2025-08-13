import matplotlib.pyplot as plt

sizes = [120000, 310000, 540000, 780000, 950000]
linear_times = [120, 320, 540, 790, 950]
binary_times = [5, 8, 10, 12, 14]

plt.figure(figsize=(8, 5))
plt.plot(sizes, linear_times, marker='o', label='Linear Search')
plt.plot(sizes, binary_times, marker='s', label='Binary Search')
plt.xlabel('Array Size (n)')
plt.ylabel('Execution Time (microseconds)')
plt.title('Linear Search vs Binary Search')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('search_times.png', dpi=300)
plt.show()
