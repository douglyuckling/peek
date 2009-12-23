/**
* @file Triangle.cpp
*/
#include "Peek_base.hpp"
#include "Triangle.hpp"

namespace peek {

	/*!
	* @param v0 The first vertex of the triangle
	* @param v1 The second vertex of the triangle
	* @param v2 The third vertex of the triangle
	*/
	Triangle::Triangle(Vertex3d::listIndex v0, Vertex3d::listIndex v1, Vertex3d::listIndex v2) {
		this->v0 = v0;
		this->v1 = v1;
		this->v2 = v2;
	}

	/*!
	*/
	void Triangle::draw(const Vertex3d::list &verts, const Normal3d::list &normals) const {
		glBegin(GL_TRIANGLES);

		glNormal3d(normals[v0].x, normals[v0].y, normals[v0].z);
		glVertex3d(verts[v0].x, verts[v0].y, verts[v0].z);

		glNormal3d(normals[v1].x, normals[v1].y, normals[v1].z);
		glVertex3d(verts[v1].x, verts[v1].y, verts[v1].z);

		glNormal3d(normals[v2].x, normals[v2].y, normals[v2].z);
		glVertex3d(verts[v2].x, verts[v2].y, verts[v2].z);

		glEnd();
	}

	/*!
	*/
	void Triangle::pick(const Vertex3d::list &verts) const {
		glBegin(GL_TRIANGLES);

		glVertex3d(verts[v0].x, verts[v0].y, verts[v0].z);
		glVertex3d(verts[v1].x, verts[v1].y, verts[v1].z);
		glVertex3d(verts[v2].x, verts[v2].y, verts[v2].z);

		glEnd();
	}

	/*!
	*/
	void Triangle::addVertexNormals(const Vertex3d::list &verts, Normal3d::list &normals) const {
		//Calculate the triangle's normal via Newell's method
		double mx = 0, my = 0, mz = 0;

		mx += (verts[v0].y - verts[v1].y)*(verts[v0].z + verts[v1].z);
		my += (verts[v0].z - verts[v1].z)*(verts[v0].x + verts[v1].x);
		mz += (verts[v0].x - verts[v1].x)*(verts[v0].y + verts[v1].y);

		mx += (verts[v1].y - verts[v2].y)*(verts[v1].z + verts[v2].z);
		my += (verts[v1].z - verts[v2].z)*(verts[v1].x + verts[v2].x);
		mz += (verts[v1].x - verts[v2].x)*(verts[v1].y + verts[v2].y);

		mx += (verts[v2].y - verts[v0].y)*(verts[v2].z + verts[v0].z);
		my += (verts[v2].z - verts[v0].z)*(verts[v2].x + verts[v0].x);
		mz += (verts[v2].x - verts[v0].x)*(verts[v2].y + verts[v0].y);

		Normal3d normal(mx, my, mz);
		normal.normalize();

		// Add the normal to the triangle's vertex normals
		normals[v0] += normal;
		normals[v1] += normal;
		normals[v2] += normal;
	}

}
