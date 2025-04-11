# Delivery Truck Pallet Packing Optimization

## Objectives
Delivery Truck Pallet Packing Optimization Problem, a real-world variation of the 0/1 knapsack Problem (0/1 KP). 
The goal is to optimize the packing of pallets in a delivery truck to maximize profit while respecting the truck’s maximum weight
capacity. 

## Problem Motivation
In logistics and supply chain management, efficiently packing delivery trucks is a critical challenge.
Companies must maximize the value of each shipment while adhering to weight restrictions. This problem
can be modeled as a 0/1 Knapsack Problem, where:

 - A Truck represents the knapsack.
 - Pallets represent the items, each with a specific weight and profit (based on the value of the goods).
 - The goal is to select a subset of pallets that maximizes the total profit without exceeding the truck's
weight capacity.


Different algorithmic approaches:
 - exhaustive search
 - dynamic programming
 - approximation
 - linear integer programming algorithms


### Problem Statement and Organization of Work
#### Basic Application Definition and Set-Up
[T1.1: 1.0 point] Command-line menu that allows users to:
- select the dataset, 
- choose the algorithmic approach, 
- view the results. 
- showcases the work you have developed in a short demo at the end of the project.

[T1.2: 0.5 point] Read and Parse the provided data set files. Store the data in appropriate data
structures (e.g., arrays, lists, …) for use in your algorithms.

[T1.3: 1.5 points] Documentation and Time and Space Complexity Analysis.

[T2.1: 3.0 points] Exhaustive (Brute-Force) Approach:
 - Implement a brute-force algorithm that explores all possible subsets of pallets to find the optimal
solution.
 - Analyze the performance of this approach and observe its limitations, particularly for larger datasets.
 - Optionally, implement a backtracking algorithmic approach to the 0/1 KP and to try to improve
efficiency.

[T2.2: 4.0 points] Dynamic Programming Approach:
 - Implement a dynamic programming solution and pay special attention to the data structure used to
store the dynamic programming table, as it can become very large for bigger datasets.
 - Evaluate different data structure alternatives (e.g., arrays, hash maps) and consider implementing a
custom solution if necessary.
-  Analyze the performance of this approach and observe its limitations.

[T2.3: 4.0 points] Approximation Algorithms (Greedy Approach):
 - Implement the greedy algorithm studied in class that selects pallets based on their weight-to-profit
ratio, where the last pallet might not be included as one cannot consider a fraction of a pallet.
 - Compare the accuracy and performance of this approximation algorithm with the optimal solutions
obtained from the exhaustive and dynamic programming approaches (using only small datasets).
 - Evaluate the performance and fidelity of the greedy algorithm in the small and large data sets.
 - Remember that this problem is not the Fractional Knapsack Problem.

[T2.4: 2.0 points] Integer Linear Programming Algorithm (ILP):
 - This task will require some critical thinking and analysis skills. You should develop and analyse your
own ILP approach to the 0/1KP.
 - You should mathematically formulate the 0/1KP properly as an ILP.
 - As an alternative to ILP you are free to pursue other algorithmic approaches such as Genetic
Algorithms or a Hybrid Algorithmic approach specifically suited to selected input datasets.
 -  Critically discuss your justification for the algorithms implemented.

[T3.1: 2.0 points] Evaluate and Compare Algorithms
Test your implementations on the provided datasets.
 - Measure and report the run time execution for each algorithm and dataset. You should perform a
graphical representation of the different times obtained.
 - Compare the space complexity of the different solutions.
 - Compare the accuracy of the different solutions (i.e., how close the greedy algorithm's solution is to
the optimal solution).