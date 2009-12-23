/**
 * \file BirdsEyeCameraRigging.hpp
 * \author Douglas W. Paul
 *
 * Delcares the BirdsEyeCameraRigging class
 */

#pragma once

#include "CameraRigging.hpp"

namespace peek {

	/**
	 * A camera rigging that operates as a "bird" flying over the X-Y plane.  That is,
	 * the camera is always orthoganal to the X-Y plane, looking in the negative
	 * direction along the Z axis.
	 */
	class BirdsEyeCameraRigging : public CameraRigging {
	public:

		/** Constructs a free camera rigging with the given ground point and height */
		BirdsEyeCameraRigging(Camera::handle camera, Point2d groundPoint, double height);

		/** Constructs a free camera rigging with the given location */
		BirdsEyeCameraRigging(Camera::handle camera, Point3d location);

		/** Destructor */
		virtual ~BirdsEyeCameraRigging();

		/** Initializes the modelview matrix based on the camera's pose */
		virtual void initModelviewMatrix();

		/** Provides access to the camera being rigged */
		virtual Camera *getCamera() { return this->camera.get(); }

		/** Gets the location of the camera over the X-Y plane */
		Point2d getGroundPoint();

		/** Sets the location of the camera over the X-Y plane */
		void setGroundPoint(Point2d groundPoint);

		/** Changes the location of the camera over the X-Y plane */
		void changeGroundPoint(Vector2d deltaGroundPoint);

		/** Changes the location of the camera over the X-Y plane */
		void changeGroundPoint(double dX, double dY);

		/** Change the location of the camera along the x-axis */
		void changeX(double dX);

		/** Change the location of the camera along the y-axis */
		void changeY(double dY);

		/** Gets the height of the camera above the X-Y plane */
		virtual double getHeight();

		/** Sets the height of the camera above the X-Y plane */
		virtual void setHeight(double height);

		/** Changes the height of the camera above the X-Y plane */
		virtual void changeHeight(double deltaHeight);

		/** Provides access to the camera's location */
		inline Point3d getLocation() { return this->location; }

		/** Sets the location of the camera */
		virtual void setLocation(Point3d location) { this->location = location; }

		/** Changes the location of the camera */
		virtual void changeLocation(Vector3d deltaLocation) { this->location += deltaLocation; }

		typedef handle_traits<BirdsEyeCameraRigging>::handle_type handle;

	protected:

		/** The camera being rigged */
		Camera::handle camera;

		/** The location of the camera in worldspace */
		Point3d location;

	};

}