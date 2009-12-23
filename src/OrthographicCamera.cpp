/**
 * \file OrthographicCamera.cpp
 * \author Douglas W. Paul
 */
#include "Peek_base.hpp"
#include "OrthographicCamera.hpp"

namespace peek {

	const double OrthographicCamera::defaultWidth = 10.0;
	const int OrthographicCamera::defaultPickingWindowSize = 3;
	const double OrthographicCamera::defaultAspectRatio = 4.0/3.0;
	const double OrthographicCamera::defaultNearVal = 0.1;
	const double OrthographicCamera::defaultFarVal = 100.0;

	/**
	 */
	OrthographicCamera::OrthographicCamera() {
		this->width = defaultWidth;
		this->aspectRatio = defaultAspectRatio;
		this->nearVal = defaultNearVal;
		this->farVal = defaultFarVal;
		this->pickingWindowSize = defaultPickingWindowSize;
		updateDerivedValues();
	}

	/**
	 * \param width The width of the camera
	 * \param aspectRatio Aspect ratio of the camera's view area
	 * \param nearVal Distance to the near plane
	 * \param farVal Distance to the far plane
	 */
	OrthographicCamera::OrthographicCamera(double width, double aspectRatio,
										   double nearVal, double farVal) {
		this->width = defaultWidth;
		this->aspectRatio = aspectRatio;
		this->nearVal = nearVal;
		this->farVal = farVal;
		this->pickingWindowSize = defaultPickingWindowSize;
		updateDerivedValues();
	}

	/**
	 */
	void OrthographicCamera::setProjectionMatrix() {
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(this->left, this->right, this->bottom, this->top, this->nearVal, this->farVal);
	}

	/**
	 */
	void OrthographicCamera::setPickingMatrix(int x, int y) {
		GLint viewport[4];
		glGetIntegerv(GL_VIEWPORT, viewport);
	  
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPickMatrix(x, viewport[3]-y, this->pickingWindowSize, this->pickingWindowSize, viewport);
		glOrtho(this->left, this->right, this->bottom, this->top, this->nearVal, this->farVal);
	}

	/**
	 */
	void OrthographicCamera::updateDerivedValues() {
		double halfWidth = this->width / 2.0;
		double halfHeight = halfWidth / this->aspectRatio;
		this->left = -halfWidth;
		this->right = halfWidth;
		this->top = halfHeight;
		this->bottom = -halfHeight;
	}

}