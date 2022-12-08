/*Given in Lab5*/
#include <iostream>
#include "../header/heap.hpp"

using namespace std;

int menu(); 

int main(){
    Heap max_heap;

    int choice = menu();

    while (choice != 4) {
        switch (choice) {
            case 1:
            {
                int priority, jobNumber, numPages;
                cout << "Enter print job to enqueue:" << endl;
                cout << " - Priority: ";
                cin>>priority;
                cout << " - Job number: ";
                cin>>jobNumber;
                cout << " - Number of pages: ";
                cin>>numPages;
                cout << endl;
                max_heap.enqueue(new PrintJob(priority, jobNumber, numPages));
                break;
            }
            case 2:
            {
                cout << "Display first job to print -> ";
                max_heap.print();
                break;
            }      
            case 3:
            {
                cout << "Printing first job canceled." << endl;
                max_heap.dequeue();
                break;
            }
        }
        
        //fix buffer just in case non-numeric choice entered
        choice = menu();

        // if (choice == 1) {
        //     int priority, jobNumber, numPages;
        //     cout << "Enter print job to enqueue (priority, job Number, number of pages): ";
        //     cin>>priority>>jobNumber>>numPages;
        //     cout << endl;

        //     max_heap.enqueue(new PrintJob(priority, jobNumber, numPages));
        // } else if (choice == 2) {
        //     max_heap.print();
        // } else if (choice == 3) {
        //     max_heap.dequeue();
        // } 
        // //fix buffer just in case non-numeric choice entered
        // choice = menu();
    }
    return 0;
}

int menu() {
    int choice = 0;
    cout << endl << "Menu options: ";
    cout << endl;
    cout << " -1. Enqueue" << endl
         << " -2. Print" << endl
         << " -3. Dequeue" << endl
         << " -4. Quit" << endl;
    cout << "Enter menu choice: ";
    cin >> choice;
    cout << endl;

    // fix buffer just in case non-numeric choice entered
    // also gets rid of newline character
    cin.clear();
    cin.ignore(256, '\n');
    return choice;
}