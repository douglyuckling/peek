/**
* @file Engine.hpp
*/
#pragma once

#include "Peek_base.hpp"
#include <boost/optional.hpp>
#include "Drawable.hpp"
#include "KeyEventHandler.hpp"
#include "CustomEventHandler.hpp"
#include "MouseButtonEventHandler.hpp"
#include "MouseMotionEventHandler.hpp"
#include "ResizeEventHandler.hpp"
#include <hash_map>

using boost::optional;
using stdext::hash_map;

namespace peek {

	/**
	* @brief The Peek engine
	*/
	class Engine {
	public:

		/** Constructor */
		Engine();

		/** Constructor */
		Engine(unsigned int screenWidth, unsigned int screenHeight, bool fullscreen);

		/** Runs the given application */
		void run();

		/** Gets the screen width */
		unsigned int getScreenWidth() const { return this->screenWidth; }

		/** Gets the screen height */
		unsigned int getScreenHeight() const { return this->screenHeight; }

		/** Gets whether or not the engine is fullscreen */
		bool isFullscreen() const { return this->fullscreen; }

		/** Set the thing to draw */
		void setDrawable(Drawable *drawable);

		/** Set custom event handler */
		void setCustomEventHandler(CustomEventHandler *customEventHandler);

		/** Set key event handler */
		void setKeyEventHandler(KeyEventHandler *keyEventHandler);

		/** Set mouse button event handler */
		void setMouseButtonEventHandler(MouseButtonEventHandler *mouseButtonEventHandler);

		/** Set mouse motion event handler */
		void setMouseMotionEventHandler(MouseMotionEventHandler *mouseMotionEventHandler);

		/** Set the resize event handler */
		void setResizeEventHandler(ResizeEventHandler *resizeEventHandler);

		/** Invalidates the current rendering, indicating that it needs to be redrawn */
		void invalidate();

		/** Bind a key to an action */
		void bindKey(SDLKey key, int action);

		/** Gets the action associated with a key, or 0 if no action is associated with the key. */
		int getKeyAction(SDLKey key);

	protected:

		/** The width of the screen, in pixels */
		unsigned int screenWidth;

		/** The height of the screen, in pixels */
		unsigned int screenHeight;

		/** Whether or not the engine is fullscreen */
		bool fullscreen;

		/** Whether or not the current rendering is invalid (out of date) */
		bool invalid;

		/** Initialize the engine */
		void init();

		/** Draw */
		void draw();

		/** Key bindings; maps from key to event */
		hash_map<SDLKey, int> keyBindings;

		/** Handle a keypress */
		void handleKeyEvent(const SDL_KeyboardEvent &keyEvent);

		/** Handle a mouse button press/release */
		void handleMouseButtonEvent(const SDL_MouseButtonEvent &mouseButtonEvent);

		/** Handle a mouse movement */
		void handleMouseMotionEvent(const SDL_MouseMotionEvent &mouseMotionEvent);

		/** Handle a resize event */
		void handleResizeEvent(int sizeX, int sizeY);

		/** The drawable */
		optional<Drawable *> drawable;

		/** The custom event handler */
		optional<CustomEventHandler*> customEventHandler;

		/** The keyboard event handler */
		optional<KeyEventHandler*> keyEventHandler;

		/** The mouse button event handler */
		optional<MouseButtonEventHandler*> mouseButtonEventHandler;

		/** The mouse motion event handler */
		optional<MouseMotionEventHandler*> mouseMotionEventHandler;

		/** The resize event handler */
		optional<ResizeEventHandler*> resizeEventHandler;
	};

}