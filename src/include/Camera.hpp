/**
 * \file Camera.hpp
 * \author Douglas W. Paul
 *
 * Declares the Camera interface
 */

#pragma once

#include "Geometry.hpp"
#include "handle_traits.hpp"
#include "list_traits.hpp"

namespace peek {

	/**
	 * \interface Camera
	 * \brief An interface for cameras
	 */
	class Camera {
	public:

		/** (Re)sets the projection matrix with the camera's parameters */
		virtual void setProjectionMatrix() = 0;

		/** (Re)sets the picking matrix with the camera's parameters and the given window coordinates */
		virtual void setPickingMatrix(int x, int y) = 0;

		/** Get the distance of the near-plane */
		virtual double getNear() = 0;

		/** Sets distance of the near-plane */
		virtual void setNear(double nearVal) = 0;

		/** Gets the distance of the far-plane */
		virtual double getFar() = 0;

		/** Sets the distance of the far-plane */
		virtual void setFar(double farVal) = 0;

		/** Gets the aspect ratio of the view area */
		virtual double getAspectRatio() = 0;

		/** Sets the aspect ratio of the view area */
		virtual void setAspectRatio(double aspectRatio) = 0;

		typedef handle_traits<Camera>::handle_type handle;

		typedef list_traits<Camera>::list_type list;

	};

}