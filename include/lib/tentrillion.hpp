
#include "services/vulkanBackendManagerService.hpp"
#ifndef TENTRILLIONGAMEENGINE_TENTRILLION_H

#include "services/renderingService.hpp"

#include <map>
#include <memory>
#include <tentrillion_export.h>

#define TENTRILLION_GAME_ENGINE_VER 0.1

namespace TenTrillionGameEngine {

class TENTRILLION_GAME_ENGINE_EXPORT TentrillionEngine {
  protected:
	std::unique_ptr<RenderingService> renderingService;
	static TentrillionEngine *tenTrillionInstance;

  public:
	// Constructor for the engine.
	TentrillionEngine();
	// This initializes the ten-trillion instance.
	void initializeInstance(int windowWidth, int windowHeight,
							const char *windowTitle);

	// This gets the current TenTrillion Instance.
	static TentrillionEngine *getTenTrillionInstance();
	// This quits the ten-trillion instance.
	void exitInstance();
};
} // namespace TenTrillionGameEngine
#endif // !TENTRILLIONGAMEENGINE_TENTRILLION_H