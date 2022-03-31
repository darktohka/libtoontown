// Filename: dnaStorage.h
// Created by:  shochet (29Mar00)
//
////////////////////////////////////////////////////////////////////

#ifndef DNASTORAGE_H
#define DNASTORAGE_H

#include "toontownbase.h"
#include "texture.h"
#include "pandaNode.h"
#include "nodePath.h"
#include "textFont.h"
#include "luse.h"
#include "pvector.h"
#include "plist.h"
#include "pset.h"

#include "dnaGroup.h"
#include "dnaVisGroup.h"
#include "dnaSuitPoint.h"
#include "dnaSuitEdge.h"
#include "dnaSuitPath.h"
#include "dnaBattleCell.h"

//////////////////////////////////////////////////
// Global part storage
//////////////////////////////////////////////////

struct PosHpr {
PUBLISHED:
  PosHpr(const LPoint3f& pos=LPoint3f(0),
      const LPoint3f& hpr=LPoint3f(0)) :
      _pos(pos),
      _hpr(hpr) {
  }
  const LPoint3f& get_pos() const { return _pos; }
  const LPoint3f& get_hpr() const { return _hpr; }
private:
  LPoint3f _pos;
  LPoint3f _hpr;
};
typedef pset< std::string > CodeSet;
typedef pmap< std::string, CodeSet > CodeCatalog;
typedef pmap< std::string, PT(Texture) > TextureMap;
typedef pmap< std::string, PT(TextFont) > FontMap;
typedef pmap< int, int > BlockToZoneMap;
typedef pmap< int, PosHpr > BlockToPosHprMap;
typedef pmap< int, LMatrix4f > BlockToTransformMap;
typedef pmap< int, std::string > BlockToTitleMap;
typedef pmap< int, std::string > BlockToArticleMap;
typedef pmap< int, std::string > BlockToBuildingTypeMap;
typedef pmap< std::string, NodePath > NodeMap;
typedef pmap< PT(PandaNode), PT(DNAGroup) > Node2GroupMap;
typedef pmap< PT(PandaNode), PT(DNAVisGroup) > Node2VisGroupMap;

// Stored primarily for the AI who does not traverse
// but still needs the vis groups
typedef pvector< PT(DNAVisGroup) > VisGroupVectorAI;

// Stores the Suit points in a vector
typedef pvector< PT(DNASuitPoint) > SuitPointVector;

// Stores all the edges in a vector
typedef pvector< PT(DNASuitEdge) > SuitEdgeVector;

// Stores all the suit point indexes with each one's
// corresponding edges for ease of traversal
typedef pmap< int, SuitEdgeVector > SuitStartPointMap;

// Stores all the suit point indexes with each one's
// corresponding edges for ease of traversal
typedef pmap< int, PT(DNASuitPoint) > SuitPointMap;

// Stores all the battle cells in a vector
typedef pvector< PT(DNABattleCell) > BattleCellVector;


class EXPCL_TOONTOWN DNAStorage {
PUBLISHED:
  DNAStorage();

  // Storage functions
  void print_node_storage() const;
  void print_texture_storage() const;
  void print_font_storage() const;
  void print_suit_point_storage() const;
  void print_battle_cell_storage() const;
  void store_texture(const std::string &code_string, PT(Texture) texture);
  void store_font(const std::string &code_string, PT(TextFont) font);
  INLINE void store_node(const std::string &code_string, NodePath node, const std::string &code_category = "");
  INLINE void store_hood_node(const std::string &code_string, NodePath node, const std::string &code_category = "");
  INLINE void store_place_node(const std::string &code_string, NodePath node, const std::string &code_category = "");
  PT(DNASuitPoint) store_suit_point(DNASuitPoint::DNASuitPointType type, LPoint3f pos);
  int store_suit_point(PT(DNASuitPoint));
  int get_highest_suit_point_index();
  int remove_suit_point(PT(DNASuitPoint));
  void store_block_number(const std::string& block, const std::string& zone_id);
  void store_block_door_pos_hpr(const std::string& block, const LPoint3f& pos, const LPoint3f& hpr);
  void store_block_sign_transform(const std::string& block, const LMatrix4f& mat);
  void store_block_title(const std::string& block, const std::string& title);
  void store_block_article(const std::string& block, const std::string& article);
  void store_battle_cell(PT(DNABattleCell));
  int remove_battle_cell(PT(DNABattleCell));
  PT(DNASuitEdge) store_suit_edge(int start_index, int end_index, std::string zone_id);
  PT(DNASuitEdge) store_suit_edge(PT(DNASuitEdge));
  int remove_suit_edge(PT(DNASuitEdge));
  int delete_unused_suit_points();
  int fix_coincident_suit_points();

  // Reset functions
  INLINE void reset_nodes();
  INLINE void reset_textures();

  // Reset everything associated with this hood
  INLINE void reset_hood();

  // These all get called by reset hood
  INLINE void reset_hood_nodes();
  INLINE void reset_place_nodes();
  INLINE void reset_suit_points();
  INLINE void reset_battle_cells();
  INLINE void reset_block_numbers();
  INLINE void reset_block_door_pos_hprs();
  INLINE void reset_block_sign_transforms();
  INLINE void reset_block_title();
  INLINE void reset_block_article();

  // Searching functions
  PT(Texture) find_texture(const std::string &dna_string) const;
  NodePath find_node(const std::string &dna_string) const;
  PT(TextFont) find_font(const std::string &dna_string) const;

  // Catalog functions
  int get_num_catalog_codes(const std::string &catalog_string) const;
  std::string get_catalog_code(const std::string &catalog_string, int i) const ;
  void store_catalog_string(const std::string &catalog_string, const std::string &dna_string);
  void print_catalog() const;

  // DNAGroup functions
  void store_DNAGroup(PT(PandaNode), PT(DNAGroup));
  int remove_DNAGroup(PT(PandaNode));
  int remove_DNAGroup(PT(DNAGroup));
  PT(DNAGroup)     find_DNAGroup(PT(PandaNode)) const;
  PT(PandaNode) find_PandaNode(PT(DNAGroup)) const;

  // Block number functions
  int get_zone_from_block_number(int block_number) const;
  int get_block_number_at(unsigned int index) const;
  int get_num_block_numbers() const;

  // Block door pos hpr functions
  const PosHpr& get_door_pos_hpr_from_block_number(int block_number) const;
  int get_door_pos_hpr_block_at(unsigned int index) const;
  int get_num_block_door_pos_hprs() const;

  // Block sign pos hpr functions
  const LMatrix4f& get_sign_transform_from_block_number(int block_number) const;
  int get_sign_transform_block_at(unsigned int index) const;
  int get_num_block_sign_transforms() const;

  INLINE void reset_DNAGroups();

  // Block title functions
  std::string get_title_from_block_number(int block_number) const;
  int get_title_block_at(unsigned int index) const;
  int get_num_block_titles() const;

  // Block article functions
  std::string get_article_from_block_number(int block_number) const;

  // Block building type functions
  void store_block_building_type(const std::string& block, const std::string& type);
  std::string get_block_building_type(int block_number) const;

  // VisGroup functions
  INLINE void store_DNAVisGroup(PT(PandaNode), PT(DNAVisGroup));
  INLINE int remove_DNAVisGroup(PT(PandaNode));
  PT(DNAVisGroup) find_DNAVisGroup(PT(PandaNode)) const;
  INLINE void reset_DNAVisGroups();
  INLINE int get_num_DNAVisGroups() const;
  PT(DNAVisGroup) get_DNAVisGroup(unsigned int i) const;
  int get_num_visibles_in_DNAVisGroup(unsigned int i) const;
  std::string get_DNAVisGroup_name(unsigned int i) const;
  std::string get_visible_name(unsigned int visgroup_index, unsigned int visible_index) const;

  // For the AI, he does not traverse but still needs vis groups
  void store_DNAVisGroupAI(PT(DNAVisGroup));
  INLINE int get_num_DNAVisGroupsAI() const;
  INLINE PT(DNAVisGroup) get_DNAVisGroupAI(unsigned int i) const;
  INLINE void reset_DNAVisGroupsAI();

  // Node relation functions
  INLINE int get_num_PandaNodes() const;
  PT(PandaNode) get_PandaNode_at(unsigned int i) const;
  void print_PandaNodes() const;

  // Suit point functions
  std::string get_suit_edge_zone(int start_index, int end_index) const;
  float get_suit_edge_travel_time(int start_index, int end_index, float rate) const;
  INLINE int get_num_suit_points() const;
  INLINE PT(DNASuitPoint) get_suit_point_at_index(int index) const;
  INLINE PT(DNASuitPoint) get_suit_point_with_index(int index) const;
  PT(DNASuitPath) get_suit_path(const DNASuitPoint *start_point,
                                const DNASuitPoint *end_point,
                                int min_length, int max_length) const;
  PT(DNASuitPath) get_adjacent_points(PT(DNASuitPoint) start_point) const;
  int discover_continuity();

  // Wall height functions
  INLINE float get_current_wall_height() const;
  INLINE void set_current_wall_height(float current_wall_height);
  INLINE void add_wall_height(float wall_height);

  std::string get_block(const std::string& name) const;

  void fixup();
  void write(std::ostream &out, int indent_level) const;

public:

  class WorkingSuitPath : public ReferenceCount {
  public:
    INLINE WorkingSuitPath(int point_index);
    INLINE WorkingSuitPath(WorkingSuitPath *next, int point_index);
    INLINE ~WorkingSuitPath();
    INLINE int get_point_index() const;

    void get_path(DNASuitPath *path) const;
    void output(std::ostream &out) const;
    void write(std::ostream &out) const;

    // We will allocate and destroy many of these a each time we compute
    // a new suit path.  As an optimization, then, we implement operator
    // new and delete here to minimize this overhead.
    INLINE void *operator new(size_t size);
    INLINE void operator delete(void *ptr);

    // See the comments at the beginning of
    // get_suit_path_breadth_first for a description of the difference
    // between these three pointers.
    PT(WorkingSuitPath) _next_in_path;
    PT(WorkingSuitPath) _next_in_chain;
    WorkingSuitPath *_next_deleted;
    int _point_index;

    static WorkingSuitPath *_deleted_chain;
  };

private:


  CodeCatalog _code_catalog;
  TextureMap _texture_map;
  NodeMap _node_map;
  FontMap _font_map;
  NodeMap _hood_node_map;
  BlockToZoneMap _block_map;
  BlockToPosHprMap _block_door_pos_hpr_map;
  BlockToTransformMap _block_sign_transform_map;
  BlockToTitleMap _block_title_map;
  BlockToArticleMap _block_article_map;
  BlockToBuildingTypeMap _block_building_type_map;
  NodeMap _place_node_map;
  Node2GroupMap _n2group_map;
  Node2VisGroupMap _n2visgroup_map;

  void r_discover_connections(DNASuitPoint *point, int graph_id);

  PT(DNASuitEdge) get_suit_edge(int start_index, int end_index) const;
  PT(DNASuitPath)
    get_suit_path_breadth_first(const DNASuitPoint *start_point,
                                const DNASuitPoint *end_point,
                                int min_length, int max_length) const;
  void
  generate_next_suit_path_chain(PT(DNAStorage::WorkingSuitPath) &chain) const;
  bool
  consider_next_suit_path_chain(PT(DNAStorage::WorkingSuitPath) &chain,
                                const DNASuitPoint *end_point,
                                pset<int> visited_points) const;

  SuitPointVector _suit_point_vector;
  SuitPointMap _suit_point_map;
  SuitStartPointMap _suit_start_point_map;
  BattleCellVector _battle_cell_vector;
  VisGroupVectorAI _vis_group_vector;
  float _current_wall_height = 0.0;

};

#include "dnaStorage.I"

#endif
