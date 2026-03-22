
#ifndef TENTRILLIONGAMEENGINE_TENTRILLION_H

#include "services/renderingService.hpp"
#include <memory>
#include <tentrillion_export.h>

#define TENTRILLION_GAME_ENGINE_VER 0.1

namespace TenTrillionGameEngine {

class TENTRILLION_GAME_ENGINE_EXPORT TentrillionEngine {
  private:
	void displayInformation();

	std::unique_ptr<RenderingService> windowService;

  public:
	// Constructor for the engine.
	TentrillionEngine();
	~TentrillionEngine();
	// This initializes the TenTrillion's Services required for it to function.
	void init();
	// This quits the engine instance.
	void quit();
};
} // namespace TenTrillionGameEngine
#endif // !TENTRILLIONGAMEENGINE_TENTRILLION_H