#ifndef __UNIT_TEST_HPP__
#define __UNIT_TEST_HPP__

#include "gtest/gtest.h"
#include "../src/heap.cpp"
#include "../src/print_job.cpp"


PrintJob job_1( 1 , 1001 , 10);
PrintJob job_2( 2 , 1002 , 20);
PrintJob job_3( 3 , 1003 , 30);

TEST(PRINT_JOB, get_priority_test) {  
    EXPECT_EQ(job_1.getPriority(), 1 );
    EXPECT_NE(job_2.getPriority(), 1);
}

TEST(PRINT_JOB, get_job_number_test) {
    EXPECT_EQ(job_1.getJobNumber(), 1001);
    EXPECT_NE(job_2.getJobNumber(), 1001);
}

TEST(PRINT_JOB, get_pages_test) {
    EXPECT_EQ(job_1.getPages(), 10);
    EXPECT_NE(job_2.getPages(), 10);
}

TEST(MAX_HEAP, highest_test) {
    Heap max_heap;
    EXPECT_EQ( max_heap.highest(), nullptr);

    max_heap.enqueue(&job_1);
    EXPECT_EQ(max_heap.highest()->getPriority(), 1);

    max_heap.enqueue(&job_2);
    EXPECT_EQ(max_heap.highest()->getPriority(), 2);
}

TEST(MAX_HEAP, enqueue_dequeue_tests) {
    Heap max_heap;

    max_heap.enqueue(&job_1);
    max_heap.enqueue(&job_2);
    max_heap.enqueue(&job_3);
    EXPECT_EQ(max_heap.highest()->getPriority(), 3);

    max_heap.dequeue();
    EXPECT_EQ(max_heap.highest()->getPriority(), 2);

    max_heap.dequeue();
    EXPECT_EQ(max_heap.highest()->getPriority(), 1);

    max_heap.dequeue();
    EXPECT_EQ(max_heap.highest(), nullptr);
}

#endif  // __UNIT_TEST_HPP__