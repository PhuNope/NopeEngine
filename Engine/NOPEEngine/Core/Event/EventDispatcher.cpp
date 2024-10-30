#include "EventDispatcher.h"

namespace NOPEEngine {
	EventDispatcher::EventDispatcher() :mEventActionMap() {}

	EventDispatcher::~EventDispatcher() {
		for (auto& pair : mEventActionMap) {
			for (auto eventAction : pair.second) {
				NOPE_FREE_MEMORY(eventAction)
			}
			pair.second.clear();
		}

		mEventActionMap.clear();
	}
}