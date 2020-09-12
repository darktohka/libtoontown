// Filename: dnaSign.I
// Created by:  skyler (2001-30-01)
//
////////////////////////////////////////////////////////////////////


INLINE void DNASign::
set_color(const LColorf &color) {
  _color = color;
}

INLINE LColorf DNASign::
get_color() const {
  return _color;
}

INLINE void DNASign::
set_code(std::string code) {
  _code = code;
}

INLINE std::string DNASign::
get_code() const {
  return _code;
}
