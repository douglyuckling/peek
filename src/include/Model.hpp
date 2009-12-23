/**
* @file Model.hpp
*/
#pragma once

#include "Geometry.hpp"
#include "Object.hpp"
#include "SmoothMesh.hpp"
#include "handle_traits.hpp"
#include "list_traits.hpp"

namespace peek {

	class Model : public Object {
	public:

		/** Constructor */
		Model();

		/** Draws the model */
		void draw() const;

		/** Draws the model for picking */
		void pick() const;

		/** Draws the vertices */
		void drawVerts() const;

		/** Increases the size of the (visible) normals */
		void increaseNormalScale() { this->normalScale *= 2.0; }

		/** Decreases the size of the (visible) normals */
		void decreaseNormalScale() { this->normalScale /= 2.0; }

		/** Adds a mesh to the model */
		void addMesh(SmoothMesh::handle mesh);

		/** Toggles smooth shading on and off */
		void toggleSmoothShading() { this->smoothShading = !this->smoothShading; }

		/** Toggles visibility of solid geometry */
		void toggleShowSolidGeometry() { this->showSolid = !this->showSolid; }

		/** Toggles visibility of the wireframe */
		void toggleShowWireframe() { this->showWireframe = !this->showWireframe; }

		/** Toggles visibility of face/vector normals */
		void toggleShowNormals() { this->showNormals = !this->showNormals; }

				/** Get the dimensions of the axis-aligned bouding box for the polygon mesh */
		inline Vector3d getDimensions() { return this->boundingBoxHigh - this->boundingBoxLow; }

		typedef handle_traits<Model>::handle_type handle;

		typedef list_traits<Model::handle>::list_type list;

	protected:

		SmoothMesh::list meshes;

		/** Whether or not smooth shading is enabled */
		bool smoothShading;

		/** Whether or not solid geometry is visible */
		bool showSolid;

		/** Whether or not the wireframe is visible */
		bool showWireframe;

		/** Whether or not normals are visible */
		bool showNormals;

		/** The scale at which to draw the normals */
		double normalScale;

		/** The low corner of the axis-aligned bounding box which contains the mesh */
		Point3d boundingBoxLow;

		/** The high corner of the axis-aligned bounding box which contains the mesh */
		Point3d boundingBoxHigh;

		/** (Re)calculates the axis-aligned bounding box for the mesh. */
		void findBoundingBox();

	};

}
