/**
 * \file OrthoBirdsEyeCameraRigging.hpp
 * \author Douglas W. Paul
 *
 * Delcares the OrthoBirdsEyeCameraRigging class
 */

#pragma once

#include "BirdsEyeCameraRigging.hpp"
#include "OrthoCameraRigging.hpp"

namespace peek {

	/**
	 * A special version of the birds-eye camera rigging for othrographic cameras.  The
	 * main purpose of the special class is to properly handle "zooming".
	 */
	class OrthoBirdsEyeCameraRigging : public virtual BirdsEyeCameraRigging, public virtual OrthoCameraRigging {
	public:

		/** Constructs a free camera rigging with the given ground point and height */
		OrthoBirdsEyeCameraRigging(OrthographicCamera::handle camera, Point2d groundPoint, double height, double fov);

		/** Constructs a free camera rigging with the given location */
		OrthoBirdsEyeCameraRigging(OrthographicCamera::handle camera, Point3d location, double fov);

		/** Destructor */
		virtual ~OrthoBirdsEyeCameraRigging();

		/** Initializes the modelview matrix based on the camera's pose */
		virtual void initModelviewMatrix();

		/** Provides access to the camera being rigged */
		virtual Camera *getCamera();

		/** Provides access to the camera being rigged */
		inline OrthographicCamera *getOrthoCamera() { return this->orthoCamera.get(); }

		/** Gets the height of the camera above the X-Y plane */
		virtual double getHeight();

		/** Sets the height of the camera above the X-Y plane */
		virtual void setHeight(double height);

		/** Changes the height of the camera above the X-Y plane */
		virtual void changeHeight(double deltaHeight);

		/** Sets the location of the camera */
		virtual void setLocation(Point3d location);

		/** Changes the location of the camera */
		virtual void changeLocation(Vector3d deltaLocation);

		/** Gets the rigging's field-of-view
		 * \return The rigging's field-of-view in degrees
		 */
		inline double getFov() {return this->fov;}

		/** Sets the rigging's field-of-view */
		void setFov(double fov);

		typedef handle_traits<OrthoBirdsEyeCameraRigging>::handle_type handle;

	protected:

		/** Updates the orthographic camera's width */
		void updateWidth();

		/** The orthographic camera being rigged */
		OrthographicCamera::handle orthoCamera;

		/** The rigging's field-of-view */
		double fov;

		/** The rigging's virtual z-coordinate */
		double virtualZ;

	};

}