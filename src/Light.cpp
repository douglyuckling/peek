/**
* @file Light.cpp
*/

#include "Peek_base.hpp"
#include "Light.hpp"

namespace peek {

	void initLight(GLenum lightNum, const Light &light) {
		float lightLocation[4] = {light.getLocation().x, light.getLocation().y, light.getLocation().z, 1.0f};

		glLightfv(lightNum, GL_POSITION, lightLocation);
		glLightfv(lightNum, GL_AMBIENT, light.getAmbient().c);
		glLightfv(lightNum, GL_DIFFUSE, light.getDiffuse().c);
		glLightfv(lightNum, GL_SPECULAR, light.getSpecular().c);
	}

}