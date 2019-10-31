#include "app.h"
#include "atom_icon.h"

#include <apps/i18n.h>
#include <apps/apps_container.h>

namespace Atom {

I18n::Message App::Descriptor::name() {
  return I18n::Message::AtomApp;
}

I18n::Message App::Descriptor::upperName() {
  return I18n::Message::AtomAppCapital;
}

const Image * App::Descriptor::icon() {
  return ImageStore::AtomIcon;
}

App * App::Snapshot::unpack(Container * container) {
  return new (container->currentAppBuffer()) App(container, this);
}

void App::Snapshot::reset() {
}

App::Descriptor * App::Snapshot::descriptor() {
  static Descriptor descriptor;
  return &descriptor;
}

void App::didBecomeActive(Window * window) {
  ::App::didBecomeActive(window);
}

void App::willBecomeInactive() {
  ::App::willBecomeInactive();
}

App::App(Container * container, Snapshot * snapshot) :
  ::App(snapshot, &m_atomController),
  m_appsContainer((AppsContainer*) container)
{
}

}
