#include <cstdlib>

void alloc(unsigned int size, unsigned int times) {
  for (unsigned int i = 0; i < times; ++i) {
#ifdef DYN
    volatile int *arr = new int[size];
    arr[0] = 5;
    delete[] arr;
#else
    volatile int arr[size];
    arr[0] = 5;
#endif
  }
}

int main(int argc, char const *argv[]) {
  int times = 100000000;
  switch (argc) {
  case 2:
    times = atoi(argv[1]);
  }
  alloc(10, times);
  volatile int *arr = 0;
  delete arr;
}
