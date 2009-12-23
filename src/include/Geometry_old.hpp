/**
 * \file Geometry.hpp
 * \author Douglas W. Paul
 *
 * Declares data types and operations for basic geometry
 *
 * This file is somewhat messy and should probably be cleaned up.  It's nice to
 * have all of the geometric definitions in one file, but it's quite bloated now.
 */

#pragma once

#include <cmath>
#include <vector>
#include <iostream>
#include "list_traits.hpp"
#include "Numerics.hpp"
#include "Set.hpp"

namespace peek {

	// Pre-declare the classes so that they can reference each other freely.
	class Point3d;
	class Vector3d;

	/**
	 * A vector in three-dimensional space
	 *
	 * Stores a vector and defines common vector operations.
	 */
	class Vector3d  {
	public:

		/** x-parameter of the vector */
		double x;

		/** y-parameter of the vector */
		double y;

		/** z-parameter of the vector */
		double z;

		/** homogeneous parameter (0 for vectors) */
		double h;

	public:

		/** Constructs a default three-dimensional vector (all zeroes) */
		inline Vector3d() {
			this->x = 0;
			this->y = 0;
			this->z = 0;
			this->h = 0;
		}

		/** Constructs a three-dimensional vector from the given scalar components */
		inline Vector3d(double x, double y, double z) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->h = 0;
		}

		/** Constructs a three-dimensional vector from the corresponding scalar components in a Point3d */
		Vector3d(const Point3d &p);

		/** Assignment */
		inline Vector3d& operator=(const Vector3d& rhs){
			this->x = rhs.x;
			this->y = rhs.y;
			this->z = rhs.z;
			this->h = rhs.h;
			return *this;
		}

		/** Negates a vector */
		inline Vector3d operator-() const {
			Vector3d v;
			v.x = -this->x;
			v.y = -this->y;
			v.z = -this->z;
			return v;
		}

		/** Sets the scalar components of the vector */
		inline void set(double x, double y, double z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		/** Sets the scalar components of the vector from an array of scalars in x-y-z order */
		inline void set(double v[3]) {
			this->x = v[0];
			this->y = v[1];
			this->z = v[2];
		}

		/** Increments one vector by another */
		inline Vector3d& operator+=(const Vector3d& rhs) {
			this->x += rhs.x;
			this->y += rhs.y;
			this->z += rhs.z;
			return *this;
		}

		/** Decrements one vector by another */
		inline Vector3d& operator-=(const Vector3d& rhs) {
			this->x -= rhs.x;
			this->y -= rhs.y;
			this->z -= rhs.z;
			return *this;
		}

		/** Per-element multiplication of one vector by another */
		inline Vector3d &operator*=(const Vector3d &rhs) {
			this->x *= rhs.x;
			this->y *= rhs.y;
			this->z *= rhs.z;
			return *this;
		}

		/** Calculates the magnitude of the vector */
		inline double magnitude() {
			return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
		}

		/** Normalizes the vector */
		inline Vector3d& normalize()  {
			double mag = magnitude();
			this->x /= mag;
			this->y /= mag;
			this->z /= mag;
			return *this;
		}

		/** Computes the dot product of the vector */
		inline double dot(Vector3d u) {
			return (this->x * u.x) + (this->y * u.y) + (this->z * u.z);
		}
	};

	/** Adds two vectors */
	inline Vector3d operator+(const Vector3d &a, const Vector3d &b) {
		Vector3d v;
		v.x = a.x + b.x;
		v.y = a.y + b.y;
		v.z = a.z + b.z;
		return v;
	}

	/** Subtracts two vectors */
	inline Vector3d operator-(const Vector3d &a, const Vector3d &b) {
		Vector3d v;
		v.x = a.x - b.x;
		v.y = a.y - b.y;
		v.z = a.z - b.z;
		return v;
	}

	/** Multiplies two vectors per-component */
	inline Vector3d operator*(const Vector3d &a, const Vector3d &b) {
		Vector3d v;
		v.x = a.x * b.x;
		v.y = a.y * b.y;
		v.z = a.z * b.z;
		return v;
	}

	/** Multiplies a vector by a scalar */
	inline Vector3d operator*(double a, const Vector3d &b) {
		Vector3d v;
		v.x = a * b.x;
		v.y = a * b.y;
		v.z = a * b.z;
		return v;
	}

	/** Multiplies a vector by a scalar */
	inline Vector3d operator*(const Vector3d &a, double b) {
		Vector3d v;
		v.x = a.x * b;
		v.y = a.y * b;
		v.z = a.z * b;
		return v;
	}

	/** Divides a vector by a scalar */
	inline Vector3d operator/(const Vector3d &a, double b) {
		Vector3d v;
		v.x = a.x / b;
		v.y = a.y / b;
		v.z = a.z / b;
		return v;
	}

	/** Computes the cross product of two vectors */
	inline Vector3d cross(const Vector3d& a, const Vector3d& b) {
		Vector3d v;
		v.x = a.y*b.z - a.z*b.y;
		v.y = a.z*b.x - a.x*b.z;
		v.z = a.x*b.y - a.y*b.x;
		return v;
	}

	/**
	 * A point in three-dimensional space.
	 *
	 * Stores a point and implements common point/vector operations.
	 */
	class Point3d {
	public:

		/** x-parameter of the vector */
		double x;

		/** y-parameter of the vector */
		double y;

		/** z-parameter of the vector */
		double z;

		/** homogeneous parameter (0 for vectors) */
		double h;

	public:

		/** Constructs a default three-dimensional point (all zeroes) */
		inline Point3d() {
			this->x = 0;
			this->y = 0;
			this->z = 0;
			this->h = 1;
		}

		/** Constructs a three-dimensional point from the given scalar components */
		inline Point3d(double x, double y, double z) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->h = 1;
		}

		/** Constructs a three-dimensional point from a three-dimensional vector */
		inline Point3d(const Vector3d &v) {
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			this->h = 1;
		}

		/** Equality */
		inline bool operator==(const Point3d& rhs) const {
			return this->x == rhs.x
				&& this->y == rhs.y
				&& this->z == rhs.z
				&& this->h == rhs.h;
		}

		/** Assignment */
		inline Point3d &operator=(const Point3d& rhs) {
			this->x = rhs.x;
			this->y = rhs.y;
			this->z = rhs.z;
			this->h = rhs.h;
			return *this;
		}

		/** Constructs the vector between two points */
		inline Vector3d operator-(const Point3d& rhs) {
			Vector3d v;
			v.x = this->x - rhs.x;
			v.y = this->y - rhs.y;
			v.z = this->z - rhs.z;
			return v;
		}

		/** Sets the scalar components of the point */
		inline void set(double x, double y, double z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		/** Moves the point by the given vector */
		inline Point3d& operator+=(const Vector3d& rhs) {
			this->x += rhs.x;
			this->y += rhs.y;
			this->z += rhs.z;
			return *this;
		}

		/** Moves the point in the opposite direction of the given vector */
		inline Point3d& operator-=(const Vector3d& rhs) {
			this->x -= rhs.x;
			this->y -= rhs.y;
			this->z -= rhs.z;
			return *this;
		}

		/** Performs perspective division on the (homogenous) point */
		inline void doPerspectiveDivision() {
			if (this->h != 1.0) {
				this->x /= h;
				this->y /= h;
				this->z /= h;
				this->h = 1.0;
			}
		}

	};

	/** Constructs a new point by moving the given point by the given vector */
	inline Point3d operator+(const Point3d &lhs, const Vector3d& rhs) {
		Point3d p;
		p.x = lhs.x + rhs.x;
		p.y = lhs.y + rhs.y;
		p.z = lhs.z + rhs.z;
		return p;
	}

	/** Constructs a new point by moving the given point in the opposite dirction of the given vector */
	inline Point3d operator-(const Point3d &lhs, const Vector3d& rhs) {
		Point3d p;
		p.x = lhs.x - rhs.x;
		p.y = lhs.y - rhs.y;
		p.z = lhs.z - rhs.z;
		return p;
	}

	/** Constructs a three-dimensional vector from a three-dimensional point */
	inline Vector3d::Vector3d(const Point3d &p) {
		this->x = p.x;
		this->y = p.y;
		this->z = p.z;
		this->h = 0;
	}

	/** An array of points */
	typedef std::vector<Point3d> Point3dList;

	/** A set of points */
	typedef Set<Point3d> Point3dSet;

	/** An index of a point in an array of points */
	typedef unsigned int PointRef;

	/** A vertex */
	typedef Point3d Vertex3d;

	/** An array of vertices */
	typedef std::vector<Vertex3d> Vertex3dList;

	/** An index of a vertex in an array of vertices */
	typedef PointRef VertexRef;

	/** An array of vectors */
	typedef std::vector<Vector3d> Vector3dList;

	/** An array of vertex references */
	typedef std::vector<VertexRef> VertexRefList;

	/** The face of a polygon (an ordered set of vertices, by reference) */
	typedef VertexRefList Face;

	/** An index of a vertex normal in an array of normals */
	typedef unsigned int VertexNormalRef;

	/** An array of normal references */
	typedef std::vector<VertexNormalRef> VertexNormalRefList;

	/** An array of faces */
	typedef std::vector<Face> FaceList;

	/** An index of a face in an array of faces */
	typedef unsigned int FaceRef;

	/** Constructs a triangular face */
	inline Face Triangle(VertexRef ref1, VertexRef ref2, VertexRef ref3) {
		Face f;
		f.push_back(ref1);
		f.push_back(ref2);
		f.push_back(ref3);
		return f;
	}

	/** Constructs a quadrilateral face */
	inline Face Quad(VertexRef ref1, VertexRef ref2, VertexRef ref3, VertexRef ref4) {
		Face f;
		f.push_back(ref1);
		f.push_back(ref2);
		f.push_back(ref3);
		f.push_back(ref4);
		return f;
	}

	/** A vertex in a mesh */
	class MeshVertex {
	public:

		/** Constructs a mesh vertex */
		inline MeshVertex(VertexRef p, VertexNormalRef n) {
			this->p = p;
			this->n = n;
		}

		/** The mesh vertex's location */
		VertexRef p;

		/** The mesh vertex's normal */
		VertexNormalRef n;
	};

	/** A face in a mesh (an ordered list of mesh vertices) */
	typedef std::vector<MeshVertex> MeshFace;

	/** An array of mesh faces */
	typedef std::vector<MeshFace> MeshFaceList;

	/** An index of a mesh face in an array of mesh faces */
	typedef unsigned int MeshFaceRef;

	/** Constructs a triangular mesh face */
	inline MeshFace Triangle(MeshVertex v1, MeshVertex v2, MeshVertex v3) {
		MeshFace f;
		f.push_back(v1);
		f.push_back(v2);
		f.push_back(v3);
		return f;
	}

	/** Constructs a quadrilateral mesh face */
	inline MeshFace Quad(MeshVertex v1, MeshVertex v2, MeshVertex v3, MeshVertex v4) {
		MeshFace f;
		f.push_back(v1);
		f.push_back(v2);
		f.push_back(v3);
		f.push_back(v4);
		return f;
	}

	/** A 4x4 matrix of doubles */
	class Matrixd {
	public:

		/** Constructs an identity matrix */
		inline Matrixd() : m(16) {
			setIdentity();
		}

		/** Constructs a matrix from another matrix */
		inline Matrixd(const Matrixd &a) : m(16) {
			copy(a);
		}

		/** Constructs a matrix from a single-dimensional array */
		inline Matrixd(const double a[16]) : m(16) {
			loadFromArray(a);
		}

		/** Sets the matrix to the identity matrix */
		inline void setIdentity() {
			for (int i=0; i < 4; i++) {
				for (int j=0; j < 4; j++) {
					this->m[i*4+j] = (i==j ? 1.0:0.0);
				}
			}
		}

		/** Sets the matrix from values in a single-dimensional array */
		inline void loadFromArray(const double a[16]) {
			for (int i=0; i < 4; i++) {
				for (int j=0; j < 4; j++) {
					this->m[i*4+j] = a[i*4+j];
				}
			}
		}

		/** Copies values from another matrix */
		inline void copy(const Matrixd &a) {
			this->m = a.m;
		}

		/** Assigns the values in one matrix to another */
		inline Matrixd &operator=(const Matrixd &a) {
			copy(a);
			return *this;
		}

		/** Gets the value of a particular matrix element */
		inline double &operator()(unsigned int i, unsigned int j) {
			/** \todo Throw a proper exception */
			if (i < 0 || i >= 4 || j < 0 || j >= 4) {
				throw -1;
			}

			return this->m[i*4+j];
		}

		/** Gets the value of a particular matrix element */
		inline double at(unsigned int i, unsigned int j) const {
			/** \todo Throw a proper exception */
			if (i < 0 || i >= 4 || j < 0 || j >= 4) {
				throw -1;
			}

			return this->m.at(i*4+j);
		}

	protected:

		/** The matrix */
		std::vector<double> m;
	};

	/** Multiplies two matrices */
	inline Matrixd operator*(const Matrixd &a, const Matrixd &b) {
		Matrixd m;
		/** \todo Find a faster way to do matrix multiplication */
		for (int i=0; i < 4; i++) {
			for (int j=0; j < 4; j++) {
				m(i, j) = 0.0;
				
				for (int k=0; k < 4; k++) {
					m(i, j) += a.at(k, j) * b.at(i, k);
				}
			}
		}
		return m;
	}

	/** Transforms a vector by a matrix to get a new vector */
	inline Vector3d operator*(const Matrixd &a, const Vector3d &b) {
		Vector3d v;
		v.x = (b.x * a.at(0, 0)) + (b.y * a.at(1, 0)) + (b.z * a.at(2, 0)) + (b.h * a.at(3, 0));
		v.y = (b.x * a.at(0, 1)) + (b.y * a.at(1, 1)) + (b.z * a.at(2, 1)) + (b.h * a.at(3, 1));
		v.z = (b.x * a.at(0, 2)) + (b.y * a.at(1, 2)) + (b.z * a.at(2, 2)) + (b.h * a.at(3, 2));
		v.h = (b.x * a.at(0, 3)) + (b.y * a.at(1, 3)) + (b.z * a.at(2, 3)) + (b.h * a.at(3, 3));
		return v;
	}

	/** Transforms a point by a matrix to get a new point */
	inline Point3d operator*(const Matrixd &a, const Point3d &b) {
		Point3d p;
		p.x = (b.x * a.at(0, 0)) + (b.y * a.at(1, 0)) + (b.z * a.at(2, 0)) + (b.h * a.at(3, 0));
		p.y = (b.x * a.at(0, 1)) + (b.y * a.at(1, 1)) + (b.z * a.at(2, 1)) + (b.h * a.at(3, 1));
		p.z = (b.x * a.at(0, 2)) + (b.y * a.at(1, 2)) + (b.z * a.at(2, 2)) + (b.h * a.at(3, 2));
		p.h = (b.x * a.at(0, 3)) + (b.y * a.at(1, 3)) + (b.z * a.at(2, 3)) + (b.h * a.at(3, 3));
		return p;
	}

	/**
	 * Prints a matrix to the given stream
	 * \param os The stream to print the matrix to
	 * \param m The matrix to print
	 */
	inline ostream &operator<<(ostream &os, const Matrixd &m) {
		for (int j=0; j < 4; j++) {
			os << endl << "| " << m.at(0, j);
			
			for (int i=1; i < 4; i++) {
				os << ", " << m.at(i, j);
			}
			os << " |";
		}
		return os;
	}

	/**
	 * Calculates the determinant of three points.
	 * \param p0 The first point
	 * \param p1 The second point
	 * \param p2 The third point
	 * \return The determinant of the three points given
	 *
	 * The determinant of the points is calculated as follows:
	 *   <pre>
	 *     | x0 x1 x2 |
	 *     | y0 y1 y2 |
	 *     |  1  1  1 |
	 *   </pre>
	 *
	 * Suppose the three points form a triangle in the x-y plane.  When this
	 * triangle is viewed from "above" (looking along the z-axis in the
	 * negative direction), if points p0, p1, and p2 form the triangle in
	 * anti-clockwise order, the determinant will be positive.  Otherwise,
	 * we have an "inside-out" triangle, and the determinant will be negative.
	 * (If the determinant is zero, the triangle is degenerate.  That is, the
	 * three points are co-linear, or are equal to each other.)  The absolute
	 * value of the determinant is exactly twice the area of the triangle.
	 */
	inline double determinant(Point3d p0, Point3d p1, Point3d p2) {
		double determinant = 0.0
			+ p0.x * (p1.y - p2.y)
			- p1.x * (p0.y - p2.y)
			+ p2.x * (p0.y - p1.y);

		return determinant;
	}

	/**
	 * Calculates the determinant of four points.
	 * \param p0 The first point
	 * \param p1 The second point
	 * \param p2 The third point
	 * \param p3 The fourth point
	 * \return The determinant of the four points given
	 *
	 * The determinant of the points is calculated as follows:
	 *   <pre>
	 *     | x0 x1 x2 x3 |
	 *     | y0 y1 y2 y3 |
	 *     | z0 z1 z2 z3 |
	 *     |  1  1  1  1 |
	 *   </pre>
	 *
	 * Suppose the four points form a tetrahedron.  When this tetrahedron is
	 * viewed from the outside, if points p0, p1, and p2 form one of the faces
	 * in anti-clockwise order, then the determinant will be positive.
	 * Otherwise, we have an "inside-out" tetrahedron, and the determinant will
	 * be negative.  (If the determinant is zero, the tetrahedron is degenerate.
	 * That is, the four points are co-planar, co-linear, or are equal to each
	 * other.)  The absolute value of the determinant is exacty six times the
	 * volume of the tetrahedron.
	 */
	inline double determinant(Point3d p0, Point3d p1, Point3d p2, Point3d p3) {
		// Each of the z-differences is used twice, so we just calculate them once.
		double z0MinusZ1 = p0.z - p1.z;
		double z0MinusZ2 = p0.z - p2.z;
		double z0MinusZ3 = p0.z - p3.z;
		double z1MinusZ2 = p1.z - p2.z;
		double z1MinusZ3 = p1.z - p3.z;
		double z2MinusZ3 = p2.z - p3.z;

		double determinant = 0.0
			+ p0.x * (p1.y * z2MinusZ3 - p2.y * z1MinusZ3 + p3.y * z1MinusZ2)
			- p1.x * (p0.y * z2MinusZ3 - p2.y * z0MinusZ3 + p3.y * z0MinusZ2)
			+ p2.x * (p0.y * z1MinusZ3 - p1.y * z0MinusZ3 + p3.y * z0MinusZ1)
			- p3.x * (p0.y * z1MinusZ2 - p1.y * z0MinusZ2 + p2.y * z0MinusZ1);

		return determinant;
	}

}