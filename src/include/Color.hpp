/**
 * @file Color.hpp
 */
#pragma once

// Implementation dependencies
#include "Peek_base.hpp"

namespace peek {

	class Color {
	public:
		float c[4];

		inline Color() {
			this->c[0] = 0.0f;
			this->c[1] = 0.0f;
			this->c[2] = 0.0f;
			this->c[3] = 1.0f;
		}

		inline Color(float r, float g, float b) {
			this->c[0] = r;
			this->c[1] = g;
			this->c[2] = b;
			this->c[3] = 1.0f;
		}

		inline Color(float r, float g, float b, float a) {
			this->c[0] = r;
			this->c[1] = g;
			this->c[2] = b;
			this->c[3] = a;
		}

		inline Color(const Color &otherColor) {
			this->c[0] = otherColor.c[0];
			this->c[1] = otherColor.c[1];
			this->c[2] = otherColor.c[2];
			this->c[3] = otherColor.c[3];
		}

		// Some common colors
		static const Color white;
		static const Color red;
		static const Color green;
		static const Color blue;
		static const Color cyan;
		static const Color magenta;
		static const Color yellow;
		static const Color black;
		static const Color gray;
		static const Color pink;
		static const Color orange;
		static const Color lime;
		static const Color teal;
		static const Color purple;
		static const Color sky;
	};

	inline void useColor(const Color &color) { glColor4fv(color.c); }

}
