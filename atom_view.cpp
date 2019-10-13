#include "atom_view.h"
#include <assert.h>
#include <poincare/integer.h>
#include <poincare/number.h>

#define ATOM_NUMS 118

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
  double mass;
};

AtomDef atomsdefs[ATOM_NUMS] = {
  {  1,  0,  0, REACTIVE_NONMETAL       , "Hydrogen"     , "H"   ,   0, 1.00784     },
  {  2, 17,  0, NOBLE_GAS               , "Helium"       , "He"  ,   2, 4.002602    },
  
  
  {  3,  0,  1, ALKALI_METAL            , "Lithium"      , "Li"  ,   4, 6.938       },
  {  4,  1,  1, ALKALI_EARTH_METAL      , "Beryllium"    , "Be"  ,   5, 9.012182    },
  {  5, 12,  1, METALLOID               , "Boron"        , "B"   ,   6, 10.806      },
  {  6, 13,  1, REACTIVE_NONMETAL       , "Carbon"       , "C"   ,   6, 12.0096     },
  {  7, 14,  1, REACTIVE_NONMETAL       , "Nitrogen"     , "N"   ,   7, 14.00643    },
  {  8, 15,  1, REACTIVE_NONMETAL       , "Oxygen"       , "O"   ,   8, 16.99903    },
  {  9, 16,  1, HALOGEN                 , "Fluorine"     , "F"   ,  10, 18.9984032  },
  { 10, 17,  1, NOBLE_GAS               , "Neon"         , "Ne"  ,  10, 20.1797     },
  
  
  { 11,  0,  2, ALKALI_METAL            , "Sodium"       , "Na"  ,  12, 22.9897693  },
  { 12,  1,  2, ALKALI_EARTH_METAL      , "Magnesium"    , "Mg"  ,  12, 24.3050     },
  { 13, 12,  2, POST_TRANSITION_METAL   , "Aluminium"    , "Al"  ,  14, 26.9815386  },
  { 14, 13,  2, METALLOID               , "Silicon"      , "Si"  ,  14, 28.084      },
  { 15, 14,  2, REACTIVE_NONMETAL       , "Phosphorus"   , "P"   ,  16, 30.973762   },
  { 16, 15,  2, REACTIVE_NONMETAL       , "Sulfur"       , "S"   ,  16, 32.059      },
  { 17, 16,  2, HALOGEN                 , "Chlorine"     , "Cl"  ,  18, 35.446      },
  { 18, 17,  2, NOBLE_GAS               , "Argon"        , "Ar"  ,  22, 39.948      },
  
  
  { 19,  0,  3, ALKALI_METAL            , "Potassium"    , "K"   ,  20, 39.0983     },
  { 20,  1,  3, ALKALI_EARTH_METAL      , "Calcium"      , "Ca"  ,  20, 40.078      },
  { 21,  2,  3, TRANSITION_METAL        , "Scandium"     , "Sc"  ,  24, 44.955912   },
  { 22,  3,  3, TRANSITION_METAL        , "Titanium"     , "Ti"  ,  26, 47.867      },
  { 23,  4,  3, TRANSITION_METAL        , "Vanadium"     , "V"   ,  28, 50.9415     },
  { 24,  5,  3, TRANSITION_METAL        , "Chromium"     , "Cr"  ,  28, 51.9961     },
  { 25,  6,  3, TRANSITION_METAL        , "Manganese"    , "Mn"  ,  30, 54.938045   },
  { 26,  7,  3, TRANSITION_METAL        , "Iron"         , "Fe"  ,  30, 55.845      },
  { 27,  8,  3, TRANSITION_METAL        , "Cobalt"       , "Co"  ,  32, 58.933195   },
  { 28,  9,  3, TRANSITION_METAL        , "Nickel"       , "Ni"  ,  31, 58.6934     },
  { 29, 10,  3, TRANSITION_METAL        , "Copper"       , "Cu"  ,  35, 63.546      },
  { 30, 11,  3, POST_TRANSITION_METAL   , "Zinc"         , "Zn"  ,  35, 65.38       },
  { 31, 12,  3, POST_TRANSITION_METAL   , "Gallium"      , "Ga"  ,  39, 69.723      },
  { 32, 13,  3, METALLOID               , "Germanium"    , "Ge"  ,  41, 72.63       },
  { 33, 14,  3, METALLOID               , "Arsenic"      , "As"  ,  42, 74.92160    },
  { 34, 15,  3, REACTIVE_NONMETAL       , "Selenium"     , "Se"  ,  45, 78.96       },
  { 35, 16,  3, HALOGEN                 , "Bromine"      , "Br"  ,  45, 79.904      },
  { 36, 17,  3, NOBLE_GAS               , "Krypton"      , "Kr"  ,  48, 83.798      },
  
  { 37,  0,  4, ALKALI_METAL            , "Rubidium"     , "Rb"  ,  20, 85.4678     },
  { 38,  1,  4, ALKALI_EARTH_METAL      , "Strontium"    , "Sr"  ,  20, 87.62       },
  { 39,  2,  4, TRANSITION_METAL        , "Yttrium"      , "Y"   ,  24, 88.90585    },
  { 40,  3,  4, TRANSITION_METAL        , "Zirconium"    , "Zr"  ,  26, 91.224      },
  { 41,  4,  4, TRANSITION_METAL        , "Niobium"      , "Nb"  ,  28, 92.90638    },
  { 42,  5,  4, TRANSITION_METAL        , "Molybdenum"   , "Mo"  ,  28, 95.96       },
  { 43,  6,  4, TRANSITION_METAL        , "Technetium"   , "Tc"  ,  30, 98          },
  { 44,  7,  4, TRANSITION_METAL        , "Ruthemium"    , "Ru"  ,  30, 101.07      },
  { 45,  8,  4, TRANSITION_METAL        , "Rhodium"      , "Rh"  ,  32, 102.90550   },
  { 46,  9,  4, TRANSITION_METAL        , "Palladium"    , "Pd"  ,  31, 106.42      },
  { 47, 10,  4, TRANSITION_METAL        , "Silver"       , "Ag"  ,  35, 107.8682    },
  { 48, 11,  4, POST_TRANSITION_METAL   , "Cadmium"      , "Cd"  ,  35, 112.411     },
  { 49, 12,  4, POST_TRANSITION_METAL   , "Indium"       , "In"  ,  39, 114.818     },
  { 50, 13,  4, POST_TRANSITION_METAL   , "Tin"          , "Sn"  ,  41, 118.710     },
  { 51, 14,  4, METALLOID               , "Antimony"     , "Sb"  ,  42, 121.760     },
  { 52, 15,  4, METALLOID               , "Tellurium"    , "Te"  ,  45, 127.60      },
  { 53, 16,  4, HALOGEN                 , "Indine"       , "I"   ,  45, 126.90447   },
  { 54, 17,  4, NOBLE_GAS               , "Xenon"        , "Xe"  ,  48, 131.293     },
  
  
  { 55,  0,  5, ALKALI_METAL            , "Caesium"      , "Cs"  ,  78, 132.905452  },
  { 56,  1,  5, ALKALI_EARTH_METAL      , "Barium"       , "Ba"  ,  81, 137.327     },

  { 57,  3,  7, LANTHANIDE              , "Lanthanum"    , "La"  ,  82, 138.90547   },
  { 58,  4,  7, LANTHANIDE              , "Cerium"       , "Ce"  ,  82, 140.116     },
  { 59,  5,  7, LANTHANIDE              , "Praseodymium" , "Pr"  ,  82, 140.90765   },
  { 60,  6,  7, LANTHANIDE              , "Neodymium"    , "Nd"  ,  84, 144.242     },
  { 61,  7,  7, LANTHANIDE              , "Promethium"   , "Pm"  ,  84, 145         },
  { 62,  8,  7, LANTHANIDE              , "Samarium"     , "Sm"  ,  88, 150.36      },
  { 63,  9,  7, LANTHANIDE              , "Europium"     , "Eu"  ,  89, 151.964     },
  { 64, 10,  7, LANTHANIDE              , "Gadolinium"   , "Gd"  ,  93, 157.25      },
  { 65, 11,  7, LANTHANIDE              , "Terbium"      , "Tb"  ,  94, 158.92535   },
  { 66, 12,  7, LANTHANIDE              , "Dyxprosium"   , "Dy"  ,  97, 162.500     },
  { 67, 13,  7, LANTHANIDE              , "Holmium"      , "Ho"  ,  98, 164.93032   },
  { 68, 14,  7, LANTHANIDE              , "Erbium"       , "Er"  ,  99, 167.259     },
  { 69, 15,  7, LANTHANIDE              , "Thulium"      , "Tm"  , 100, 168.93421   },
  { 70, 16,  7, LANTHANIDE              , "Ytterbium"    , "Yb"  , 103, 173.054     },
  { 71, 17,  7, LANTHANIDE              , "Lutetium"     , "Lu"  , 104, 174.9668    },

  { 72,  3,  5, TRANSITION_METAL        , "Hafnium"      , "Hf"  , 106, 178.49      },
  { 73,  4,  5, TRANSITION_METAL        , "Tantalum"     , "Ta"  , 108, 180.94788   },
  { 74,  5,  5, TRANSITION_METAL        , "Tungsten"     , "W"   , 110, 183.84      },
  { 75,  6,  5, TRANSITION_METAL        , "Rhenium"      , "Re"  , 111, 186.207     },
  { 76,  7,  5, TRANSITION_METAL        , "Osmium"       , "Os"  , 114, 190.23      },
  { 77,  8,  5, TRANSITION_METAL        , "Iridium"      , "Ir"  , 115, 192.217     },
  { 78,  9,  5, TRANSITION_METAL        , "Platinum"     , "Pt"  , 117, 195.084     },
  { 79, 10,  5, TRANSITION_METAL        , "Gold"         , "Au"  , 118, 196.966569  },
  { 80, 11,  5, POST_TRANSITION_METAL   , "Mercury"      , "Hg"  , 121, 200.59      },
  { 81, 12,  5, POST_TRANSITION_METAL   , "Thalium"      , "Tl"  , 123, 204.382     },
  { 82, 13,  5, POST_TRANSITION_METAL   , "Lead"         , "Pb"  , 125, 207.2       },
  { 83, 14,  5, POST_TRANSITION_METAL   , "Bismuth"      , "Bi"  , 126, 208.98040   },
  { 84, 15,  5, POST_TRANSITION_METAL   , "Polonium"     , "Po"  , 125, 209         },
  { 85, 16,  5, HALOGEN                 , "Astatine"     , "At"  , 125, 210         },
  { 86, 17,  5, NOBLE_GAS               , "Radon"        , "Rn"  , 136, 222         },
  
  
  { 87,  0,  6, ALKALI_METAL            , "Francium"     , "Fr"  , 136, 223         },
  { 88,  1,  6, ALKALI_EARTH_METAL      , "Radium"       , "Ra"  , 138, 226         },

  { 89,  3,  8, ACTINIDE                , "Actinium"     , "Ac"  , 138, 227         },
  { 90,  4,  8, ACTINIDE                , "Thorium"      , "Th"  , 142, 232.03806   },
  { 91,  5,  8, ACTINIDE                , "Protactinium" , "Pa"  , 140, 231.03588   },
  { 92,  6,  8, ACTINIDE                , "Uranium"      , "U"   , 146, 238.02891   },
  { 93,  7,  8, ACTINIDE                , "Neptunium"    , "Np"  , 144, 237         },
  { 94,  8,  8, ACTINIDE                , "Plutonium"    , "Pu"  , 150, 244         },
  { 95,  9,  8, ACTINIDE                , "Americium"    , "Am"  , 148, 243         },
  { 96, 10,  8, ACTINIDE                , "Curium"       , "Cm"  , 151, 247         },
  { 97, 11,  8, ACTINIDE                , "Berkellum"    , "Bk"  , 150, 247         },
  { 98, 12,  8, ACTINIDE                , "Californium"  , "Cf"  , 153, 251         },
  { 99, 13,  8, ACTINIDE                , "Einsteinium"  , "Es"  , 153, 252         },
  {100, 14,  8, ACTINIDE                , "Fermium"      , "Fm"  , 157, 257         },
  {101, 15,  8, ACTINIDE                , "Mendelevium"  , "Md"  , 157, 258         },
  {102, 16,  8, ACTINIDE                , "Nobelium"     , "No"  , 157, 259         },
  {103, 17,  8, ACTINIDE                , "Lawrencium"   , "Lr"  , 159, 262         },

  {104,  3,  6, TRANSITION_METAL        , "Rutherfordium", "Rf"  , 157, 261         },
  {105,  4,  6, TRANSITION_METAL        , "Dubnium"      , "Db"  , 157, 262         },
  {106,  5,  6, TRANSITION_METAL        , "Seaborgium"   , "Sg"  , 157, 263         },
  {107,  6,  6, TRANSITION_METAL        , "Bohrium"      , "Bh"  , 157, 264         },
  {108,  7,  6, TRANSITION_METAL        , "Hassium"      , "Hs"  , 157, 265         },
  {109,  8,  6, UNKNOWN                 , "Meitnerium"   , "Mt"  , 159, 268         },
  {110,  9,  6, UNKNOWN                 , "Damstadtium"  , "Ds"  , 171, 281         },
  {111, 10,  6, UNKNOWN                 , "Roentgenium"  , "Rg"  , 162, 273         },
  {112, 11,  6, POST_TRANSITION_METAL   , "Coppernicium" , "Cn"  , 165, 277         },
  {113, 12,  6, UNKNOWN                 , "Nihonium"     , "Nh"  , 170, 283         },
  {114, 13,  6, UNKNOWN                 , "Flerovium"    , "Fl"  , 171, 285         },
  {115, 14,  6, UNKNOWN                 , "Moscovium"    , "Mv"  , 172, 287         },
  {116, 15,  6, UNKNOWN                 , "Livermorium"  , "Lv"  , 173, 289         },
  {117, 16,  6, UNKNOWN                 , "Tennessine"   , "Ts"  , 177, 294         },
  {118, 17,  6, NOBLE_GAS               , "Oganesson"    , "Og"  , 175, 293         },
  
  
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
    
    ctx->drawString(atomsdefs[id].symbol, KDPoint(8 + atomsdefs[id].x * 17, 17 + atomsdefs[id].y * 17), KDFont::SmallFont, KDColor::RGB24(0x222222), fill);
  } else {
    ctx->fillRect(KDRect(6 + atomsdefs[id].x * 17, 6 + atomsdefs[id].y * 17, 18, 18), fill);
    ctx->strokeRect(KDRect(6 + atomsdefs[id].x * 17, 6 + atomsdefs[id].y * 17, 18, 18), KDColor::RGB24(0x525552));
    
    ctx->drawString(atomsdefs[id].symbol, KDPoint(8 + atomsdefs[id].x * 17, 8 + atomsdefs[id].y * 17), KDFont::SmallFont, KDColor::RGB24(0x222222), fill);
  }


  
}

uint8_t cursor_pos = 2;
bool partial_draw = false;

void AtomView::handleLeft() {
  if (cursor_pos > 0) {
    cursor_pos--;
    partial_draw = true;
    markRectAsDirty(bounds());
  }
}

void AtomView::handleRight() {
  if (cursor_pos < ATOM_NUMS - 1) {
    cursor_pos++;
    partial_draw = true;
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
    partial_draw = true;
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
    partial_draw = true;
    markRectAsDirty(bounds());
  }
}

void AtomView::drawRect(KDContext * ctx, KDRect rect) const {
  if (partial_draw) {
    partial_draw = false;
    ctx->fillRect(KDRect(50,   0, 169, 57), KDColorWhite);
    ctx->fillRect(KDRect( 8, 168, 305, 35), KDColorWhite);
  } else {
    ctx->fillRect(bounds(), KDColorWhite);
  }
  
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
  ctx->drawString(atomsdefs[cursor_pos].name, KDPoint(110, 27), KDFont::SmallFont);
  ctx->drawString(nucleons, KDPoint(50, 18), KDFont::SmallFont);
  ctx->drawString(protons, KDPoint(50, 31), KDFont::SmallFont);
  
  char mass[15] = "             ";
  
  mass[0] = 'M';
  mass[1] = ':';
  mass[2] = ' ';
  
  int num = Poincare::Number::FloatNumber(atomsdefs[cursor_pos].mass).serialize(mass + 3, 11);
  mass[3 + num] = 0;
  
  ctx->drawString(mass, KDPoint(8, 174), KDFont::SmallFont);
}

}
