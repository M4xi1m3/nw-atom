#include "atom_view.h"
#include <assert.h>

namespace Atom {

AtomView::AtomView() :
  View()
{
}

void AtomView::drawRect(KDContext * ctx, KDRect rect) const {
  ctx->fillRect(bounds(), KDColorWhite);
  
  ctx->drawString("Hello world!", KDPointZero);
}

}
