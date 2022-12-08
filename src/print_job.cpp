#include "../header/print_job.hpp"

PrintJob::PrintJob ( int setP, int setJ, int numP )
  :priority(setP), jobNumber(setJ), numPages(numP)  {}

PrintJob::~PrintJob() {}

int PrintJob::getPriority ( ){
  return priority;
}

int PrintJob::getJobNumber ( ){
  return jobNumber;
}

int PrintJob::getPages ( ){
  return numPages;
}