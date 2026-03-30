
#ifndef TENTRILLIONGAMEENGINE_TENTRILLION_H

#include "services/renderingService.hpp"

#include <map>
#include <memory>
#include <tentrillion_export.h>

#define TENTRILLION_GAME_ENGINE_VER 0.1

namespace TenTrillionGameEngine {

class TENTRILLION_GAME_ENGINE_EXPORT TentrillionEngine {
  protected:
	std::map<std::string, TenTrillionService *> TenTrillionServices = {};

  public:
	// Constructor for the engine.
	TentrillionEngine();

	/**
	 * This gets a Ten-Trillion Service by a name reference.
	 * @param name The name of the service to reference.
	 * @return The service that will be returned.
	 */
	TenTrillionService *getTenTrillionServiceByName(const std::string &name);

	/**
	 * This gets a Ten-Trillion Service by a typename.
	 * @tparam T The type to cast to.
	 * @param name The name of the service.
	 * @return The cast service.
	 */
	template <class T> T getTenTrillionServiceByName(const std::string &name) {
		auto ref = this->getTenTrillionServiceByName(name);
		return std::dynamic_pointer_cast<T>(ref);
	}

	/**
	 * This creates a new Ten-Trillion service.
	 * @param service The service pointer.
	 */
	void addTenTrillionService(TenTrillionService *service);

	/**
	 * This initializes the TenTrillion's Services required for it to
	 * function.
	 */
	void init(int windowWidth, int windowHeight, const char *windowTitle);
	/**
	 * This quits the current TenTrillion Instance.
	 */
	void quit();
};
} // namespace TenTrillionGameEngine
#endif // !TENTRILLIONGAMEENGINE_TENTRILLION_H