#ifndef APPS_ATOM_VIEW_H
#define APPS_ATOM_VIEW_H

#include <escher.h>

namespace Atom {

class AtomView : public View {
public:
  AtomView();
  void drawRect(KDContext * ctx, KDRect rect) const override;
};

}

#endif
