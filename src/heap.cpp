#include "../header/heap.hpp"

Heap::Heap() {
    arr [0] =  nullptr ;     
    numItems = 0;
}

void Heap::enqueue ( PrintJob* JobNode ) {
  
    // if the heap is empty, insert JobNode to root and increment 
    if (this->numItems == 0) {
    
        this->arr[0] = JobNode;
        this->numItems++;
    }  
    // if heap is not full insert JobNode 
    else if(numItems < MAX_HEAP_SIZE) {

        // insert the JobNode to the end of the heapArray 
        arr[numItems] = JobNode; 
        // Insert Job without violating max heap properties
        this->trickleUP(numItems); 
        // increment number of items in the heap 
        numItems++;
    }

    // exit if the heap is full
    else {
        return; 
    }
}

void Heap::dequeue ( ) {
    // if the heap is empty, then exit 
    if(numItems < 1) {
        return;
    }

    // decrement the number of itemps in the heap 
    numItems--;

    // move the last JobNode to the root 
    this->arr[0] = this->arr[numItems]; 

    /* call the trickleDown function to set the root
       and keep the heap properties
    */  
    this->trickleDown(0);
}

PrintJob* Heap::highest ( ) {
    if(numItems < 1) {
        return nullptr;
    }
    
    return this->arr[0]; 
}

void Heap::print ( ) {
    // if the heap is empty do not print 
    if(this->numItems < 1) {
        return;
    }
    cout << "Priority: " << this->highest()->getPriority() << ", "; 
    cout << "Job Number: " << this->highest()->getJobNumber() << ", ";
    cout << "Number of Pages: " << this->highest()->getPages() << endl; 
}

void Heap::trickleDown(int index ) {
    int leftIndex ;                 // index Node left child node  
    int rightIndex ;                // index Node right child node 
    int childIndex = 2 * index + 1; // holds the child with higher priority
    PrintJob *temp;                 // used to swap values of the heap   

    // check priority of index node and its descendents 
    while(childIndex < numItems) {
        // get childen indices 
        leftIndex  = (2 * index) + 1;
        rightIndex = (2 * index) + 2;
   
        // select the max pariority child
        if(rightIndex < numItems) {
            if(arr[leftIndex]->getPriority() >= arr[rightIndex]->getPriority()) {
                childIndex = leftIndex; 
            } else {
                childIndex = rightIndex; 
            }
        } else {
            childIndex = leftIndex;   //no right child 
        }
        // if index Priority is higher then childen, return 
        if(arr[childIndex]->getPriority() <= arr[index]->getPriority()) {
            return;        
        } 
        // if childIndex priority is higher, swap with index node 
        else {
            temp = this->arr[index]; 
            this->arr[index] = this->arr[childIndex];
            this->arr[childIndex] = temp;

            // update the index and childIndex for the while loop 
            index = childIndex;           
            childIndex = (2 * index) + 1;
        }
    }
}

void Heap::trickleUP( int childIndex ) {
    while ( childIndex > 0) {     
        int parentIndex    = (childIndex - 1) / 2; 
        int parentPriority = this->arr[parentIndex]->getPriority();
        int childPriority  = this->arr[childIndex]->getPriority(); 

        if(parentPriority >= childPriority) {      
            return;   // do nothing  
        } else {
            // swap the child and the parent 
            PrintJob *temp = this->arr[parentIndex];
            this->arr[parentIndex] = this->arr[childIndex]; 
            this->arr[childIndex] = temp;
   
            // move the childIndex up the heap
            childIndex = parentIndex;   
        }
    } 
}