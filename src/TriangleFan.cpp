/**
* @file TriangleFan.cpp
*/
#include "Peek_base.hpp"
#include "TriangleFan.hpp"

namespace peek {

	/**
	*/
	TriangleFan::TriangleFan() {}

	/**
	*/
	void TriangleFan::draw(const Vertex3d::list &verts, const Normal3d::list &normals) const {
		glBegin(GL_TRIANGLE_FAN);

		for(Vertex3d::listIndex i = 0; i < this->v.size(); i++) {
			glNormal3d(normals[this->v[i]].x, normals[this->v[i]].y, normals[this->v[i]].z);
			glVertex3d(verts[this->v[i]].x, verts[this->v[i]].y, verts[this->v[i]].z);
		}

		glEnd();
	}

	/**
	*/
	void TriangleFan::pick(const Vertex3d::list &verts) const {
		glBegin(GL_TRIANGLE_FAN);

		for(Vertex3d::listIndex i = 0; i < this->v.size(); i++) {
			glVertex3d(verts[this->v[i]].x, verts[this->v[i]].y, verts[this->v[i]].z);
		}

		glEnd();
	}

	/**
	*/
	void TriangleFan::addVertexNormals(const Vertex3d::list &verts, Normal3d::list &normals) const {
		//Calculate the triangle's normal via Newell's method
		for(Vertex3d::listIndex i = 1; i < this->v.size()-1; i++) {
			double mx = 0, my = 0, mz = 0;

			mx += (verts[this->v[0]].y - verts[this->v[i]].y)*(verts[this->v[0]].z + verts[this->v[i]].z);
			my += (verts[this->v[0]].z - verts[this->v[i]].z)*(verts[this->v[0]].x + verts[this->v[i]].x);
			mz += (verts[this->v[0]].x - verts[this->v[i]].x)*(verts[this->v[0]].y + verts[this->v[i]].y);

			mx += (verts[this->v[i]].y - verts[this->v[i+1]].y)*(verts[this->v[i]].z + verts[this->v[i+1]].z);
			my += (verts[this->v[i]].z - verts[this->v[i+1]].z)*(verts[this->v[i]].x + verts[this->v[i+1]].x);
			mz += (verts[this->v[i]].x - verts[this->v[i+1]].x)*(verts[this->v[i]].y + verts[this->v[i+1]].y);

			mx += (verts[this->v[i+1]].y - verts[this->v[0]].y)*(verts[this->v[i+1]].z + verts[this->v[0]].z);
			my += (verts[this->v[i+1]].z - verts[this->v[0]].z)*(verts[this->v[i+1]].x + verts[this->v[0]].x);
			mz += (verts[this->v[i+1]].x - verts[this->v[0]].x)*(verts[this->v[i+1]].y + verts[this->v[0]].y);

			Normal3d normal(mx, my, mz);
			normal.normalize();

			// Add the normal to the triangle's vertex normals
			normals[this->v[0]] += normal;
			normals[this->v[i]] += normal;
			normals[this->v[i+1]] += normal;
		}
	}

	void TriangleFan::addVertex(const Vertex3d::listIndex &v) {
		this->v.push_back(v);
	}
}
