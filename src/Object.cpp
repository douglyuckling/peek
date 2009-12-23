/**
 * @file Object.cpp
 */
#include "Peek_base.hpp"
#include "Object.hpp"

namespace peek {

/*!
 */
Object::Object() {
	this->scale = 1.0;
}

/*!
 */
void Object::transformModelviewMatrix() const {
  glMatrixMode(GL_MODELVIEW);
  glScaled(this->scale, this->scale, this->scale);
  glRotated(this->rotation.z, 0, 0, 1);
  glRotated(this->rotation.y, 0, 1, 0);
  glRotated(this->rotation.x, 1, 0, 0);
  glTranslated(this->origin.x, this->origin.y, this->origin.z);
}

}