#ifndef __PRINTJOB_HPP__
#define __PRINTJOB_HPP__

class PrintJob {
  private:
    int priority;
    int jobNumber;
    int numPages;

  public:
    PrintJob ( int, int, int);
    ~PrintJob();
    int getPriority ( );
    int getJobNumber ( );
    int getPages ( );
    /*You can add additional functions here */
};

#endif  // __PRINTJOB_HPP__