# Abstact Data Types : Max Heap

Author: Mahdi Aouchiche (<https://github.com/mahdi-aouchiche/ADT_05_max_heap>)

* Example of implementing a max heap using an array.
* Create a node of a class PrintJob. The node data holds the following data:
  * Priority:  priority of the print job (job with higher priority prints first).
  * Job Number: holds the job ID number.
  * Number of Pages: the number of pages to print in the given job.  
* Implement enqueue function which adds a print job to the max heap. It uses a trickleUP helper function which moves the new job to the right location.
* Implement a dequeue function which removes the highest priority print job. It uses a trickleDown helper function which removes the root job and replaces it with the highest print job.
* Implement a print function which displays the data of the highest print job in the heap.
* Test the correcteness of the functions using standard output in main.
* Use google unit tests to automate the tests for each function.

## To run the project nicely run the following commands

```c++
cmake -S . -B build
cmake --build build/ 
```

## 2 executables are created, use the following commands to run an executable

```c++
// run the unit tests
./build/test_max_heap

// run the code
./build/max_heap
```
