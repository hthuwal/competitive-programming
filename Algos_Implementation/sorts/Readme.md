## Implementation of Various Sorting Algorithms
- Selection Sort
- Merge Sort
- Heap Sort
- Quick Sort

### Benchmarks

- Why is quick sort as slow as selection sort? (See Large Inputs)
- I am pretty sure my implementations of each of the algorithm is right.
    + Even tried the gfg implementation (same as mine just to be sure)
    + Quick sort is still pretty damn slow.

**Size of array: 10**

- Merge Sort: 0.00381125 milli seconds
- Heap Sort: 0.00336795 milli seconds
- Quick Sort: 0.00202444 milli seconds
- Inbuilt Sort: 0.00108685 milli seconds
- Selection Sort: 0.00207425 milli seconds

**Size of array: 100**

- Merge Sort: 0.0216348 milli seconds
- Heap Sort: 0.0266459 milli seconds
- Quick Sort: 0.0309787 milli seconds
- Inbuilt Sort: 0.00909785 milli seconds
- Selection Sort: 0.0299537 milli seconds

**Size of array: 1000**

- Merge Sort: 0.291076 milli seconds
- Heap Sort: 0.341214 milli seconds
- Quick Sort: 1.85185 milli seconds
- Inbuilt Sort: 0.0823451 milli seconds
- Selection Sort: 1.78685 milli seconds

**Size of array: 10000**

- Merge Sort: 5.78217 milli seconds
- Heap Sort: 4.76385 milli seconds
- Quick Sort: 162.094 milli seconds
- Inbuilt Sort: 1.38744 milli seconds
- Selection Sort: 180.742 milli seconds
