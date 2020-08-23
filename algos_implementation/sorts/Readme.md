## Implementation of Various Sorting Algorithms
- Selection Sort
- Merge Sort
- Heap Sort
- Quick Sort

### To Run

```bash
g++ *.h *.cpp && ./a.out
```

Expected Input: 

- **n** denoting the number of integers to be sorted. 
- Followed by the list of integers (space seperated or one on each line)

### Benchmarks

- ~~Why is quick sort as slow as selection sort? (See Large Inputs)~~
- **Quick Sort: Always implement randomized quick sort.**

#### Size of array: 10 (Averaged over 1000 runs)

- Merge Sort: 0.000520125 milli seconds
- Heap Sort: 0.000387505 milli seconds
- Randomized Quick Sort: 0.000286057 milli seconds
- Inbuilt Sort: 0.000159212 milli seconds
- Selection Sort: 0.000205781 milli seconds



#### Size of array: 100 (Averaged over 1000 runs)

- Merge Sort: 0.000520125 milli seconds
- Heap Sort: 0.000387505 milli seconds
- Randomized Quick Sort: 0.000286057 milli seconds
- Inbuilt Sort: 0.000159212 milli seconds
- Selection Sort: 0.000205781 milli seconds


#### Size of array: 1000 (Averaged over 1000 runs)

- Merge Sort: 0.0799004 milli seconds
- Heap Sort: 0.117189 milli seconds
- Randomized Quick Sort: 0.0624245 milli seconds
- Inbuilt Sort: 0.0399227 milli seconds
- Selection Sort: 1.06984 milli seconds

#### Size of array: 10000 (Averaged over 100 runs)

- Merge Sort: 0.991509 milli seconds
- Heap Sort: 1.63837 milli seconds
- Randomized Quick Sort: 0.794372 milli seconds
- Inbuilt Sort: 0.57726 milli seconds
- Selection Sort: 103.746 milli seconds

#### Size of array: 100000 (Averaged over 10 runs)

- Merge Sort: 12.3158 milli seconds
- Heap Sort: 20.865 milli seconds
- Randomized Quick Sort: 10.1164 milli seconds
- Inbuilt Sort: 7.57082 milli seconds
- Selection Sort: 10558.2 milli seconds

