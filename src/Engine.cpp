/**
* @file Engine.cpp
*/

#include <boost/shared_ptr.hpp>
#include "Engine.hpp"
#include <iostream>

using boost::shared_ptr;

namespace peek {

	Engine::Engine() {
		this->screenWidth = 640;
		this->screenHeight = 480;
		this->fullscreen = false;
		init();
	}

	Engine::Engine(unsigned int screenWidth, unsigned int screenHeight, bool fullscreen) {
		this->screenWidth = screenWidth;
		this->screenHeight = screenHeight;
		this->fullscreen = fullscreen;
		init();
	}

	void Engine::init() {
		int error = SDL_Init(SDL_INIT_VIDEO);

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);

		/** @todo The next four lines may not be necessary... */
		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

		Uint32 fullscreenFlag = (this->fullscreen ? SDL_FULLSCREEN : 0);
		SDL_SetVideoMode(this->screenWidth, this->screenHeight, 0, SDL_OPENGL | fullscreenFlag);

		glViewport(0, 0, this->screenWidth, this->screenHeight);
		glEnable(GL_DEPTH_TEST);
		glShadeModel(GL_SMOOTH);
		glEnable(GL_NORMALIZE);
		glPolygonMode(GL_FRONT, GL_FILL);
		glPolygonMode(GL_BACK, GL_FILL);

		glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

		// Only for perspective camera
		glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

		SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL);

		invalidate();
	}

	void Engine::run() {
		SDL_Event evt;
		bool done = false;
	    
		while(!done) {

			// Display...
			if (this->invalid) {
				draw();
				this->invalid = false;
				SDL_GL_SwapBuffers(); // swap buffers for smooth animation
			}

			// Poll for events...
			while(SDL_PollEvent(&evt)) {
				switch(evt.type) {
					case SDL_USEREVENT:
						break;
		                
					//case SDL_KEYUP:
					case SDL_KEYDOWN:
						handleKeyEvent(evt.key);
						break;

					case SDL_MOUSEBUTTONDOWN:
					case SDL_MOUSEBUTTONUP:
						handleMouseButtonEvent(evt.button);
						break;

					case SDL_MOUSEMOTION:
						handleMouseMotionEvent(evt.motion);
						break;

					case SDL_QUIT:
						done = true;
						break;
		                
					default:
						break;
				}
			}
	            
		}
	}

	void Engine::setDrawable(Drawable *drawable) {
		this->drawable = drawable;
	}

	void Engine::setCustomEventHandler(CustomEventHandler *customEventHandler) {
		this->customEventHandler = customEventHandler;
	}

	void Engine::setKeyEventHandler(KeyEventHandler *keyEventHandler) {
		this->keyEventHandler = keyEventHandler;
	}

	void Engine::setMouseButtonEventHandler(MouseButtonEventHandler *mouseButtonEventHandler) {
		this->mouseButtonEventHandler = mouseButtonEventHandler;
	}

	void Engine::setMouseMotionEventHandler(MouseMotionEventHandler *mouseMotionEventHandler) {
		this->mouseMotionEventHandler = mouseMotionEventHandler;
	}

	void Engine::setResizeEventHandler(ResizeEventHandler *resizeEventHandler) {
		this->resizeEventHandler = resizeEventHandler;
	}

	void Engine::invalidate() {
		this->invalid = true;
	}

	void Engine::bindKey(SDLKey key, int action) {
		this->keyBindings[key] = action;
	}

	int Engine::getKeyAction(SDLKey key) {
		hash_map<SDLKey, int>::iterator i = this->keyBindings.find(key);

		if (i == this->keyBindings.end()) {
			return 0;
		}

		return i->second;
	}

	void Engine::draw() {
		if (this->drawable) {
			(*this->drawable)->draw();
		}
	}

	void Engine::handleKeyEvent(const SDL_KeyboardEvent &keyEvent) {
		if (this->customEventHandler) {
			int action = getKeyAction(keyEvent.keysym.sym);
			(*this->customEventHandler)->handleCustomEvent(action);
		}

		if (this->keyEventHandler) {
			int x, y;
			SDL_GetMouseState(&x, &y);
			(*this->keyEventHandler)->handleKeyEvent(keyEvent, x, y);
		}
	}

	void Engine::handleMouseButtonEvent(const SDL_MouseButtonEvent &mouseButtonEvent) {
		if (this->mouseButtonEventHandler) {
			(*this->mouseButtonEventHandler)->handleMouseButtonEvent(mouseButtonEvent);
		}
	}

	void Engine::handleMouseMotionEvent(const SDL_MouseMotionEvent &mouseMotionEvent) {
		if (this->mouseMotionEventHandler) {
			(*this->mouseMotionEventHandler)->handleMouseMotionEvent(mouseMotionEvent);
		}
	}

	void Engine::handleResizeEvent(int sizeX, int sizeY) {
		glViewport(0, 0, sizeX, sizeY);

		if (this->resizeEventHandler) {
			(*this->resizeEventHandler)->handleResizeEvent(sizeX, sizeY);
		}
	}

}
