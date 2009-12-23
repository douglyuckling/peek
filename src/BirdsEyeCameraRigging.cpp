/**
 * \file BirdsEyeCameraRigging.cpp
 * \author Douglas W. Paul
 *
 * Defines the behavior of the BirdsEyeCameraRigging class.
 */

#include "Peek_base.hpp"
#include "BirdsEyeCameraRigging.hpp"

namespace peek {

	/**
	 * \param camera The camera this rigging will control
	 * \param groundPoint The initial location of the camera over the X-Y plane
	 * \param height The initial height of the camera over the X-Y plane
	 */
	BirdsEyeCameraRigging::BirdsEyeCameraRigging(Camera::handle camera, Point2d groundPoint, double height) {
		this->camera = camera;
		this->location.x = groundPoint.x;
		this->location.y = groundPoint.y;
		this->location.z = height;
	}

	/**
	 * \param camera The camera this rigging will control
	 * \param location The initial location of the camera in threespace
	 */
	BirdsEyeCameraRigging::BirdsEyeCameraRigging(Camera::handle camera, Point3d location) {
		this->camera = camera;
		this->location = location;
	}

	BirdsEyeCameraRigging::~BirdsEyeCameraRigging() {}

	void BirdsEyeCameraRigging::initModelviewMatrix() {
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslated(-this->location.x, -this->location.y, -this->location.z);
	}

	/**
	 * \return The location of the camera over the X-Y plane
	 */
	Point2d BirdsEyeCameraRigging::getGroundPoint() {
		return Point2d(this->location.x, this->location.y);
	}

	/**
	 * \param groundPoint The new location of the camera over the X-Y plane
	 */
	void BirdsEyeCameraRigging::setGroundPoint(Point2d groundPoint) {
		this->location.x = groundPoint.x;
		this->location.y = groundPoint.y;
	}

	/**
	 * \param deltaGroundPoint The change in the location of the camera over the X-Y plane
	 */
	void BirdsEyeCameraRigging::changeGroundPoint(Vector2d deltaGroundPoint) {
		this->location.x += deltaGroundPoint.x;
		this->location.y += deltaGroundPoint.y;
	}

	/**
	 * \param dX The change in the location of the camera along the X axis
	 * \param dY The change in the location of the camera along the Y axis
	 */
	void BirdsEyeCameraRigging::changeGroundPoint(double dX, double dY) {
		this->location.x += dX;
		this->location.y += dY;
	}

	/**
	 * \param dX The change in the position of the camera along the x-axis
	 */
	void BirdsEyeCameraRigging::changeX(double dX) {
		this->location.x += dX;
	}

	/**
	 * \param dY The change in the position of the camera along the y-axis
	 */
	void BirdsEyeCameraRigging::changeY(double dY) {
		this->location.y += dY;
	}

	/**
	 * \return The height of the camera over the X-Y plane
	 */
	double BirdsEyeCameraRigging::getHeight() {
		return this->location.z;
	}

	/**
	 * \param height The new height of the camera above the X-Y plane
	 */
	void BirdsEyeCameraRigging::setHeight(double height) {
		this->location.z = height;
	}

	/**
	 * \param deltaHeight The change in height of the camera above the X-Y plane
	 */
	void BirdsEyeCameraRigging::changeHeight(double deltaHeight) {
		this->location.z += deltaHeight;
	}

}