// Filename: dnaSignText.I
// Created by:  skyler (2001-30-01)
//
////////////////////////////////////////////////////////////////////


INLINE void DNASignText::
set_color(const LColorf &color) {
  _use_baseline_color = false;
  _color = color;
}

INLINE LColorf DNASignText::
get_color() const {
  return _color;
}

INLINE void DNASignText::
set_code(std::string code) {
  _code = code;
}

INLINE std::string DNASignText::
get_code() const {
  return _code;
}

INLINE void DNASignText::
set_letters(std::string letters) {
  _letters = letters;
}

INLINE std::string DNASignText::
get_letters() const {
  return _letters;
}
