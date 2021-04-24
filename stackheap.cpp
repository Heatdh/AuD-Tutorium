#include <iostream>
int main()
{

    int *ptr = new int;
    *ptr = 6;
    int stp = 5;
    int b[10];
    std::cout << *ptr << '\n';
    std::cout << ptr;

    // why is it important ?

    /* Parameter	                                  STACK	                                    HEAP
Basic	                             Memory is allocated in a contiguous block.	    Memory is allocated in any random order.
Allocation and Deallocation	        Automatic by compiler instructions.	                Manual by the programmer.
Cost	                                         Less	                                            More
Implementation	                                 Easy	                                            Hard
Accesstime	                                     Faster	                                            Slower
Main Issue	                                Shortage of memory	                            Memory fragmentation
Locality of reference	                        Excellent	                                        Adequate
Flexibility	                                    Fixed-size	                                Resizing is possible
Data type structure	                            Linear	                                        Hierarchical */
}