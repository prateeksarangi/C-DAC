#include <iostream>
#include <string>
#include <vector>
#include "omp.h"
int main() {
#pragma omp parallel        
      #pragma omp single
      std::cout << "Number of threads = " << omp_get_num_threads() << std::endl;
  return 0;
}
