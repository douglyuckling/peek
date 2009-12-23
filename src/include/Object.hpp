/**
 * @file Object.hpp
 */
#pragma once

#include "Geometry.hpp"

namespace peek {

/**
 * @brief A three-dimensional object
 */
class Object {
 public:

  /** Constructor */
  Object();

  /** Destructor */
  virtual ~Object() {}

  /** Gets the origin */
  inline Vector3d getOrigin() const {return this->origin;}

  /** Sets the origin */
  inline void setOrigin(Vector3d origin) { this->origin = origin; }

  /** Gets the rotation */
  inline Vector3d getRotation() const {return this->rotation;}

  /** Sets the rotation */
  inline void setRotation(Vector3d rotation) { this->rotation = rotation; }

  /** Gets the scaling factor */
  inline double getScale() const {return this->scale;}

  /** Sets the scaling factor */
  inline void setScale(double scale) {this->scale = scale;}

 protected:

  /** The object's translation */
  Vector3d origin;

  /** The objects rotation */
  Vector3d rotation;

  /** The object's scaling factor */
  double scale;

  /** Transforms the modelview matrix */
  void transformModelviewMatrix() const;

};

}