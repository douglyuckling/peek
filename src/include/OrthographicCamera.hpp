/**
 * \file OrthographicCamera.hpp
 * \author Douglas W. Paul
 */
#pragma once

#include "Camera.hpp"
#include "Geometry.hpp"
#include "handle_traits.hpp"
#include "list_traits.hpp"

namespace peek {

	/**
	 * \brief A simple orthographic camera
	 */
	class OrthographicCamera : public Camera {
	public:

		/** Constructs a default orthographic camera */
		OrthographicCamera();

		/** Constructs a orthographic camera with the given attributes */
		OrthographicCamera(double width, double aspectRatio,
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

		/** Gets the width of the camera in units */
		inline double getWidth() {return this->width;}

		/** Sets the width of the camera in units */
		inline void setWidth(double width) {this->width = width; updateDerivedValues();}

		/** Gets the calculated height of the camera based on the current width and aspect ratio */
		inline double getHeight() {return this->width / this->aspectRatio;}

		/** Gets the width and height of the picking region */
		inline int getPickingWindowSize() {return this->pickingWindowSize;}

		/** Sets the width and height of the picking region */
		inline void setPickingWindowSize(int pickingWindowSize) {this->pickingWindowSize = pickingWindowSize;}

		/** Gets the aspect ratio of the view area */
		inline double getAspectRatio() {return this->aspectRatio;}

		/** Sets the aspect ratio of the view area */
		inline void setAspectRatio(double aspectRatio) {this->aspectRatio = aspectRatio; updateDerivedValues();}

		/** The default width */
		static const double defaultWidth;

		/** The default aspect ratio of the view area */
		static const double defaultAspectRatio;

		/** The default distance to the near plane */
		static const double defaultNearVal;

		/** The default distance to the far plane */
		static const double defaultFarVal;

		/** The default width and height of the picking region */
		static const int defaultPickingWindowSize;

		typedef handle_traits<OrthographicCamera>::handle_type handle;

		typedef list_traits<OrthographicCamera>::list_type list;

	protected:

		/** Updates derived values */
		void updateDerivedValues();

		/** The distance to the near plane */
		double nearVal;

		/** The distance to the far plane */
		double farVal;

		/** The aspect ratio of the view area */
		double aspectRatio;

		/** The width of the camera */
		double width;

		/** The left boundary of the camera */
		double left;

		/** The right boundaray of the camera */
		double right;

		/** The top boundary of the camera */
		double top;

		/** The bottom boundary of the camera */
		double bottom;

		/** The width and height of the picking region */
		int pickingWindowSize;

	};

}