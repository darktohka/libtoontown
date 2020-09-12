// Filename: dnaStreet.h
// Created by:  shochet (26May00)
//
////////////////////////////////////////////////////////////////////

//
#ifndef DNASTREET_H
#define DNASTREET_H
//
////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////
#include "dnaStorage.h"
#include "dnaNode.h"
#include "pandaNode.h"
#include "nodePath.h"
#include "luse.h"
#include "pvector.h"


////////////////////////////////////////////////////////////////////
//       Class : DNAStreet
// Description : A street.
////////////////////////////////////////////////////////////////////
class EXPCL_TOONTOWN DNAStreet : public DNANode  {
PUBLISHED:
  DNAStreet(const std::string &initial_name);
  DNAStreet(const DNAStreet &street);

  virtual NodePath traverse(NodePath &parent, DNAStorage *store, int editing=0);
  virtual void write(std::ostream &out, DNAStorage *store, int indent_level = 0) const;

  INLINE void set_code(std::string code);
  INLINE std::string get_code() const;

  INLINE void set_street_texture(std::string street_texture);
  INLINE std::string get_street_texture() const;

  INLINE void set_sidewalk_texture(std::string sidewalk_texture);
  INLINE std::string get_sidewalk_texture() const;

  INLINE void set_curb_texture(std::string curb_texture);
  INLINE std::string get_curb_texture() const;

  // For now we no longer support color on streets to allow vertex color

  INLINE void set_street_color(const LColorf &color);
  INLINE LColorf get_street_color() const;

  INLINE void set_sidewalk_color(const LColorf &color);
  INLINE LColorf get_sidewalk_color() const;

  INLINE void set_curb_color(const LColorf &color);
  INLINE LColorf get_curb_color() const;

private:
  virtual DNAGroup* make_copy();

private:
  std::string _code;
  std::string _street_texture;
  std::string _sidewalk_texture;
  std::string _curb_texture;
  LColorf _street_color;
  LColorf _sidewalk_color;
  LColorf _curb_color;

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    DNANode::init_type();
    register_type(_type_handle, "DNAStreet",
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

#include "dnaStreet.I"

#endif
