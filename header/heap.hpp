#ifndef __HEAP_HPP__
#define __HEAP_HPP__

#include <iostream> 
using namespace std; 
#include "print_job.hpp"

const int MAX_HEAP_SIZE = 10;

class Heap {
  private:
   // Notice this is an array of PrintJob pointers
   PrintJob* arr[MAX_HEAP_SIZE];

   //current number of items in heap  
   int numItems;  

  public:
   /* Initializes an empty heap. */
   Heap();

   /* Inserts a PrintJob to the heap without
      violating max-heap properties.
   */
   void enqueue ( PrintJob* );

   /* Removes the node with highest priority from the heap. 
      Follow the algorithm on priority-queue slides.
   */
   void dequeue ( );

   /* Returns the node with highest priority. */
   PrintJob* highest ( );

   /* Prints the PrintJob with highest priority in the
      following format:
      Priority: priority, Job Number: jobNum, Number of Pages: numPages
      (Add a new line at the end.)
   */
   void print ( );

  private:
   /* This function is called by dequeue function
      to move the new root down the heap to the 
      appropriare location.
   */
   void trickleDown(int);
    
   /* This function is called by dequeue function
      to move the new job node up the heap to the appropriate
      location to avoid violating max heap properties
   */
   void trickleUP(int);
};

#endif   // __HEAP_HPP__
