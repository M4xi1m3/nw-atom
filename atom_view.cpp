#include "atom_view.h"
#include <assert.h>
#include <poincare/integer.h>

#define ATOM_NUMS 86

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
  uint8_t neutrons;
};

AtomDef atomsdefs[ATOM_NUMS] = {
  {  1,  0,  0, REACTIVE_NONMETAL       , "Hydrogen"    , "H"   ,   0},
  {  2, 17,  0, NOBLE_GAS               , "Helium"      , "He"  ,   2},
  
  
  {  3,  0,  1, ALKALI_METAL            , "Lithium"     , "Li"  ,   4},
  {  4,  1,  1, ALKALI_EARTH_METAL      , "Beryllium"   , "Be"  ,   5},
  {  5, 12,  1, METALLOID               , "Boron"       , "B"   ,   6},
  {  6, 13,  1, REACTIVE_NONMETAL       , "Carbon"      , "C"   ,   6},
  {  7, 14,  1, REACTIVE_NONMETAL       , "Nitrogen"    , "N"   ,   7},
  {  8, 15,  1, REACTIVE_NONMETAL       , "Oxygen"      , "O"   ,   8},
  {  9, 16,  1, HALOGEN                 , "Fluorine"    , "F"   ,   10},
  { 10, 17,  1, NOBLE_GAS               , "Neon"        , "Ne"  ,   10},
  
  
  { 11,  0,  2, ALKALI_METAL            , "Sodium"      , "Na"  ,   12},
  { 12,  1,  2, ALKALI_EARTH_METAL      , "Magnesium"   , "Mg"  ,   12},
  { 13, 12,  2, POST_TRANSITION_METAL   , "Aluminium"   , "Al"  ,   14},
  { 14, 13,  2, METALLOID               , "Silicon"     , "Si"  ,   14},
  { 15, 14,  2, REACTIVE_NONMETAL       , "Phosphorus"  , "P"   ,   16},
  { 16, 15,  2, REACTIVE_NONMETAL       , "Sulfur"      , "S"   ,   16},
  { 17, 16,  2, HALOGEN                 , "Chlorine"    , "Cl"  ,   18},
  { 18, 17,  2, NOBLE_GAS               , "Argon"       , "Ar"  ,   22},
  
  
  { 19,  0,  3, ALKALI_METAL            , "Potassium"   , "K"   ,   20},
  { 20,  1,  3, ALKALI_EARTH_METAL      , "Calcium"     , "Ca"  ,   20},
  { 21,  2,  3, TRANSITION_METAL        , "Scandium"    , "Sc"  ,   24},
  { 22,  3,  3, TRANSITION_METAL        , "Titanium"    , "Ti"  ,   26},
  { 23,  4,  3, TRANSITION_METAL        , "Vanadium"    , "V"   ,   28},
  { 24,  5,  3, TRANSITION_METAL        , "Chromium"    , "Cr"  ,   28},
  { 25,  6,  3, TRANSITION_METAL        , "Manganese"   , "Mn"  ,   30},
  { 26,  7,  3, TRANSITION_METAL        , "Iron"        , "Fe"  ,   30},
  { 27,  8,  3, TRANSITION_METAL        , "Cobalt"      , "Co"  ,   32},
  { 28,  9,  3, TRANSITION_METAL        , "Nickel"      , "Ni"  ,   31},
  { 29, 10,  3, TRANSITION_METAL        , "Copper"      , "Cu"  ,   35},
  { 30, 11,  3, TRANSITION_METAL        , "Zinc"        , "Zn"  ,   35},
  { 31, 12,  3, POST_TRANSITION_METAL   , "Gallium"     , "Ga"  ,   39},
  { 32, 13,  3, METALLOID               , "Germanium"   , "Ge"  ,   41},
  { 33, 14,  3, METALLOID               , "Arsenic"     , "As"  ,   42},
  { 34, 15,  3, REACTIVE_NONMETAL       , "Selenium"    , "Se"  ,   45},
  { 35, 16,  3, HALOGEN                 , "Bromine"     , "Br"  ,   45},
  { 36, 17,  3, NOBLE_GAS               , "Krypton"     , "Kr"  ,   48},
  
  
  { 37,  0,  4, ALKALI_METAL            , "Rubidium"    , "Rb"  ,   20},
  { 38,  1,  4, ALKALI_EARTH_METAL      , "Strontium"   , "Sr"  ,   20},
  { 39,  2,  4, TRANSITION_METAL        , "Yttrium"     , "Y"   ,   24},
  { 40,  3,  4, TRANSITION_METAL        , "Zirconium"   , "Zr"  ,   26},
  { 41,  4,  4, TRANSITION_METAL        , "Niobium"     , "Nb"  ,   28},
  { 42,  5,  4, TRANSITION_METAL        , "Molybdenum"  , "Mo"  ,   28},
  { 43,  6,  4, TRANSITION_METAL        , "Technetium"  , "Tc"  ,   30},
  { 44,  7,  4, TRANSITION_METAL        , "Ruthemium"   , "Ru"  ,   30},
  { 45,  8,  4, TRANSITION_METAL        , "Rhodium"     , "Rh"  ,   32},
  { 46,  9,  4, TRANSITION_METAL        , "Palladium"   , "Pd"  ,   31},
  { 47, 10,  4, TRANSITION_METAL        , "Silver"      , "Ag"  ,   35},
  { 48, 11,  4, TRANSITION_METAL        , "Cadmium"     , "Cd"  ,   35},
  { 49, 12,  4, POST_TRANSITION_METAL   , "Indium"      , "In"  ,   39},
  { 50, 13,  4, POST_TRANSITION_METAL   , "Tin"         , "Sn"  ,   41},
  { 51, 14,  4, METALLOID               , "Antimony"    , "Sb"  ,   42},
  { 52, 15,  4, METALLOID               , "Tellurium"   , "Te"  ,   45},
  { 53, 16,  4, HALOGEN                 , "Indine"      , "I"   ,   45},
  { 54, 17,  4, NOBLE_GAS               , "Xenon"       , "Xe"  ,   48},
  
  
  { 55,  0,  5, ALKALI_METAL            , "Caesium"     , "Cs"  ,   78},
  { 56,  1,  5, ALKALI_EARTH_METAL      , "Barium"      , "Ba"  ,   81},

  { 57,  3,  7, LANTHANIDE              , "Lanthanum"   , "La"  ,   82},
  { 58,  4,  7, LANTHANIDE              , "Cerium"      , "Ce"  ,   82},
  { 59,  5,  7, LANTHANIDE              , "Praseodymium", "Pr"  ,   82},
  { 60,  6,  7, LANTHANIDE              , "Neodymium"   , "Nd"  ,   84},
  { 61,  7,  7, LANTHANIDE              , "Promethium"  , "Pm"  ,   84},
  { 62,  8,  7, LANTHANIDE              , "Samarium"    , "Sm"  ,   88},
  { 63,  9,  7, LANTHANIDE              , "Europium"    , "Eu"  ,   89},
  { 64, 10,  7, LANTHANIDE              , "Gadolinium"  , "Gd"  ,   93},
  { 65, 11,  7, LANTHANIDE              , "Terbium"     , "Tb"  ,   94},
  { 66, 12,  7, LANTHANIDE              , "Dyxprosium"  , "Dy"  ,   97},
  { 67, 13,  7, LANTHANIDE              , "Holmium"     , "Ho"  ,   98},
  { 68, 14,  7, LANTHANIDE              , "Erbium"      , "Er"  ,   99},
  { 69, 15,  7, LANTHANIDE              , "Thulium"     , "Tm"  ,  100},
  { 70, 16,  7, LANTHANIDE              , "Ytterbium"   , "Yb"  ,  103},
  { 71, 17,  7, LANTHANIDE              , "Lutetium"    , "Lu"  ,  104},

  { 72,  3,  5, TRANSITION_METAL        , "Hafnium"     , "Hf"  ,  106},
  { 73,  4,  5, TRANSITION_METAL        , "Tantalum"    , "Ta"  ,  108},
  { 74,  5,  5, TRANSITION_METAL        , "Tungsten"    , "W"   ,  110},
  { 75,  6,  5, TRANSITION_METAL        , "Rhenium"     , "Re"  ,  111},
  { 76,  7,  5, TRANSITION_METAL        , "Osmium"      , "Os"  ,  114},
  { 77,  8,  5, TRANSITION_METAL        , "Iridium"     , "Ir"  ,  115},
  { 78,  9,  5, TRANSITION_METAL        , "Platinum"    , "Pt"  ,  117},
  { 79, 10,  5, TRANSITION_METAL        , "Gold"        , "Au"  ,  118},
  { 80, 11,  5, TRANSITION_METAL        , "Mercury"     , "Hg"  ,  121},
  { 81, 12,  5, POST_TRANSITION_METAL   , "Thalium"     , "Tl"  ,  123},
  { 82, 13,  5, POST_TRANSITION_METAL   , "Lead"        , "Pb"  ,  125},
  { 83, 14,  5, POST_TRANSITION_METAL   , "Bismuth"     , "Bi"  ,  126},
  { 84, 15,  5, POST_TRANSITION_METAL   , "Polonium"    , "Po"  ,  125},
  { 85, 16,  5, HALOGEN                 , "Astatine"    , "At"  ,  125},
  { 86, 17,  5, NOBLE_GAS               , "Radon"       , "Rn"  ,  136},
  
  
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

  if (atomsdefs[id].y >= 7) {
    ctx->fillRect(KDRect(6 + atomsdefs[id].x * 17, 15 + atomsdefs[id].y * 17, 18, 18), fill);
    ctx->strokeRect(KDRect(6 + atomsdefs[id].x * 17, 15 + atomsdefs[id].y * 17, 18, 18), KDColor::RGB24(0x525552));
  } else {
    ctx->fillRect(KDRect(6 + atomsdefs[id].x * 17, 6 + atomsdefs[id].y * 17, 18, 18), fill);
    ctx->strokeRect(KDRect(6 + atomsdefs[id].x * 17, 6 + atomsdefs[id].y * 17, 18, 18), KDColor::RGB24(0x525552));
  }


  
}

uint8_t cursor_pos = 2;

void AtomView::handleLeft() {
  if (cursor_pos > 0) {
    cursor_pos--;
    markRectAsDirty(bounds());
  }
}

void AtomView::handleRight() {
  if (cursor_pos < ATOM_NUMS - 1) {
    cursor_pos++;
    markRectAsDirty(bounds());
  }
}

void AtomView::handleUp() {
  uint8_t curr_x = atomsdefs[cursor_pos].x;
  uint8_t curr_y = atomsdefs[cursor_pos].y;
  bool updated = false;
  
  if (curr_y > 0 && curr_y <= 9) {
    for(uint8_t i = 0; i < ATOM_NUMS; i++) {
      if (atomsdefs[i].x == curr_x && atomsdefs[i].y == curr_y - 1) {
        cursor_pos = i;
        updated = true;
        break;
      }
    }
  }
  
  if (updated) {
    markRectAsDirty(bounds());
  }
}

void AtomView::handleDown() {
  uint8_t curr_x = atomsdefs[cursor_pos].x;
  uint8_t curr_y = atomsdefs[cursor_pos].y;
  bool updated = false;
  
  if (curr_y >= 0 && curr_y < 9) {
    for(uint8_t i = 0; i < ATOM_NUMS; i++) {
      if (atomsdefs[i].x == curr_x && atomsdefs[i].y == curr_y + 1) {
        cursor_pos = i;
        updated = true;
        break;
      }
    }
  }
  
  if (updated) {
    markRectAsDirty(bounds());
  }
}

void AtomView::drawRect(KDContext * ctx, KDRect rect) const {
  ctx->fillRect(bounds(), KDColorWhite);
  
  for(uint8_t i = 0; i < ATOM_NUMS; i++) {
    AtomView::drawAtom(ctx, i);
  }
  
  if (atomsdefs[cursor_pos].y >= 7) {
    ctx->strokeRect(KDRect(6 + atomsdefs[cursor_pos].x * 17, 15 + atomsdefs[cursor_pos].y * 17, 18, 18), KDColor::RGB24(0x000000));
    ctx->strokeRect(KDRect(7 + atomsdefs[cursor_pos].x * 17, 16 + atomsdefs[cursor_pos].y * 17, 16, 16), KDColor::RGB24(0x000000));
  } else {
    ctx->strokeRect(KDRect(6 + atomsdefs[cursor_pos].x * 17, 6 + atomsdefs[cursor_pos].y * 17, 18, 18), KDColor::RGB24(0x000000));
    ctx->strokeRect(KDRect(7 + atomsdefs[cursor_pos].x * 17, 7 + atomsdefs[cursor_pos].y * 17, 16, 16), KDColor::RGB24(0x000000));
  }
  
  ctx->fillRect(KDRect(48,  99, 2, 61), KDColor::RGB24(0x525552));
  ctx->fillRect(KDRect(48, 141, 9,  2), KDColor::RGB24(0x525552));
  ctx->fillRect(KDRect(48, 158, 9,  2), KDColor::RGB24(0x525552));

  char protons[4];
  char nucleons[4];
  
  Poincare::Integer(atomsdefs[cursor_pos].num).serialize(protons, 4);
  Poincare::Integer(atomsdefs[cursor_pos].neutrons + atomsdefs[cursor_pos].num).serialize(nucleons, 4);
  
  ctx->drawString(atomsdefs[cursor_pos].symbol, KDPoint(73, 23), KDFont::LargeFont);
  ctx->drawString(atomsdefs[cursor_pos].name, KDPoint(100, 23), KDFont::LargeFont);
  ctx->drawString(nucleons, KDPoint(50, 18), KDFont::SmallFont);
  ctx->drawString(protons, KDPoint(50, 31), KDFont::SmallFont);
}

}
