// Filename: dnaSign.h
// Created by:  skyler (2001-30-01)
//
////////////////////////////////////////////////////////////////////
#ifndef DNASign_H
#define DNASign_H
//

#include "dnaNode.h"
#include "dnaBuildings.h"
#include "pandaNode.h"
#include "nodePath.h"
#include "luse.h"
#include "pvector.h"

////////////////////////////////////////////////////////////////////
//       Class : DNASign
// Description : A Sign
////////////////////////////////////////////////////////////////////
class EXPCL_TOONTOWN DNASign : public DNANode  {
PUBLISHED:
  DNASign(const std::string &initial_name = "");
  DNASign(const DNASign &Sign);

  virtual NodePath traverse(NodePath &parent, DNAStorage *store, int editing=0);
  virtual void write(std::ostream &out, DNAStorage *store, int indent_level = 0) const;

  void set_code(std::string code);
  std::string get_code() const;

  void set_color(const LColorf &color);
  LColorf get_color() const;

private:
  virtual DNAGroup* make_copy();

private:
  std::string _code;
  LColorf _color;

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    DNANode::init_type();
    register_type(_type_handle, "DNASign",
                  DNANode::get_class_type()
                  );
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

private:
  static TypeHandle _type_handle;
};

#include "dnaSign.I"

#endif
