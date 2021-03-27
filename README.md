# Hello PureWeb

In this directory you'll find my simple shuffle solution for your technical assessment.

> "Using the language of your choice, implement the following program named Shuffle:<br>
  > Input a single integer N.<br>
  > Output the integers 1..N in random order.<br>
  > Optimize for speed."

## Running the solution

I've included a command line executable in the bin folder

### BUT

If for whatever reason that doesn't work, you can build an executable from the source code `src/shuffle.cpp` using this command (provided you have a c++ compiler installed)

    g++ src/shuffle.cpp -o Shuffle -Wall -std=c++17

## Assumptions and considerations made

- N is between 1 and INT_MAX
- To be more efficient, some modularity was removed. (Initially, the shuffling and printing was done separately, but to save an iteration of the array the printing was done at the time of shuffling).
  - Ideally the shuffle algorithm would be templated to work on all std containers as well, but I figured that was beyond the scope of the assessment. (I could just explain that here!)
- I changed from cout to printf to print the values to get a bit more speed.
- I seeded rand() with the std::random_device instead of generating random numbers with it since this application doesn't require 'true' randomness.

## Algorithm (simple) explanation

1. Generate an array A of size N, from 1 -> N.
2. Iterate backwards through A, swapping A[i] with another random element A[j], where 0 <= j < i, and printing immediately.

I generate the array to quickly/easily ensure the whole range is present, and printing immediately then decreasing the range for elements to swap at each step ensures that: I save an unnecessary iteration of the array in computation, and prevent duplicate prints by not swapping future elements I've already printed.

## Future possible improvements

- I believe that given an N of significant size, that the algorithm could be sped up by using a divide and conquer approach to the shuffling.
  - At the time of this assessment I didn't put together a sufficient algorithm for merging the subarrays in a way that would produce enough randomness.
