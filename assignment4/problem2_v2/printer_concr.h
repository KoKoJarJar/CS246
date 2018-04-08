#ifndef __PRINTER_CONCR__
#define __PRINTER_CONCR__

#include "game.h"
#include "printer.h"
#include <ostream>

class Printer_concr : public Printer {
public:
  // Constructor
  Printer_concr();

  // See header for description
  void print(const Game &game, std::ostream &out);
};

#endif
