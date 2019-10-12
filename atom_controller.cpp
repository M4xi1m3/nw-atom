#include "atom_controller.h"

namespace Atom {

AtomController::AtomController() :
  ViewController(nullptr),
  m_atomView()
{
}

View * AtomController::view() {
  return &m_atomView;
}

}
