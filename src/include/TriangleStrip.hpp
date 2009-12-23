/**
* @file TriangleStrip.hpp
*/
#pragma once

#include "Geometry.hpp"
#include "Primitive.hpp"

namespace peek {

	/**
	* @brief A triangle strip primitive
	*/
	class TriangleStrip : public Primitive {
	public:

		/** Constructs an empty triangle strip */
		TriangleStrip();

		/** Draws the triangle strip */
		virtual void draw(const Vertex3d::list &verts, const Normal3d::list &normals) const;

		/** Draws the triangle strip for picking */
		virtual void pick(const Vertex3d::list &verts) const;

		/** Adds the triangle strip's normals to the given vertex normals */
		virtual void addVertexNormals(const Vertex3d::list &verts, Normal3d::list &normals) const;

		void addVertex(const Vertex3d::listIndex &v);

		typedef handle_traits<TriangleStrip>::handle_type handle;

		typedef list_traits<TriangleStrip::handle>::list_type list;

	protected:

		/** The vertices of the triangle strip */
		Vertex3d::listIndexList v;

	};

}