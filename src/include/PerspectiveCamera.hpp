/**
 * @file PerspectiveCamera.hpp
 */
#pragma once

#include "Camera.hpp"
#include "Geometry.hpp"
#include "handle_traits.hpp"
#include "list_traits.hpp"

namespace peek {

	/**
	 * \brief A simple perspective camera
	 */
	class PerspectiveCamera : public Camera {
	public:

		/** Constructs a default perspective camera */
		PerspectiveCamera();

		/** Constructs a perspective camera with the given attributes */
		PerspectiveCamera(double fov, double aspectRatio,
						  double nearVal, double farVal);

		/** (Re)sets the projection matrix with the camera's parameters */
		void setProjectionMatrix();

		/** (Re)sets the picking matrix with the camera's parameters and the given window coordinates */
		void setPickingMatrix(int x, int y);

		/** Get the distance of the near-plane */
		inline double getNear() {return this->nearVal;}

		/** Sets distance of the near-plane */
		inline void setNear(double nearVal) {this->nearVal = nearVal;}

		/** Gets the distance of the far-plane */
		inline double getFar() {return this->farVal;}

		/** Sets the distance of the far-plane */
		inline void setFar(double farVal) {this->farVal = farVal;}

		/** Gets the field-of-view in degrees */
		inline double getFov() {return this->fov;}

		/** Sets the field-of-view in degrees */
		inline void setFov(double fov) {this->fov = fov;}

		/** Gets the width and height of the picking region */
		inline int getPickingWindowSize() {return this->pickingWindowSize;}

		/** Sets the width and height of the picking region */
		inline void setPickingWindowSize(int pickingWindowSize) {this->pickingWindowSize = pickingWindowSize;}

		/** Gets the aspect ratio of the view area */
		inline double getAspectRatio() {return this->aspectRatio;}

		/** Sets the aspect ratio of the view area */
		inline void setAspectRatio(double aspectRatio) {this->aspectRatio = aspectRatio;}

		/** The default field-of-view */
		static const double defaultFov;

		/** The default aspect ratio of the view area */
		static const double defaultAspectRatio;

		/** The default distance to the near plane */
		static const double defaultNearVal;

		/** The default distance to the far plane */
		static const double defaultFarVal;

		/** The default width and height of the picking region */
		static const int defaultPickingWindowSize;

		typedef handle_traits<PerspectiveCamera>::handle_type handle;

		typedef list_traits<PerspectiveCamera>::list_type list;

	protected:

		/** The distance to the near plane */
		double nearVal;

		/** The distance to the far plane */
		double farVal;

		/** The aspect ratio of the view area */
		double aspectRatio;

		/** The field-of-view of the camera */
		double fov;

		/** The width and height of the picking region */
		int pickingWindowSize;

	};

}