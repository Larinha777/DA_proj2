import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import csv
from collections import defaultdict
import statistics
import numpy as np

# Prepare to group by (algorithm, x)
grouped_points = defaultdict(list)
accuracies = []

try:
    with open('../benchmarks/bmarks.csv', 'r') as file:
        reader = csv.reader(file)
        i = 0

        acc_file = open("../benchmarks/approximation_accuracy.txt", "w")
        for row in reader:
            i += 1

            algorithm = row[0]
            y_value = float(row[2])
            x_value = float(row[3])

            # collect optimal/profit pairs
            if i % 5 == 3:
                optimal = int(row[1])
            if i % 5 == 4:
                ap = int(row[1])
                truck, pallets = row[4], row[5]
                acc_file.write(
                    f"Truck: {truck}\n"
                    f"Pallets: {pallets}\n"
                    f"Optimal Profit: {optimal}\n"
                    f"Approximation Profit: {ap}\n"
                    f"{(ap/optimal)*100:.2f}% accurate\n\n"
                )
            if x_value == -1 or y_value == -1:
                continue  # Skip invalid data points

            grouped_points[(algorithm, x_value)].append(y_value)
        acc_file.close()

except FileNotFoundError:
    print("Error: File 'bmarks.csv' not found.")
    exit(1)
except Exception as e:
    print(f"Error reading CSV file: {e}")
    exit(1)

if not grouped_points:
    print("No valid data found in the CSV file.")
    exit(1)

# Create a scatter plot
plt.figure(figsize=(10, 6))
color_map = {
    'Brute-Force': 'blue',
    'Backtracking': 'red',
    'Dynamic': 'green',
    'Approximate': 'purple',
    'ILP': 'orange'
}

# Reorganize data by algorithm
alg_data = defaultdict(lambda: {'x': [], 'y': []})

plt.yscale('log')
plt.xscale('log')

for (algorithm, x), y_list in grouped_points.items():
    avg_y = statistics.mean(y_list)
    color = color_map.get(algorithm, 'black')
    plt.scatter(x, avg_y, color=color, s=25)  # Individual point
    alg_data[algorithm]['x'].append(x)
    alg_data[algorithm]['y'].append(avg_y)

# Sort and connect points per algorithm
for algorithm, data in alg_data.items():
    x = np.array(data['x'])
    y = np.array(data['y'])
    color = color_map.get(algorithm, 'black')

    # Sort points by x for proper line plotting
    sorted_indices = np.argsort(x)
    x_sorted = x[sorted_indices]
    y_sorted = y[sorted_indices]

    plt.plot(x_sorted, y_sorted, color=color, linewidth=1)

# Axis limits
x_values = [val for sub in [v['x'] for v in alg_data.values()] for val in sub]
y_values = [val for sub in [v['y'] for v in alg_data.values()] for val in sub]
min_x = min(filter(lambda v: v > 0, x_values))
min_y = min(filter(lambda v: v > 0, y_values))
max_x = max(x_values)
max_y = max(y_values)

plt.xlim(min_x * 0.9, max_x * 1.1)
plt.ylim(min_y * 0.9, max_y * 1.1)

# Labels and title
plt.xlabel('Number of Pallets')
plt.ylabel('Runtime (seconds)')
plt.title('0/1 Knapsack Algorithm Comparison')
plt.grid(False)

# Static legend
legend_patches = [
    mpatches.Patch(color='blue', label='Brute Force'),
    mpatches.Patch(color='red', label='Backtracking'),
    mpatches.Patch(color='green', label='DP'),
    mpatches.Patch(color='purple', label='Approximation'),
    mpatches.Patch(color='orange', label='ILP')
]
plt.legend(handles=legend_patches)

# Save the plot
plt.savefig('../benchmarks/algorithm_comparison.png', dpi=300, bbox_inches='tight')
# plt.show()