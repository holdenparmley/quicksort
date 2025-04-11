The Hoare implementation was faster in nearly all cases. In challenging cases, such as duplicates, already sorted integers, and when every integer was the same,
the Hoare method was noticeably faster than the Lomuto method. With randomly distributed data, it took a large number of items (around 1,000,000) before I began
to notice a time difference between Hoare and Lomuto. For small datasets of randomly distributed data, Lomuto actually seemed to be slightly faster than Hoare, though
it might be within a margin of error. I suspect that, if there is a difference, it  is because it takes a small amount of time for the program to handle the command
line parameter "-h" and understand that it has to run the Hoare partition method, and that this time outweighs any time that Hoare saves for small datasets.

In terms of the number of operations done, Hoare had less operations in all test cases. For random data, the Hoare method involved 3x fewer swaps than the Lomuto
method. For 1000 already sorted integers, the Hoare method used only 2 swaps, while the Lomuto method used over 250,000; this was the most stark difference I found.
For 1000 integers that were all the same, the Hoare method used around 5000 swaps, and the Lomuto method used around 500000. Different test cases had different differences,
but the bottom line is that there were always less swaps for Hoare's method.
