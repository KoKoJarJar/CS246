#include <cstdlib>

void iterate(int i) {
  volatile int bef = 0, aft = 0;
#ifndef RECURSION
  for (;;) {
    ++bef;
    if (i == 0)
      break;
    --i;
    ++aft;
  }
#else
  ++bef;
  if (i == 0)
    return;
  iterate(i - 1);
  ++aft;
#endif
}

int main(int argc, char *argv[]) {
  unsigned int times = 10000000;
  using namespace std;
  switch (argc) {
  case 2:
    times = atoi(argv[1]);
  }
  iterate(times);
}
