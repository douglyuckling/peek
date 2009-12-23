/**
* @file Geometry.hpp
*/
#pragma once

#include <cmath>
#include <vector>
#include <iostream>
#include "list_traits.hpp"
#include "Numerics.hpp"
#include "Set.hpp"

namespace peek {

	template <typename T>
	class Point2;

	/**
	 * @brief A vector in two-dimensional space
	 *
	 * Stores a vector and defines common vector operations.
	 */
	template <typename T>
	class Vector2 {
		typedef typename T T_type;

	public:

		typedef typename list_traits<Vector2<T_type>>::list_type list;
		typedef typename list::size_type listIndex;
		typedef typename list_traits<listIndex>::list_type listIndexList;

		/** x-parameter of the vector */
		T_type x;

		/** y-parameter of the vector */
		T_type y;

		/** homogeneous parameter (0 for vectors) */
		T_type h;

	public:

		/** Constructs a default two-dimensional vector (all zeros) */
		inline Vector2() {
			this->x = 0;
			this->y = 0;
			this->h = 0;
		}

		/** Constructs a two-dimensional vector from the given scalar components */
		inline Vector2(T_type x, T_type y) {
			this->x = x;
			this->y = y;
			this->h = 0;
		}

		/** Constructs a two-dimensional vector from the corresponding scalar components in a Point2 */
		Vector2(const Point2<T_type> &p);

		/** Negates a vector */
		inline Vector2<T_type> operator-() const {
			Vector2<T_type> v;
			v.x = -this->x;
			v.y = -this->y;
			return v;
		}

		/** Increments one vector by another */
		inline Vector2<T_type>& operator+=(const Vector2<T_type>& rhs) {
			this->x += rhs.x;
			this->y += rhs.y;
			return *this;
		}

		/** Calculates the magnitude of the vector */
		inline T_type magnitude() {
			return sqrt((this->x * this->x) + (this->y * this->y));
		}

		/** Normalizes the vector */
		inline Vector2<T_type>& normalize()  {
			double mag = magnitude();
			this->x /= mag;
			this->y /= mag;
			return *this;
		}

	};

	/** Adds two vectors */
	template <typename T>
	inline Vector2<T> operator+(const Vector2<T> &a, const Vector2<T> &b) {
		Vector2<T> v;
		v.x = a.x + b.x;
		v.y = a.y + b.y;
		return v;
	}

	/** Subtracts two vectors */
	template <typename T>
	inline Vector2<T> operator-(const Vector2<T> &a, const Vector2<T> &b) {
		Vector2<T> v;
		v.x = a.x - b.x;
		v.y = a.y - b.y;
		return v;
	}

	/** Multiplies two vectors per-component */
	template <typename T>
	inline Vector2<T> operator*(const Vector2<T> &a, const Vector2<T> &b) {
		Vector2<T> v;
		v.x = a.x * b.x;
		v.y = a.y * b.y;
		return v;
	}

	/** Multiplies a vector by a scalar */
	template <typename T>
	inline Vector2<T> operator*(T a, const Vector2<T> &b) {
		Vector3<T> v;
		v.x = a * b.x;
		v.y = a * b.y;
		return v;
	}

	/** Multiplies a vector by a scalar */
	template <typename T>
	inline Vector2<T> operator*(const Vector2<T> &a, T b) {
		Vector2<T> v;
		v.x = a.x * b;
		v.y = a.y * b;
		return v;
	}

	/** Divides a vector by a scalar */
	template <typename T>
	inline Vector2<T> operator/(const Vector2<T> &a, T b) {
		Vector3<T> v;
		v.x = a.x / b;
		v.y = a.y / b;
		return v;
	}


	template <typename T>
	class Point3;

	/**
	 * @brief A vector in three-dimensional space
	 *
	 * Stores a vector and defines common vector operations.
	 */
	template <typename T>
	class Vector3 {
		typedef typename T T_type;

	public:

		typedef typename list_traits<Vector3<T_type>>::list_type list;
		typedef typename list::size_type listIndex;
		typedef typename list_traits<listIndex>::list_type listIndexList;

		/** x-parameter of the vector */
		T_type x;

		/** y-parameter of the vector */
		T_type y;

		/** z-parameter of the vector */
		T_type z;

		/** homogeneous parameter (0 for vectors) */
		T_type h;

	public:

		/** Constructs a default three-dimensional vector (all zeros) */
		inline Vector3() {
			this->x = 0;
			this->y = 0;
			this->z = 0;
			this->h = 0;
		}

		/** Constructs a three-dimensional vector from the given scalar components */
		inline Vector3(T_type x, T_type y, T_type z) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->h = 0;
		}

		/** Constructs a three-dimensional vector from the corresponding scalar components in a Point3 */
		Vector3(const Point3<T_type> &p);

		/** Assignment */
		/*
		inline Vector3& operator=(const Vector3& rhs){
		this->x = rhs.x;
		this->y = rhs.y;
		this->z = rhs.z;
		this->h = rhs.h;
		return *this;
		}
		*/

		/** Negates a vector */
		inline Vector3<T_type> operator-() const {
			Vector3<T_type> v;
			v.x = -this->x;
			v.y = -this->y;
			v.z = -this->z;
			return v;
		}

		/** Sets the scalar components of the vector */
		/*
		inline void set(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
		}
		*/

		/** Sets the scalar components of the vector from an array of scalars in x-y-z order */
		/*
		inline void set(double v[3]) {
		this->x = v[0];
		this->y = v[1];
		this->z = v[2];
		}
		*/

		/** Increments one vector by another */
		inline Vector3<T_type>& operator+=(const Vector3<T_type>& rhs) {
			this->x += rhs.x;
			this->y += rhs.y;
			this->z += rhs.z;
			return *this;
		}

		/** Decrements one vector by another */
		/*
		inline Vector3& operator-=(const Vector3& rhs) {
		this->x -= rhs.x;
		this->y -= rhs.y;
		this->z -= rhs.z;
		return *this;
		}
		*/

		/** Per-element multiplication of one vector by another */
		/*
		inline Vector3 &operator*=(const Vector3 &rhs) {
		this->x *= rhs.x;
		this->y *= rhs.y;
		this->z *= rhs.z;
		return *this;
		}
		*/

		/** Calculates the magnitude of the vector */
		inline T_type magnitude() {
			return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
		}

		/** Normalizes the vector */
		inline Vector3<T_type>& normalize()  {
			double mag = magnitude();
			this->x /= mag;
			this->y /= mag;
			this->z /= mag;
			return *this;
		}

		/** Computes the dot product of the vector */
		/*
		inline double dot(Vector3 u) {
		return (this->x * u.x) + (this->y * u.y) + (this->z * u.z);
		}
		*/
	};

	/** Adds two vectors */
	template <typename T>
	inline Vector3<T> operator+(const Vector3<T> &a, const Vector3<T> &b) {
		Vector3<T> v;
		v.x = a.x + b.x;
		v.y = a.y + b.y;
		v.z = a.z + b.z;
		return v;
	}

	/** Subtracts two vectors */
	template <typename T>
	inline Vector3<T> operator-(const Vector3<T> &a, const Vector3<T> &b) {
		Vector3<T> v;
		v.x = a.x - b.x;
		v.y = a.y - b.y;
		v.z = a.z - b.z;
		return v;
	}

	/** Multiplies two vectors per-component */
	template <typename T>
	inline Vector3<T> operator*(const Vector3<T> &a, const Vector3<T> &b) {
		Vector3<T> v;
		v.x = a.x * b.x;
		v.y = a.y * b.y;
		v.z = a.z * b.z;
		return v;
	}

	/** Multiplies a vector by a scalar */
	template <typename T>
	inline Vector3<T> operator*(T a, const Vector3<T> &b) {
		Vector3<T> v;
		v.x = a * b.x;
		v.y = a * b.y;
		v.z = a * b.z;
		return v;
	}

	/** Multiplies a vector by a scalar */
	template <typename T>
	inline Vector3<T> operator*(const Vector3<T> &a, T b) {
		Vector3<T> v;
		v.x = a.x * b;
		v.y = a.y * b;
		v.z = a.z * b;
		return v;
	}

	/** Divides a vector by a scalar */
	template <typename T>
	inline Vector3<T> operator/(const Vector3<T> &a, T b) {
		Vector3<T> v;
		v.x = a.x / b;
		v.y = a.y / b;
		v.z = a.z / b;
		return v;
	}

	/** Computes the cross product of two vectors */
	template <typename T>
	inline Vector3<T> cross(const Vector3<T>& a, const Vector3<T>& b) {
		Vector3<T> v;
		v.x = a.y*b.z - a.z*b.y;
		v.y = a.z*b.x - a.x*b.z;
		v.z = a.x*b.y - a.y*b.x;
		return v;
	}


	/**
	 * @brief A point in two-dimensional space.
	 *
	 * Stores a point and implements common point/vector operations.
	 */
	template <typename T>
	class Point2 {
		typedef typename T T_type;

	public:

		typedef typename list_traits<Point2<T_type>>::list_type list;
		typedef typename list::size_type listIndex;
		typedef typename list_traits<listIndex>::list_type listIndexList;

		/** x-parameter of the vector */
		T_type x;

		/** y-parameter of the vector */
		T_type y;

		/** homogeneous parameter (1 for points) */
		T_type h;

	public:

		/** Constructs a default two-dimensional point (all zeros) */
		inline Point2() {
			this->x = 0;
			this->y = 0;
			this->z = 0;
			this->h = 1;
		}

		/** Constructs a two-dimensional point from the given scalar components */
		inline Point2(T_type x, T_type y) {
			this->x = x;
			this->y = y;
			this->h = 1;
		}

		/** Constructs a three-dimensional point from a two-dimensional vector */
		inline Point2(const Vector2<T_type> &v) {
			this->x = v.x;
			this->y = v.y;
			this->h = 1;
		}

		/** Equality */
		inline bool operator==(const Point2<T_type>& rhs) const {
			return this->x == rhs.x
				&& this->y == rhs.y
				&& this->h == rhs.h;
		}

		/** Assignment */
		inline Point2<T_type> &operator=(const Point2<T_type>& rhs) {
			this->x = rhs.x;
			this->y = rhs.y;
			this->h = rhs.h;
			return *this;
		}

		/** Constructs the vector between two points */
		inline Vector2<T_type> operator-(const Point2<T_type>& rhs) {
			Vector2<T_type> v;
			v.x = this->x - rhs.x;
			v.y = this->y - rhs.y;
			v.z = this->z - rhs.z;
			return v;
		}

		/** Sets the scalar components of the point */
		inline void set(T_type x, T_type y) {
			this->x = x;
			this->y = y;
		}

		/** Moves the point by the given vector */
		inline Point2<T_type>& operator+=(const Vector2<T_type>& rhs) {
			this->x += rhs.x;
			this->y += rhs.y;
			return *this;
		}

		/** Moves the point in the opposite direction of the given vector */
		inline Point2<T_type>& operator-=(const Vector2<T_type>& rhs) {
			this->x -= rhs.x;
			this->y -= rhs.y;
			return *this;
		}

		/** Performs perspective division on the (homogenous) point */
		inline void doPerspectiveDivision() {
			if(this->h != 1.0) {
				this->x /= h;
				this->y /= h;
				this->h = 1.0;
			}
		}

	};

	/** Constructs a new point by moving the given point by the given vector */
	template <typename T>
	inline Point2<T> operator+(const Point2<T> &lhs, const Vector2<T>& rhs) {
		Point2<T> p;
		p.x = lhs.x + rhs.x;
		p.y = lhs.y + rhs.y;
		return p;
	}

	/** Constructs a new point by moving the given point in the opposite dirction of the given vector */
	template <typename T>
	inline Point2<T> operator-(const Point2<T> &lhs, const Vector2<T>& rhs) {
		Point2<T> p;
		p.x = lhs.x - rhs.x;
		p.y = lhs.y - rhs.y;
		return p;
	}

	/** Constructs a two-dimensional vector from a two-dimensional point */
	template <typename T>
	inline Vector2<T>::Vector2(const Point2<T> &p) {
		this->x = p.x;
		this->y = p.y;
		this->h = 0;
	}

	/**
	 * @brief A point in three-dimensional space.
	 *
	 * Stores a point and implements common point/vector operations.
	 */
	template <typename T>
	class Point3 {
		typedef typename T T_type;

	public:

		typedef typename list_traits<Point3<T_type>>::list_type list;
		typedef typename list::size_type listIndex;
		typedef typename list_traits<listIndex>::list_type listIndexList;

		/** x-parameter of the vector */
		T_type x;

		/** y-parameter of the vector */
		T_type y;

		/** z-parameter of the vector */
		T_type z;

		/** homogeneous parameter (0 for vectors) */
		T_type h;

	public:

		/** Constructs a default three-dimensional point (all zeroes) */
		inline Point3() {
			this->x = 0;
			this->y = 0;
			this->z = 0;
			this->h = 1;
		}

		/** Constructs a three-dimensional point from the given scalar components */
		inline Point3(T_type x, T_type y, T_type z) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->h = 1;
		}

		/** Constructs a three-dimensional point from a three-dimensional vector */
		inline Point3(const Vector3<T_type> &v) {
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			this->h = 1;
		}

		/** Equality */
		inline bool operator==(const Point3<T_type>& rhs) const {
			return this->x == rhs.x
				&& this->y == rhs.y
				&& this->z == rhs.z
				&& this->h == rhs.h;
		}

		/** Assignment */
		inline Point3<T_type> &operator=(const Point3<T_type>& rhs) {
			this->x = rhs.x;
			this->y = rhs.y;
			this->z = rhs.z;
			this->h = rhs.h;
			return *this;
		}

		/** Constructs the vector between two points */
		inline Vector3<T_type> operator-(const Point3<T_type>& rhs) {
			Vector3<T_type> v;
			v.x = this->x - rhs.x;
			v.y = this->y - rhs.y;
			v.z = this->z - rhs.z;
			return v;
		}

		/** Sets the scalar components of the point */
		inline void set(T_type x, T_type y, T_type z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		/** Moves the point by the given vector */
		inline Point3<T_type>& operator+=(const Vector3<T_type>& rhs) {
			this->x += rhs.x;
			this->y += rhs.y;
			this->z += rhs.z;
			return *this;
		}

		/** Moves the point in the opposite direction of the given vector */
		inline Point3<T_type>& operator-=(const Vector3<T_type>& rhs) {
			this->x -= rhs.x;
			this->y -= rhs.y;
			this->z -= rhs.z;
			return *this;
		}

		/** Performs perspective division on the (homogenous) point */
		inline void doPerspectiveDivision() {
			if(this->h != 1.0) {
				this->x /= h;
				this->y /= h;
				this->z /= h;
				this->h = 1.0;
			}
		}

	};

	/** Constructs a new point by moving the given point by the given vector */
	template <typename T>
	inline Point3<T> operator+(const Point3<T> &lhs, const Vector3<T>& rhs) {
		Point3<T> p;
		p.x = lhs.x + rhs.x;
		p.y = lhs.y + rhs.y;
		p.z = lhs.z + rhs.z;
		return p;
	}

	/** Constructs a new point by moving the given point in the opposite dirction of the given vector */
	template <typename T>
	inline Point3<T> operator-(const Point3<T> &lhs, const Vector3<T>& rhs) {
		Point3<T> p;
		p.x = lhs.x - rhs.x;
		p.y = lhs.y - rhs.y;
		p.z = lhs.z - rhs.z;
		return p;
	}

	/** Constructs a three-dimensional vector from a three-dimensional point */
	template <typename T>
	inline Vector3<T>::Vector3(const Point3<T> &p) {
		this->x = p.x;
		this->y = p.y;
		this->z = p.z;
		this->h = 0;
	}


	/* Matrices */

	using namespace std;

	/** A 4x4 matrix */
	template <typename T>
	class Matrix {

		typedef typename T T_type;

	public:

		/** Constructs an identity matrix */
		inline Matrix() : m(16) {
			setIdentity();
		}

		/** Constructs a matrix from another matrix */
		inline Matrix(const Matrix<T_type> &a) : m(16) {
			copy(a);
		}

		/** Constructs a matrix from a single-dimensional array */
		inline Matrix(const T_type a[16]) : m(16) {
			loadFromArray(a);
		}

		/** Sets the matrix to the identity matrix */
		inline void setIdentity() {
			for(int i=0; i < 4; i++)
				for(int j=0; j < 4; j++)
					this->m[i*4+j] = (i==j ? 1.0:0.0);
		}

		/** Sets the matrix from values in a single-dimensional array */
		inline void loadFromArray(const T_type a[16]) {
			for(int i=0; i < 4; i++)
				for(int j=0; j < 4; j++)
					this->m[i*4+j] = a[i*4+j];
		}

		/** Copies values from another matrix */
		inline void copy(const Matrix<T_type> &a) {
			this->m = a.m;
		}

		/** Assigns the values in one matrix to another */
		inline Matrix<T_type> &operator=(const Matrix<T_type> &a) {
			copy(a);
			return *this;
		}

		/** Gets the value of a particular matrix element */
		inline double &operator()(unsigned int i, unsigned int j) {
			/** @todo Throw a proper exception */
			if(i < 0 || i >= 4 || j < 0 || j >= 4)
				throw -1;
			return this->m[i*4+j];
		}

		/** Gets the value of a particular matrix element */
		inline double at(unsigned int i, unsigned int j) const {
			/** @todo Throw a proper exception */
			if(i < 0 || i >= 4 || j < 0 || j >= 4)
				throw -1;
			return this->m.at(i*4+j);
		}

	protected:

		/** The matrix */
		vector<T_type> m;
	};

	/** Multiplies two matrices */
	template <typename T>
	inline Matrix<T> operator*(const Matrix<T> &a, const Matrix<T> &b) {
		Matrix<T> m;
		/** @todo Find a faster way to do matrix multiplication */
		for(int i=0; i < 4; i++) {
			for(int j=0; j < 4; j++) {
				m(i, j) = 0.0;
				for(int k=0; k < 4; k++) {
					m(i, j) += a.at(k, j) * b.at(i, k);
				}
			}
		}
		return m;
	}

	/** Transforms a vector by a matrix to get a new vector */
	template <typename T>
	inline Vector3<T> operator*(const Matrix<T> &a, const Vector3<T> &b) {
		Vector3<T> v;
		v.x = (b.x * a.at(0, 0)) + (b.y * a.at(1, 0)) + (b.z * a.at(2, 0)) + (b.h * a.at(3, 0));
		v.y = (b.x * a.at(0, 1)) + (b.y * a.at(1, 1)) + (b.z * a.at(2, 1)) + (b.h * a.at(3, 1));
		v.z = (b.x * a.at(0, 2)) + (b.y * a.at(1, 2)) + (b.z * a.at(2, 2)) + (b.h * a.at(3, 2));
		v.h = (b.x * a.at(0, 3)) + (b.y * a.at(1, 3)) + (b.z * a.at(2, 3)) + (b.h * a.at(3, 3));
		return v;
	}

	/** Transforms a point by a matrix to get a new point */
	template <typename T>
	inline Point3<T> operator*(const Matrix<T> &a, const Point3<T> &b) {
		Point3<T> p;
		p.x = (b.x * a.at(0, 0)) + (b.y * a.at(1, 0)) + (b.z * a.at(2, 0)) + (b.h * a.at(3, 0));
		p.y = (b.x * a.at(0, 1)) + (b.y * a.at(1, 1)) + (b.z * a.at(2, 1)) + (b.h * a.at(3, 1));
		p.z = (b.x * a.at(0, 2)) + (b.y * a.at(1, 2)) + (b.z * a.at(2, 2)) + (b.h * a.at(3, 2));
		p.h = (b.x * a.at(0, 3)) + (b.y * a.at(1, 3)) + (b.z * a.at(2, 3)) + (b.h * a.at(3, 3));
		return p;
	}

	/*!
	* @brief Prints a matrix to the given stream
	* @param os The stream to print the matrix to
	* @param m The matrix to print
	*/
	template <typename T>
	inline ostream &operator<<(ostream &os, const Matrix<T> &m) {
		for(int j=0; j < 4; j++) {
			os << endl << "| " << m.at(0, j);
			for(int i=1; i < 4; i++) {
				os << ", " << m.at(i, j);
			}
			os << " |";
		}
		return os;
	}

	template <typename T>
	inline Vector3<T> parametricUnitCircle(T t) {
		T r = t * (2.0*PI);
		return Vector3<T>(cos(r), sin(r), 0);
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
	template <typename T>
	inline double determinant(Point3<T> p0, Point3<T> p1, Point3<T> p2) {
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
	template <typename T>
	inline double determinant(Point3<T> p0, Point3<T> p1, Point3<T> p2, Point3<T> p3) {
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

	typedef Point3<double> Point3d;
	typedef Point3<float> Point3f;

	typedef Point2<double> Point2d;
	typedef Point2<float> Point2f;

	typedef Vector3<double> Vector3d;
	typedef Vector3<float> Vector3f;

	typedef Vector2<double> Vector2d;
	typedef Vector2<float> Vector2f;

	/** A vertex */
	typedef Point3d Vertex3d;
	
	/** A vertex normal */
	typedef Vector3d Normal3d;

	/** An array of points */
	typedef std::vector<Point3d> Point3dList;

	/** A set of points */
	typedef Set<Point3d> Point3dSet;

}