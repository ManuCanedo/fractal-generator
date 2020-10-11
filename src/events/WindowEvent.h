#pragma once

#include "Event.h"

namespace Fractal
{
	class WindowEvent : public Event
	{
	public:
		inline virtual EventType GetEventType() const = 0;
		inline virtual std::string ToString() const = 0;
	};

	class WindowCloseEvent : public WindowEvent
	{
	public:
		WindowCloseEvent() = default;

		static EventType GetStaticType() { return EventType::WindowClose; }

		EventType GetEventType() const override { return GetStaticType(); }
		std::string ToString() const { return "WindowCloseEvent"; }
	};

	class WindowResizeEvent : public WindowEvent
	{
	public:
		WindowResizeEvent(int width, int height)
			: m_Width(width), m_Height(height) {}

		int GetWidth() { return m_Width; }
		int GetHeight() { return m_Height; }
		
		static EventType GetStaticType() { return EventType::WindowResize; }

		EventType GetEventType() const override { return GetStaticType(); }
		std::string ToString() const
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: (" << m_Width << "," << m_Height << ")";
			return ss.str();
		}

	private:
		int m_Width, m_Height;
	};
}

