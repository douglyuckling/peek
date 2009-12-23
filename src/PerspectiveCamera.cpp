/**
 * \file PerspectiveCamera.cpp
 * \author Douglas W. Paul
 */
#include "Peek_base.hpp"
#include "PerspectiveCamera.hpp"

namespace peek {

	const double PerspectiveCamera::defaultFov = 45.0;
	const int PerspectiveCamera::defaultPickingWindowSize = 3;
	const double PerspectiveCamera::defaultAspectRatio = 4.0/3.0;
	const double PerspectiveCamera::defaultNearVal = 0.1;
	const double PerspectiveCamera::defaultFarVal = 100.0;

	/**
	 */
	PerspectiveCamera::PerspectiveCamera() {
		this->fov = defaultFov;
		this->aspectRatio = defaultAspectRatio;
		this->nearVal = defaultNearVal;
		this->farVal = defaultFarVal;
		this->pickingWindowSize = defaultPickingWindowSize;
	}

	/**
	 * \param fov The field-of-view of the camera
	 * \param aspectRatio Aspect ratio of the camera's view area
	 * \param nearVal Distance to the near plane
	 * \param farVal Distance to the far plane
	 */
	PerspectiveCamera::PerspectiveCamera(double fov, double aspectRatio,
										 double nearVal, double farVal) {
		this->fov = defaultFov;
		this->aspectRatio = aspectRatio;
		this->nearVal = nearVal;
		this->farVal = farVal;
		this->pickingWindowSize = defaultPickingWindowSize;
	}

	/**
	 */
	void PerspectiveCamera::setProjectionMatrix() {
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(this->fov, this->aspectRatio, this->nearVal, this->farVal);
	}

	/**
	 */
	void PerspectiveCamera::setPickingMatrix(int x, int y) {
		GLint viewport[4];
		glGetIntegerv(GL_VIEWPORT, viewport);
	  
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPickMatrix(x, viewport[3]-y, this->pickingWindowSize, this->pickingWindowSize, viewport);
		gluPerspective(this->fov, this->aspectRatio, this->nearVal, this->farVal);
	}

}