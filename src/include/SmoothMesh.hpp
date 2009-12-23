/**
* @file SmoothMesh.hpp
*/
#pragma once

#include "Geometry.hpp"
#include "Object.hpp"
#include <vector>
#include "Material.hpp"
#include <boost/optional.hpp>
#include "Primitive.hpp"

using boost::optional;

namespace peek {

	/**
	* @brief A special type of Object which is a smooth mesh of polygons
	*/
	class SmoothMesh : public Object {
	public:

		/** Constructs a smooth mesh from the provided components and material */
		SmoothMesh(Vertex3d::list verts, Primitive::list primitives, const Material &material);

		/** Constructs a smooth mesh from the provided components using the default material */
		SmoothMesh(Vertex3d::list verts, Primitive::list primitives);

		/** Gets the mesh's material */
		optional<Material> getMaterial() const;

		/** Sets the mesh's material */
		void setMaterial(const Material &material);

		/** Draws the mesh */
		void draw(bool textured) const;

		/** Draws the mesh for picking */
		void pick() const;

		/** Draws the mesh normals */
		void drawNormals(double normalScale) const;

		/** Draws the mesh's vertices */
		void drawVerts() const;

		/** Get the dimensions of the axis-aligned bounding box for the mesh */
		inline Vector3d getDimensions() { return this->boundingBoxHigh - this->boundingBoxLow; }

		/** Get the "low" point of the axis-aligned bounding box for the mesh */
		inline Point3d getBoundingBoxHigh() { return this->boundingBoxHigh; }

		/** Get the "high" point of the axis-aligned bounding box for the mesh */
		inline Point3d getBoundingBoxLow() { return this->boundingBoxLow; }

		typedef handle_traits<SmoothMesh>::handle_type handle;

		typedef list_traits<SmoothMesh::handle>::list_type list;

	protected:

		/** Do the actual work of constructing */
		void construct(Vertex3d::list verts, Primitive::list primitives, const Material &material);

		/** The vertices that compose the mesh */
		Vertex3d::list verts;

		/** The vertex normals */
		Normal3d::list vertNormals;

		/** The faces of the mesh; triangles, quads, etc. */
		Primitive::list primitives;

		/** Generates the normals of the mesh */
		virtual void generateNormals();

		/** The low corner of the axis-aligned bounding box which contains the mesh */
		Point3d boundingBoxLow;

		/** The high corner of the axis-aligned bounding box which contains the mesh */
		Point3d boundingBoxHigh;

		/** (Re)calculates the axis-aligned bounding box for the mesh. */
		void findBoundingBox();

		optional<Material> material;
	};

}