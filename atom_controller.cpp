#include "atom_controller.h"
#include <apps/apps_container.h>

namespace Atom {

AtomController::AtomController() :
  ViewController(nullptr),
  m_atomView()
{
}

bool AtomController::handleEvent(Ion::Events::Event e) {
  if (e == Ion::Events::Right) {
    m_atomView.handleRight();
    AppsContainer::sharedAppsContainer()->redrawWindow();
    return true;
  }
  
  if (e == Ion::Events::Left){
    m_atomView.handleLeft();
    AppsContainer::sharedAppsContainer()->redrawWindow();
    return true;
  }
  
  if (e == Ion::Events::Up){
    m_atomView.handleUp();
    AppsContainer::sharedAppsContainer()->redrawWindow();
    return true;
  }
  
  if (e == Ion::Events::Down){
    m_atomView.handleDown();
    AppsContainer::sharedAppsContainer()->redrawWindow();
    return true;
  }
  
  if (e == Ion::Events::Copy){
    AppsContainer::sharedAppsContainer()->redrawWindow();
    m_atomView.handleCopy();
    return true;
  }
  
  if (e == Ion::Events::OK || e == Ion::Events::EXE){
    if (m_atomView.handleOK()) {
      AppsContainer::sharedAppsContainer()->redrawWindow();
      return true;
    }
  }
  
  if (e == Ion::Events::Back){
    if (m_atomView.handleBack()) {
      AppsContainer::sharedAppsContainer()->redrawWindow();
      return true;
    }
  }
  
  return false;
}

View * AtomController::view() {
  return &m_atomView;
}

}
