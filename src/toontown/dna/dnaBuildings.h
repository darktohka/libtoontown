// Filename: dnaBuildings.h
// Created by:  shochet (28Mar00)
//
////////////////////////////////////////////////////////////////////
#ifndef DNABUILDINGS_H
#define DNABUILDINGS_H
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
//       Class : DNAWall
// Description : A stackable wall.
////////////////////////////////////////////////////////////////////
class EXPCL_TOONTOWN DNAWall : public DNANode  {
PUBLISHED:
  DNAWall(const std::string &initial_name = "");
  DNAWall(const DNAWall &wall);

  virtual NodePath traverse(NodePath &parent, DNAStorage *store, int editing=0);
  virtual void write(std::ostream &out, DNAStorage *store, int indent_level = 0) const;

  INLINE void set_code(std::string code);
  INLINE std::string get_code() const;

  INLINE void set_height(float height);
  INLINE float get_height() const ;

  INLINE void set_color(const LColorf &color);
  INLINE LColorf get_color() const;

private:
  virtual DNAGroup* make_copy();


private:
  std::string _code;
  float _height;
  LColorf _color;

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    DNANode::init_type();
    register_type(_type_handle, "DNAWall",
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




////////////////////////////////////////////////////////////////////
//       Class : DNAFlatBuilding
// Description : A flat building.
////////////////////////////////////////////////////////////////////
class EXPCL_TOONTOWN DNAFlatBuilding : public DNANode  {
PUBLISHED:
  DNAFlatBuilding(const std::string &initial_name = "");
  DNAFlatBuilding(const DNAFlatBuilding &building);

  virtual NodePath traverse(NodePath &parent, DNAStorage *store, int editing=0);
  virtual void write(std::ostream &out, DNAStorage *store, int indent_level = 0) const;

  INLINE void set_width(float width);
  INLINE float get_width() const;

protected:
  bool has_door(PT(DNAGroup) group_vector);
  void setup_suit_flat_building(NodePath &parent, DNAStorage *store);
  void setup_cogdo_flat_building(NodePath &parent, DNAStorage *store);

private:
  virtual DNAGroup* make_copy();

private:
  float _width;

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    DNANode::init_type();
    register_type(_type_handle, "DNAFlatBuilding",
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


////////////////////////////////////////////////////////////////////
//       Class : DNALandmarkBuilding
// Description : A landmark building.
////////////////////////////////////////////////////////////////////
class EXPCL_TOONTOWN DNALandmarkBuilding : public DNANode  {
PUBLISHED:
  DNALandmarkBuilding(const std::string &initial_name = "");
  DNALandmarkBuilding(const DNALandmarkBuilding &building);

  virtual NodePath traverse(NodePath &parent, DNAStorage *store, int editing=0);
  virtual void write(std::ostream &out, DNAStorage *store, int indent_level = 0) const;

  INLINE void set_title(const std::string &title);
  INLINE std::string get_title() const;

  INLINE void set_article(const std::string &article);
  INLINE std::string get_article() const;

  INLINE void set_code(std::string code);
  INLINE std::string get_code() const;

  INLINE void set_wall_color(const LColorf &color);
  INLINE LColorf get_wall_color() const;

  INLINE void set_building_type(const std::string& type);
  INLINE std::string get_building_type() const;

protected:
  void setup_suit_building_origin(NodePath &parent,
    NodePath &building_node_path);

private:
  virtual DNAGroup* make_copy();

protected:
  std::string _code;
  LColorf _wall_color;
  std::string _title;
  std::string _article;
  std::string _building_type;

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    DNANode::init_type();
    register_type(_type_handle, "DNALandmarkBuilding",
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

#include "dnaBuildings.I"

#endif
