#ifndef APPS_ATOM_VIEW_H
#define APPS_ATOM_VIEW_H

#include <escher.h>

namespace Atom {

class AtomView : public View {
public:
  AtomView();
  void drawRect(KDContext * ctx, KDRect rect) const override;
  
  void handleRight();
  void handleLeft();
  void handleUp();
  void handleDown();
  void handleCopy();
  bool handleOK();
  bool handleBack();
private:
  void drawAtom(KDContext * ctx, uint8_t id) const;
};

}

#endif
