/**
* @file Quadrilateral.hpp
*/
#pragma once

#include "Geometry.hpp"
#include "Primitive.hpp"

namespace peek {

	/**
	* @brief A quadrilateral primitive
	*/
	class Quadrilateral : public Primitive {
	public:

		/** Constructs a quadrilateral with get given vertices */
		Quadrilateral(Vertex3d::listIndex v0, Vertex3d::listIndex v1, Vertex3d::listIndex v2, Vertex3d::listIndex v3);

		/** Draws the quadrilateral */
		virtual void draw(const Vertex3d::list &verts, const Normal3d::list &normals) const;

		/** Draws the quadrilateral for picking */
		virtual void pick(const Vertex3d::list &verts) const;

		/** Adds the quadrilateral's normal to the given vertex normals */
		virtual void addVertexNormals(const Vertex3d::list &verts, Normal3d::list &normals) const;

		typedef handle_traits<Quadrilateral>::handle_type handle;

		typedef list_traits<Quadrilateral::handle>::list_type list;

	protected:

		/** The vertices of the quadrilateral */
		Vertex3d::listIndex v0, v1, v2, v3;

	};

}