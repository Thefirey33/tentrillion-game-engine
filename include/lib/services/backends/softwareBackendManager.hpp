

#ifndef TEN_TRILLION_SOFTWAREBACKENDMANAGER_HPP
#define TEN_TRILLION_SOFTWAREBACKENDMANAGER_HPP
#include "renderingBackend.hpp"

namespace TenTrillionGameEngine {
class RenderingService;

class TENTRILLION_GAME_ENGINE_EXPORT SoftwareBackendManager
	: public RenderingBackendManager {
  public:
	explicit SoftwareBackendManager(RenderingService *renderingService,
									TentrillionEngine *tenTrillionEngine);
};
} // namespace TenTrillionGameEngine

#endif // TEN_TRILLION_SOFTWAREBACKENDMANAGER_HPP
