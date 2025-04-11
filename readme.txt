I decided on a constant of 25 for the minimum size sort to apply the median of three technique.

Originally, my test cases involved completely randomized integers. I ran random tests that had runtimes upwards of 10 minutes, and could not find a consistent significant difference
between the median of three technique and regular quicksort.

Then, I tested the worst case scenario: data that was already sorted. I noticed a huge difference between regular quicksort and the median of three technique, and the differences were
noticeable even when using a list with as little as 25 integers. Using the time command on the command line showed that this consistently took about 20% more time for the regular
quicksort for a list of 25 integers.

It is worth noting that no difference was found with random data. This means that the overhead for using the MO3 technique was not significant. So, I decided to implement a constant of 25.
This way, the worst case scenario (already sorted data) would never take too long, and there would still be no noticeable performance decrease when MO3 is not necessary.
