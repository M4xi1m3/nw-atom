#include "atom_view.h"
#include <assert.h>

#define ATOM_NUMS 18

namespace Atom {

enum AtomType {
  ALKALI_METAL,
  ALKALI_EARTH_METAL,
  LANTHANIDE,
  ACTINIDE,
  TRANSITION_METAL,
  POST_TRANSITION_METAL,
  METALLOID,
  HALOGEN,
  REACTIVE_NONMETAL,
  NOBLE_GAS,
  UNKNOWN
};

struct AtomDef {
  uint8_t num;
  uint8_t x;
  uint8_t y;
  AtomType type;
  const char* name;
  const char* symbol;
  float mass;
  uint8_t neutrons;
  uint8_t protons;
};

AtomDef atomsdefs[ATOM_NUMS] = {
  {  1,  0,  0, REACTIVE_NONMETAL       , "Hydrogen"    , "H"   , 1.007840f,   0,   1},
  {  2, 17,  0, NOBLE_GAS               , "Helium"      , "He"  , 4.002602f,   2,   2},
  
  {  3,  0,  1, ALKALI_METAL            , "Lithium"     , "Li"  , 6.938000f,   4,   3},
  {  4,  1,  1, ALKALI_EARTH_METAL      , "Beryllium"   , "Be"  , 6.938000f,   4,   3},
  {  5, 12,  1, METALLOID               , "Boron"       , "B"   , 6.938000f,   4,   3},
  {  6, 13,  1, REACTIVE_NONMETAL       , "Carbon"      , "C"   , 6.938000f,   4,   3},
  {  7, 14,  1, REACTIVE_NONMETAL       , "Nitrogen"    , "N"   , 6.938000f,   4,   3},
  {  8, 15,  1, REACTIVE_NONMETAL       , "Oxygen"      , "O"   , 6.938000f,   4,   3},
  {  9, 16,  1, HALOGEN                 , "Fluorine"    , "F"   , 6.938000f,   4,   3},
  { 10, 17,  1, NOBLE_GAS               , "Neon"        , "Ne"  , 6.938000f,   4,   3},
  
  { 11,  0,  2, ALKALI_METAL            , "Sodium"      , "Na"  , 6.938000f,   4,   3},
  { 12,  1,  2, ALKALI_EARTH_METAL      , "Magnesium"   , "Mg"  , 6.938000f,   4,   3},
  { 13, 12,  2, POST_TRANSITION_METAL   , "Aluminium"   , "Al"  , 6.938000f,   4,   3},
  { 14, 13,  2, METALLOID               , "Silicon"     , "Si"  , 6.938000f,   4,   3},
  { 15, 14,  2, REACTIVE_NONMETAL       , "Phosphorus"  , "P"   , 6.938000f,   4,   3},
  { 16, 15,  2, REACTIVE_NONMETAL       , "Sulfur"      , "S"   , 6.938000f,   4,   3},
  { 17, 16,  2, HALOGEN                 , "Chlorine"    , "Cl"  , 6.938000f,   4,   3},
  { 18, 17,  2, NOBLE_GAS               , "Argon"       , "Ar"  , 6.938000f,   4,   3}
};

AtomView::AtomView() :
  View()
{
}

void AtomView::drawAtom(KDContext * ctx, uint8_t id) const {
  KDColor fill = KDColor::RGB24(0xeeeeee);

  switch(atomsdefs[id].type) {
    case ALKALI_METAL:
      fill = KDColor::RGB24(0xffaa00);
      break;
    case ALKALI_EARTH_METAL:
      fill = KDColor::RGB24(0xf6f200);
      break;
    case LANTHANIDE:
      fill = KDColor::RGB24(0xffaa8b);
      break;
    case ACTINIDE:
      fill = KDColor::RGB24(0xdeaacd);
      break;
    case TRANSITION_METAL:
      fill = KDColor::RGB24(0xde999c);
      break;
    case POST_TRANSITION_METAL:
      fill = KDColor::RGB24(0x9cbaac);
      break;
    case METALLOID:
      fill = KDColor::RGB24(0x52ce8b);
      break;
    case REACTIVE_NONMETAL:
      fill = KDColor::RGB24(0x00ee00);
      break;
    case NOBLE_GAS:
      fill = KDColor::RGB24(0x8baaff);
      break;
    case HALOGEN:
      fill = KDColor::RGB24(0x00debd);
      break;
    default:
      break;
  }

  ctx->fillRect(KDRect(6 + atomsdefs[id].x * 17, 6 + atomsdefs[id].y * 17, 18, 18), fill);
  ctx->strokeRect(KDRect(6 + atomsdefs[id].x * 17, 6 + atomsdefs[id].y * 17, 18, 18), KDColor::RGB24(0x525552));
}

void AtomView::drawRect(KDContext * ctx, KDRect rect) const {
  ctx->fillRect(bounds(), KDColorWhite);
  
  // ctx->drawString("Hello world!", KDPointZero);
  
  for(uint8_t i = 0; i < ATOM_NUMS; i++) {
    AtomView::drawAtom(ctx, i);
  }
  
  // ctx->fillRect(KDRect(6, 6, 18, 18), KDColor::RGB24(0x00ee00));
  // ctx->strokeRect(KDRect(6, 6, 18, 18), KDColor::RGB24(0x525552));
}

}
