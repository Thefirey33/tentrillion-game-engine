

#ifndef TEN_TRILLION_OPENGLBACKENDMANAGERSERVICE_H
#define TEN_TRILLION_OPENGLBACKENDMANAGERSERVICE_H
#include "renderingBackend.hpp"
#include "tentrillionService.hpp"

namespace TenTrillionGameEngine {
class RenderingService;
class TENTRILLION_GAME_ENGINE_EXPORT OpenGlBackendManagerService
	: public TenTrillionGameEngine::RenderingBackendManager {

  public:
	explicit OpenGlBackendManagerService(RenderingService *renderingService,
										 TentrillionEngine *tenTrillionEngine);
};
} // namespace TenTrillionGameEngine

#endif // TEN_TRILLION_OPENGLBACKENDMANAGERSERVICE_H
