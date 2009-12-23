/**
* @file TriangleFan.hpp
*/
#pragma once

#include "Geometry.hpp"
#include "Primitive.hpp"

namespace peek {

	/**
	* @brief A triangle fan primitive
	*/
	class TriangleFan : public Primitive {
	public:

		/** Constructs an empty fan */
		TriangleFan();

		/** Draws the fan */
		virtual void draw(const Vertex3d::list &verts, const Normal3d::list &normals) const;

		/** Draws the fan for picking */
		virtual void pick(const Vertex3d::list &verts) const;

		/** Adds the fan's normal to the given vertex normals */
		virtual void addVertexNormals(const Vertex3d::list &verts, Normal3d::list &normals) const;

		void addVertex(const Vertex3d::listIndex &v);

		typedef handle_traits<TriangleFan>::handle_type handle;

		typedef list_traits<TriangleFan::handle>::list_type list;

	protected:

		/** The vertices of the fan */
		Vertex3d::listIndexList v;

	};

}