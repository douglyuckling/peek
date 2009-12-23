/**
 * \file OrthoBirdsEyeCameraRigging.cpp
 * \author Douglas W. Paul
 *
 * Defines the behavior of the OrthoBirdsEyeCameraRigging class.
 */

#include "Peek_base.hpp"
#include "OrthoBirdsEyeCameraRigging.hpp"

namespace peek {

	/**
	 * \param camera The camera this rigging will control
	 * \param groundPoint The initial location of the camera over the X-Y plane
	 * \param height The initial height of the camera over the X-Y plane
	 */
	OrthoBirdsEyeCameraRigging::OrthoBirdsEyeCameraRigging(OrthographicCamera::handle camera, Point2d groundPoint, double height, double fov)
		: BirdsEyeCameraRigging(camera, groundPoint, height) {
		this->orthoCamera = camera;
		this->fov = fov;
		this->virtualZ = height;
		updateWidth();
	}

	/**
	 * \param camera The camera this rigging will control
	 * \param location The initial location of the camera in threespace
	 */
	OrthoBirdsEyeCameraRigging::OrthoBirdsEyeCameraRigging(OrthographicCamera::handle camera, Point3d location, double fov)
		: BirdsEyeCameraRigging(camera, location) {
		this->orthoCamera = camera;
		this->fov = fov;
		updateWidth();
	}

	OrthoBirdsEyeCameraRigging::~OrthoBirdsEyeCameraRigging() {}

	void OrthoBirdsEyeCameraRigging::initModelviewMatrix() {
		BirdsEyeCameraRigging::initModelviewMatrix();
	}

	Camera *OrthoBirdsEyeCameraRigging::getCamera() {
		return BirdsEyeCameraRigging::getCamera();
	}

	/**
	 * \return The (virtual) height of the camera over the X-Y plane
	 */
	double OrthoBirdsEyeCameraRigging::getHeight() {
		return this->virtualZ;
	}

	/**
	 * \param height The new (virtual) height of the camera above the X-Y plane
	 */
	void OrthoBirdsEyeCameraRigging::setHeight(double height) {
		//BirdsEyeCameraRigging::setHeight(height);
		this->virtualZ = height;
		if (this->virtualZ < 0.0) this->virtualZ = 0.0;
		updateWidth();
	}

	/**
	 * \param deltaHeight The change in (virtual) height of the camera above the X-Y plane
	 */
	void OrthoBirdsEyeCameraRigging::changeHeight(double deltaHeight) {
		//BirdsEyeCameraRigging::changeHeight(deltaHeight);
		this->virtualZ += deltaHeight;
		if (this->virtualZ < 0.0) this->virtualZ = 0.0;
		updateWidth();
	}

	/**
	 * \param location The new location of the camera
	 */
	void OrthoBirdsEyeCameraRigging::setLocation(Point3d location) {
		BirdsEyeCameraRigging::setLocation(location);
		updateWidth();
	}

	/**
	 * \param deltaLocation The change in the location of the camera
	 */
	void OrthoBirdsEyeCameraRigging::changeLocation(Vector3d deltaLocation) {
		BirdsEyeCameraRigging::changeLocation(deltaLocation);
		updateWidth();
	}

	/**
	 * \param fov The new field-of-view of the rigging in degrees
	 */
	void OrthoBirdsEyeCameraRigging::setFov(double fov) {
		this->fov = fov;
		updateWidth();
	}

	/**
	 */
	void OrthoBirdsEyeCameraRigging::updateWidth() {
		double width = 2.0 * tan(this->fov/2.0) * this->virtualZ;
		this->orthoCamera->setWidth(width);
	}

}