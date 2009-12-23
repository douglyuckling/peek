/**
 * \file GlWrappers.h
 * \author Douglas W. Paul
 *
 * Defines some functions to ease the use of geometric primitives with OpenGL
 */

#pragma once

#include "Peek_base.hpp"
#include "Geometry.hpp"
#include "Color.hpp"

namespace peek {

	/**
	 * \param p The point to give as an OpenGL vertex
	 */
	inline void pkGlVertex(Point3d p) {
		glVertex3d(p.x, p.y, p.z);
	}

	/**
	 * \param v The vector to give as an OpenGL normal
	 */
	inline void pkGlNormal(Vector3d v) {
		glNormal3d(v.x, v.y, v.z);
	}

	/**
	 * \param c The color to give as an OpenGL color
	 */
	inline void pkGlColor(Color c) {
		glColor3fv(c.c);
	}

	/**
	 * \param c The color to give as an OpenGL color
	 */
	inline void pkGlClearColor(Color c, float alpha) {
		glClearColor(c.c[0], c.c[1], c.c[2], alpha);
	}

}