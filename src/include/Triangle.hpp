/**
* @file Triangle.hpp
*/
#pragma once

#include "Geometry.hpp"
#include "Primitive.hpp"

namespace peek {

	/**
	* @brief A triangle primitive
	*/
	class Triangle : public Primitive {
	public:

		/** Constructs a triangle with get given vertices */
		Triangle(Vertex3d::listIndex v0, Vertex3d::listIndex v1, Vertex3d::listIndex v2);

		/** Draws the triangle */
		virtual void draw(const Vertex3d::list &verts, const Normal3d::list &normals) const;

		/** Draws the triangle for picking */
		virtual void pick(const Vertex3d::list &verts) const;

		/** Adds the triangle's normal to the given vertex normals */
		virtual void addVertexNormals(const Vertex3d::list &verts, Normal3d::list &normals) const;

		typedef handle_traits<Triangle>::handle_type handle;

		typedef list_traits<Triangle::handle>::list_type list;

	protected:

		/** The vertices of the triangle */
		Vertex3d::listIndex v0, v1, v2;

	};

}