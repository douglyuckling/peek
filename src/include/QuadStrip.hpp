/**
* @file QuadStrip.hpp
*/
#pragma once

#include "Geometry.hpp"
#include "Primitive.hpp"

namespace peek {

	/**
	* @brief A quad strip primitive
	*/
	class QuadStrip : public Primitive {
	public:

		/** Constructs an empty quad strip */
		QuadStrip();

		/** Draws the quad strip */
		virtual void draw(const Vertex3d::list &verts, const Normal3d::list &normals) const;

		/** Draws the quad strip for picking */
		virtual void pick(const Vertex3d::list &verts) const;

		/** Adds the quad strip's normal to the given vertex normals */
		virtual void addVertexNormals(const Vertex3d::list &verts, Normal3d::list &normals) const;

		void addVertex(const Vertex3d::listIndex &v);

		typedef handle_traits<QuadStrip>::handle_type handle;

		typedef list_traits<QuadStrip::handle>::list_type list;

	protected:

		/** The vertices of the quad strip */
		Vertex3d::listIndexList v;

	};

}