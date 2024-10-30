#pragma once

#include "EventContext.h"

namespace NOPEEngine {
	template<typename T> using EventCallback = std::function<bool(const T&)>;

	class NOPE_API IEventAction {
	public:
		virtual ~IEventAction() = default;
		virtual bool Execute(const EventContext*) = 0;

	};

	template<typename T>
	class NOPE_API EventAction :public IEventAction {
	public:
		EventAction(const EventCallback<T>& callback) : mCallBack(callback) {}

		virtual bool Execute(const EventContext* eventContext) override {
			NOPE_STATIC_ASSERT(std::is_base_of<EventContext, T>::value && "Invalid event context!");
			return mCallBack(*(T*)eventContext);
		}

	private:
		EventCallback<T> mCallBack;
	};
}