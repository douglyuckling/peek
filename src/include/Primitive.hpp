/**
* @file Primitive.hpp
*/
#pragma once

#include <vector>
#include <handle_traits.hpp>
#include <list_traits.hpp>
#include "Geometry.hpp"

using std::vector;
using boost::shared_ptr;

namespace peek {

	/**
	* @interface Primitive
	* @brief A primitive
	*/
	class Primitive {
	public:

		/** Draws the primitive */
		virtual void draw(const Vertex3d::list &verts, const Normal3d::list &normals) const = 0;

		/** Draws the primitive for picking */
		virtual void pick(const Vertex3d::list &verts) const = 0;

		/** Adds the normals of the primitives' faces to the given vertex normals */
		virtual void addVertexNormals(const Vertex3d::list &verts, Normal3d::list &normals) const = 0;

		typedef handle_traits<Primitive>::handle_type handle;

		typedef list_traits<Primitive::handle>::list_type list;

	};

}