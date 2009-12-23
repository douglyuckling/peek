/**
* @file QuadStrip.cpp
*/
#include "Peek_base.hpp"
#include "QuadStrip.hpp"

namespace peek {

	/**
	*/
	QuadStrip::QuadStrip() {}

	/**
	*/
	void QuadStrip::draw(const Vertex3d::list &verts, const Normal3d::list &normals) const {
		glBegin(GL_QUAD_STRIP);

		for(Vertex3d::listIndex i = 0; i < this->v.size(); i++) {
			glNormal3d(normals[this->v[i]].x, normals[this->v[i]].y, normals[this->v[i]].z);
			glVertex3d(verts[this->v[i]].x, verts[this->v[i]].y, verts[this->v[i]].z);
		}

		glEnd();
	}

	/**
	*/
	void QuadStrip::pick(const Vertex3d::list &verts) const {
		glBegin(GL_QUAD_STRIP);

		for(Vertex3d::listIndex i = 0; i < this->v.size(); i++) {
			glVertex3d(verts[this->v[i]].x, verts[this->v[i]].y, verts[this->v[i]].z);
		}

		glEnd();
	}

	/**
	*/
	void QuadStrip::addVertexNormals(const Vertex3d::list &verts, Normal3d::list &normals) const {
		//Calculate the triangle's normal via Newell's method
		for(Vertex3d::listIndex i = 0; i < this->v.size()-2; i+=2) {
			double mx = 0, my = 0, mz = 0;
			
			mx += (verts[this->v[i]].y - verts[this->v[i+1]].y)*(verts[this->v[i]].z + verts[this->v[i+1]].z);
			my += (verts[this->v[i]].z - verts[this->v[i+1]].z)*(verts[this->v[i]].x + verts[this->v[i+1]].x);
			mz += (verts[this->v[i]].x - verts[this->v[i+1]].x)*(verts[this->v[i]].y + verts[this->v[i+1]].y);

			mx += (verts[this->v[i+1]].y - verts[this->v[i+3]].y)*(verts[this->v[i+1]].z + verts[this->v[i+3]].z);
			my += (verts[this->v[i+1]].z - verts[this->v[i+3]].z)*(verts[this->v[i+1]].x + verts[this->v[i+3]].x);
			mz += (verts[this->v[i+1]].x - verts[this->v[i+3]].x)*(verts[this->v[i+1]].y + verts[this->v[i+3]].y);

			mx += (verts[this->v[i+3]].y - verts[this->v[i+2]].y)*(verts[this->v[i+3]].z + verts[this->v[i+2]].z);
			my += (verts[this->v[i+3]].z - verts[this->v[i+2]].z)*(verts[this->v[i+3]].x + verts[this->v[i+2]].x);
			mz += (verts[this->v[i+3]].x - verts[this->v[i+2]].x)*(verts[this->v[i+3]].y + verts[this->v[i+2]].y);

			mx += (verts[this->v[i+2]].y - verts[this->v[i]].y)*(verts[this->v[i+2]].z + verts[this->v[i]].z);
			my += (verts[this->v[i+2]].z - verts[this->v[i]].z)*(verts[this->v[i+2]].x + verts[this->v[i]].x);
			mz += (verts[this->v[i+2]].x - verts[this->v[i]].x)*(verts[this->v[i+2]].y + verts[this->v[i]].y);

			Normal3d normal(mx, my, mz);
			normal.normalize();

			// Add the normal to the triangle's vertex normals
			normals[this->v[i]] += normal;
			normals[this->v[i+1]] += normal;
			normals[this->v[i+2]] += normal;
			normals[this->v[i+3]] += normal;
		}
	}

	void QuadStrip::addVertex(const Vertex3d::listIndex &v) {
		this->v.push_back(v);
	}
}
