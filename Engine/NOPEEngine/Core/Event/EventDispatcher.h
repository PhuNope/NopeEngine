#pragma once

#include "EventAction.h"

namespace NOPEEngine {
	using EventActionList = std::vector<IEventAction*>;

	class NOPE_API EventDispatcher {
		friend class Application;

	public:
		~EventDispatcher();

		template<typename T>
		void AddEventListener(const EventCallback<T>& callback) {
			NOPE_STATIC_ASSERT(std::is_base_of<EventContext, T>::value && "Add invalid event context!");

			const char* eventType = typeid(T).name();
			IEventAction* eventAction = new EventAction<T>(callback);
			mEventActionMap[eventType].emplace_back(eventAction);
		}

		template<typename T>
		void DispatchEventListener(const T& eventContext) {
			NOPE_STATIC_ASSERT(std::is_base_of<EventContext, T>::value && "Dispatch invalid event context!");

			const char* eventType = typeid(T).name();
			NOPE_ASSERT(mEventActionMap.find(eventType) != mEventActionMap.end() && "Unknown event type!");
			for (auto eventAction : mEventActionMap.at(eventType)) {
				if (eventAction->Execute(&eventContext)) {
					break;
				}
			}
		}

	private:
		EventDispatcher();

		std::unordered_map<const char*, EventActionList> mEventActionMap;
	};
}