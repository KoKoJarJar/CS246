#include <cstdlib>
#include <iostream>
using namespace std;

// volatile prevents dead-code removal
void do_work(int C1, int C2, int C3, int L1, int L2, volatile int L3) {
  bool flag1 = false;
  int i = 0;
  while ((i < L1) & !flag1) {
# git statusifndef NO_OUTPUT
    cout << "S1 i:" << i << endl;
#endif
    bool flag2 = false;
    int j = 0;
    while ((j < L2) & !flag2 & !flag1) {
#ifndef NO_OUTPUT
      cout << "S2 i:" << i << " j:" << j << endl;
#endif
      int k = 0;
      bool flag3 = false;
      while ((k < L3) & !flag3 & !flag2 & !flag1) {
#ifndef NO_OUTPUT
        cout << "S3 i:" << i << " j:" << j << " k:" << k << " : ";
#endif
        if (C1) {
          flag1 = true;
        } else {
#ifndef NO_OUTPUT
          cout << "S4 i:" << i << " j:" << j << " k:" << k << " : ";
#endif
          if (C2) {
            flag2 = true;
          } else {
#ifndef NO_OUTPUT
            cout << "S5 i:" << i << " j:" << j << " k:" << k << " : ";
#endif
            if (C3) {
              flag3 = true;
            } else {
#ifndef NO_OUTPUT
              cout << "S6 i:" << i << " j:" << j << " k:" << k << " : ";
#endif
            }
          }
        }
        ++k;
      } // while
      if (!flag2 & !flag1) {
#ifndef NO_OUTPUT
        cout << "S7 i:" << i << " j:" << j << endl;
#endif
      }
      ++j;
    } // w
    if (!flag1) {
#ifndef NO_OUTPUT
    cout << "S8 i:" << i << endl;
#endif
    }
    ++i;
  } // while
} // do_work

int main(int argc, char *argv[]) {
  int times = 1, L1 = 10, L2 = 10, L3 = 10;
  switch (argc) {
  case 5:
    L3 = atoi(argv[4]);
    L2 = atoi(argv[3]);
    L1 = atoi(argv[2]);
    times = atoi(argv[1]);
    break;
  default:
    cerr << "Usage: " << argv[0] << " times L1 L2 L3" << endl;
    exit(EXIT_FAILURE);
  } // switch
  for (int i = 0; i < times; ++i) {
    for (int C1 = 0; C1 < 2; ++C1) {
      for (int C2 = 0; C2 < 2; ++C2) {
        for (int C3 = 0; C3 < 2; ++C3) {
          do_work(C1, C2, C3, L1, L2, L3);
#ifndef NO_OUTPUT
          cout << endl;
#endif
        }
      }
    }
  }
}
