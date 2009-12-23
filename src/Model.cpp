/**
* @file Model.cpp
*/
#include "Peek_base.hpp"
#include "Model.hpp"

/* Implementation dependencies */
#include <iostream>

namespace peek {

	Model::Model() {
		this->smoothShading = true;
		this->showSolid = true;
		this->showWireframe = false;
		this->showNormals = false;

		this->normalScale = 0.25;
	}

	/** Draws the model */
	void Model::draw() const {
		glPushMatrix();
		transformModelviewMatrix();

		if(this->showSolid) {
			if(this->showWireframe) {
				glEnable(GL_POLYGON_OFFSET_FILL);
	            glPolygonOffset(1.0, 1.0);
			}
			else {
				glDisable(GL_POLYGON_OFFSET_FILL);
			}

			glEnable(GL_LIGHTING);
			glEnable(GL_CULL_FACE);
			glCullFace(GL_BACK);
			glPolygonMode(GL_FRONT, GL_FILL);
			glPolygonMode(GL_BACK, GL_FILL);
			
			for(SmoothMesh::list::const_iterator i = meshes.begin(); i != meshes.end(); ++i) {
				(*i)->draw(true);
			}
		}

		if(this->showWireframe) {
			if(this->showSolid) {
				glDisable(GL_LIGHTING);
			}
			else {
				glEnable(GL_LIGHTING);
			}

			glEnable(GL_CULL_FACE);
			glCullFace(GL_BACK);
			glPolygonMode(GL_FRONT, GL_LINE);
			glPolygonMode(GL_BACK, GL_LINE);
			
			for(SmoothMesh::list::const_iterator i = meshes.begin(); i != meshes.end(); ++i) {
				(*i)->draw(!this->showSolid);
			}
		}

		if(this->showNormals) {
			glDisable(GL_CULL_FACE);
			for(SmoothMesh::list::const_iterator i = meshes.begin(); i != meshes.end(); ++i) {
				(*i)->drawNormals(this->normalScale);
			}
		}

		glPopMatrix();
	}

	/** Draws the model for picking */
	void Model::pick() const {
		glPushMatrix();
		transformModelviewMatrix();

		for(SmoothMesh::list::const_iterator i = meshes.begin(); i != meshes.end(); ++i) {
			(*i)->pick();
		}

		glPopMatrix();
	}

	/** Draws the vertices */
	void Model::drawVerts() const {
		glPushMatrix();
		transformModelviewMatrix();

		for(SmoothMesh::list::const_iterator i = meshes.begin(); i != meshes.end(); ++i) {
			(*i)->drawVerts();
		}

		glPopMatrix();
	}

	/** Adds a mesh to the model */
	void Model::addMesh(SmoothMesh::handle mesh) {
		meshes.push_back(mesh);

		// Update the bounding box
		for(SmoothMesh::list::const_iterator i = meshes.begin(); i != meshes.end(); ++i) {
			Point3d curMeshBoundingBoxLow = (*i)->getBoundingBoxLow();
			if(curMeshBoundingBoxLow.x < this->boundingBoxLow.x) {
				this->boundingBoxLow.x = curMeshBoundingBoxLow.x;
			}
			if(curMeshBoundingBoxLow.y < this->boundingBoxLow.y) {
				this->boundingBoxLow.y = curMeshBoundingBoxLow.y;
			}
			if(curMeshBoundingBoxLow.z < this->boundingBoxLow.z) {
				this->boundingBoxLow.z = curMeshBoundingBoxLow.z;
			}

			Point3d curMeshBoundingBoxHigh = (*i)->getBoundingBoxHigh();
			if(curMeshBoundingBoxHigh.x < this->boundingBoxHigh.x) {
				this->boundingBoxHigh.x = curMeshBoundingBoxHigh.x;
			}
			if(curMeshBoundingBoxHigh.y < this->boundingBoxHigh.y) {
				this->boundingBoxHigh.y = curMeshBoundingBoxHigh.y;
			}
			if(curMeshBoundingBoxHigh.z < this->boundingBoxHigh.z) {
				this->boundingBoxHigh.z = curMeshBoundingBoxHigh.z;
			}
		}

		// Update normal size based on bounding box size
		this->normalScale = (this->boundingBoxHigh - this->boundingBoxLow).magnitude()/50.0;
	}

}
