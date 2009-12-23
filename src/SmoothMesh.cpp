/**
* @file SmoothMesh.cpp
*/
#include "Peek_base.hpp"
#include "SmoothMesh.hpp"
#include <limits>

namespace peek {

	/*!
	* @param verts The list of vertices that compose the model
	* @param primitives The list of primitives that compose the model
	* @param material The material to render the model with
	*/
	SmoothMesh::SmoothMesh(Vertex3d::list verts, Primitive::list primitives, const Material &material) {
		construct(verts, primitives, material);
	}

	/*!
	* @param verts The list of vertices that compose the model
	* @param primitives The list of primitives that compose the model
	*/
	SmoothMesh::SmoothMesh(Vertex3d::list verts, Primitive::list primitives) {
		construct(verts, primitives, Material::DEFAULT);
	}

	/*!
	* @param verts The list of vertices that compose the model
	* @param primitives The list of primitives that compose the model
	* @param material The material to render the model with
	*/
	void SmoothMesh::construct(Vertex3d::list verts, Primitive::list primitives, const Material &material) {
		this->verts = verts;
		this->primitives = primitives;
		this->material = material;

		generateNormals();
		findBoundingBox();
	}

	/*!
	*/
	optional<Material> SmoothMesh::getMaterial() const {
		return this->material;
	}

	/*!
	*/
	void SmoothMesh::setMaterial(const Material &material) {
		this->material = material;
	}

	/*!
	*/
	void SmoothMesh::draw(bool textured) const {
		glPushMatrix();
		transformModelviewMatrix();

		if(textured && material) {
			useMaterial(GL_FRONT, *material);
		}
		else {
			glColor3f(0.5, 0.5, 0.5);
		}


		for(Primitive::list::const_iterator i = this->primitives.begin(); i < this->primitives.end(); ++i) {
			(*i)->draw(this->verts, this->vertNormals);
		}

		glPopMatrix();
	}

	/*!
	*/
	void SmoothMesh::pick() const {
		glPushMatrix();
		transformModelviewMatrix();

		// \todo Do we need to worry about lighting mode, etc, here?

		for(Primitive::list::const_iterator i = this->primitives.begin(); i < this->primitives.end(); ++i) {
			(*i)->pick(this->verts);
		}

		glPopMatrix();
	}

	/*!
	*/
	void SmoothMesh::drawNormals(double normalScale) const {
		glPushMatrix();
		transformModelviewMatrix();

		// Disable lighting for drawing normals
		glDisable(GL_LIGHTING);
		glColor3f(1.0, 0.0, 0.0);

		glBegin(GL_LINES);

		for(Vertex3d::listIndex i=0; i < this->verts.size(); i++) {
			glVertex3d(this->verts[i].x, this->verts[i].y, this->verts[i].z);
			glVertex3d(this->verts[i].x + normalScale * this->vertNormals[i].x,
				this->verts[i].y + normalScale * this->vertNormals[i].y,
				this->verts[i].z + normalScale * this->vertNormals[i].z);
		}

		glEnd();
		glPopMatrix();
	}

	/*!
	*/
	void SmoothMesh::drawVerts() const {
		glPushMatrix();
		transformModelviewMatrix();

		// Disable lighting for drawing vertices
		glDisable(GL_LIGHTING);
		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_POINTS);
		for(Vertex3d::listIndex i=0; i < this->verts.size(); i++) {
			glVertex3d(this->verts[i].x, this->verts[i].y, this->verts[i].z);
		}
		glEnd();

		glPopMatrix();
	}

	/*!
	*/
	void SmoothMesh::generateNormals() {
		this->vertNormals.resize(this->verts.size());

		for(Primitive::list::const_iterator i = this->primitives.begin(); i < this->primitives.end(); ++i) {
			(*i)->addVertexNormals(this->verts, this->vertNormals);
		}

		for(Normal3d::listIndex i=0; i < this->vertNormals.size(); i++) {
			this->vertNormals[i].normalize();
		}
	}

	/*!
	*/
	void SmoothMesh::findBoundingBox() {
		double lowX, lowY, lowZ, highX, highY, highZ;

		lowX = lowY = lowZ = numeric_limits<double>::infinity();
		highX = highY = highZ = -numeric_limits<double>::infinity();

		for(Vertex3d::listIndex i=0; i < this->verts.size(); i++) {
			if(this->verts[i].x < lowX)
				lowX = this->verts[i].x;
			if(this->verts[i].x > highX)
				highX = this->verts[i].x;
			if(this->verts[i].y < lowY)
				lowY = this->verts[i].y;
			if(this->verts[i].y > highY)
				highY = this->verts[i].y;
			if(this->verts[i].z < lowZ)
				lowZ = this->verts[i].z;
			if(this->verts[i].z > highZ)
				highZ = this->verts[i].z;
		}

		this->boundingBoxLow.set(lowX, lowY, lowZ);
		this->boundingBoxHigh.set(highX, highY, highZ);
	}

}