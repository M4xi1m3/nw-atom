#ifndef APPS_ATOM_CONTROLLER_H
#define APPS_ATOM_CONTROLLER_H

#include <escher.h>
#include "atom_view.h"

namespace Atom {

class AtomController : public ViewController {
public:
  AtomController();
  View * view() override;
  bool handleEvent(Ion::Events::Event e) override;
private:
  AtomView m_atomView;
};

}

#endif
