#pragma once

#include "pch.h"

namespace NOPEEngine {
	class NOPE_API EventContext {
	public:
		virtual ~EventContext() = default;
	};

	class NOPE_API WindowResizedEvent : public EventContext {
	public:
		WindowResizedEvent(int32_t width, int32_t height) : mWidth(width), mHeight(height) {}

		NOPE_FORCE_INLINE int32_t GetWidth() const { return mWidth; }
		NOPE_FORCE_INLINE int32_t GetHeight() const { return mHeight; }

	private:
		int32_t mWidth, mHeight;

	};

	class NOPE_API KeyPressedEvent : public EventContext {
	public:
		KeyPressedEvent(int32_t keyCode) :mKeyCode(keyCode) {}
		NOPE_FORCE_INLINE int32_t GetKeyCode()const { return mKeyCode; }

	private:
		int32_t mKeyCode;
	};

	class NOPE_API KeyHeldEvent : public EventContext {
	public:
		KeyHeldEvent(int32_t keyCode) :mKeyCode(keyCode) {}
		NOPE_FORCE_INLINE int32_t GetKeyCode()const { return mKeyCode; }

	private:
		int32_t mKeyCode;
	};

	class NOPE_API KeyReleaseEvent : public EventContext {
	public:
		KeyReleaseEvent(int32_t keyCode) :mKeyCode(keyCode) {}
		NOPE_FORCE_INLINE int32_t GetKeyCode()const { return mKeyCode; }

	private:
		int32_t mKeyCode;
	};

	class NOPE_API MouseMoveEvent : public EventContext {
	public:
		MouseMoveEvent(double x, double y, double offsetX, double offsetY) :
			xPosition(x),
			yPosition(y),
			xOffset(offsetX),
			yOffset(offsetY) {}

		NOPE_FORCE_INLINE double GetX() const { return xPosition; }
		NOPE_FORCE_INLINE double GetY()const { return yPosition; }
		NOPE_FORCE_INLINE double GetXOffset() const { return xOffset; }
		NOPE_FORCE_INLINE double GetYOffset() const { return yOffset; }

	private:
		double xPosition, yPosition;
		double xOffset, yOffset;
	};

	class NOPE_API MouseScrolledEvent : public EventContext {
	public:
		MouseScrolledEvent(double offsetX, double offsetY) : xOffset(offsetX), yOffset(offsetY) {}
		NOPE_FORCE_INLINE double GetOffsetX() const { return xOffset; }
		NOPE_FORCE_INLINE double GetOffsetY() const { return yOffset; }
	private:
		double xOffset, yOffset;
	};

	class NOPE_API MouseButtonPressedEvent : public EventContext {
	public:
		MouseButtonPressedEvent(int32_t button) : mButton(button) {}
		NOPE_FORCE_INLINE int32_t GetButton() const { return mButton; }
	private:
		int32_t mButton;
	};

	class NOPE_API MouseButtonHeldEvent : public EventContext {
	public:
		MouseButtonHeldEvent(int32_t button) : mButton(button) {}
		NOPE_FORCE_INLINE int32_t GetButton() const { return mButton; }
	private:
		int32_t mButton;
	};

	class NOPE_API MouseButtonReleasedEvent : public EventContext {
	public:
		MouseButtonReleasedEvent(int32_t button) : mButton(button) {}
		NOPE_FORCE_INLINE int32_t GetButton() const { return mButton; }
	private:
		int32_t mButton;
	};
}