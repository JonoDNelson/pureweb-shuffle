/* A simple program to print out the numbers from 1 to n in a random order */
#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <stdio.h>

// Shuffle the array
// Algorithm:
// Swap each element of index i with a randomly selected element of index j within the array,
// where j < i
void shuffleAndPrintVector(std::vector<int> &vec) {
  std::random_device rd;
  srand(rd());

  std::cout << std::endl;
  for(size_t i = vec.size() - 1; i > 0; --i) {
    std::swap(vec[i], vec[rand() % i]);
    printf("%d\n", vec[i]);
  }
  printf("%d\n", vec[0]);
}

// Get integer value (greater than 1) from cin
int askForInt() {
  int n = 0;

  do {
    std::cout << "\nEnter an integer value greater than 1.\n" \
    "Values greater than " << INT_MAX << " will be treated as " << INT_MAX << ".\n";
    std::cin >> n;
    if(std::cin.fail())
      {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      }
    }while(!std::cin.good() || n < 1);

    return n;
}

// Generate an int vector from 1 to n
std::vector<int> ascendingIntVector(int n) {
  std::vector<int> vec(n);
  std::iota(vec.begin(), vec.end(), 1);

  return vec;
}

int main() {
  int n = askForInt();
  std::vector<int> a = ascendingIntVector(n);
  shuffleAndPrintVector(a);

  return 1;
}

