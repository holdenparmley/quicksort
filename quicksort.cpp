#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

const int minSizeForMO3 = 25;  // See readme.txt for justification                                                                                                                                                                                                                                          

void swap(std::vector<int>& A, int i, int j) {  // Swap helper function                                                                                                                                                                                                                                     
  int temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

int medianOfThree(std::vector<int>& A, int p, int r) {
  int midpoint = p + ((r - p) / 2);
  int pVal = A[p];
  int mVal = A[midpoint];
  int rVal = A[r];
  int medIndex = r;  // Initializing the return value, random decision to make it r                                                                                                                                                                                                                         
  if ((pVal < mVal && pVal > rVal) || (pVal > mVal && pVal < rVal)) {
    medIndex = p;
  }
  else if ((mVal < pVal && mVal > rVal) || (mVal > pVal && mVal < rVal)) {
    medIndex = midpoint;
  }
  else if ((rVal < pVal && rVal > mVal) || (rVal > pVal && rVal < mVal)) {
    medIndex = r;
  }
  return medIndex;
  }

int partition(std::vector<int>& A, int p, int r) {
  // For each time partition is called, check the size of the list chunk                                                                                                                                                                                                                                    
  if ((r - p) > minSizeForMO3) {
    int medIndex = medianOfThree(A, p, r);
    swap(A, medIndex, r);
  }
  int x = A[r];
  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (A[j] <= x) {
      i++;
      swap(A, i, j);
    }
  }
  swap(A, i + 1, r);
  return i + 1;
}

int hoarePartition(std::vector<int>& A, int p, int r) {
  if ((r - p) > minSizeForMO3) {
    int medIndex = medianOfThree(A, p, r);
    swap(A, medIndex, p);
  }
  int x = A[p];
  int i = p - 1;
  int j = r + 1;
  while (true) {
    do {
      i = i + 1;
    } while (A[i] < x);
    do {
      j = j - 1;
    } while (A[j] > x);
    if (i >= j) {
      return j;
    }
    swap(A, i, j);
  }
  return r;
}

// Our real quicksort function                                                                                                                                                                                                                                                                              
void quicksort(std::vector<int>& A, int p, int r, int method) {
  if (p < r) {
    if (method == 2) {
      int q = hoarePartition(A, p, r);
      quicksort(A, p, q, 2);
      quicksort(A, q + 1, r, 2);
    } else if (method == 1) {
      int q = partition(A, p, r);
      quicksort(A, p, q - 1, 1);
      quicksort(A, q + 1, r, 1);
    }
  }
}

// Our wrapper quicksort function                                                                                                                                                                                                                                                                           
void quicksort(std::vector<int>& A, int method)  {
  quicksort(A, 0, A.size() - 1, method);
}

int main(int argc, char* argv[]) {
  std::vector<int> values;
  std::string line;
  while (std::getline(std::cin, line)) {
    int value = std::stoi(line);
    if (value >= 0) {
      values.push_back(value);
    }
  }
  if (argv[1]) {  // Handle the command line parameter to determine partition method                                                                                                                                                                                                                        
    std::string arg = argv[1];
    if (arg == "-h") {
      quicksort(values, 2);  // Argument of 2 uses Hoare partitioning                                                                                                                                                                                                                                       
    }
  } else {
    quicksort(values, 1);  // Argument of 1 uses Lomuto partitioning                                                                                                                                                                                                                                        
  }
  for (int value : values) {
    std::cout << std::setw(9) << std::setfill('0') << value << std::endl;
   }
}
