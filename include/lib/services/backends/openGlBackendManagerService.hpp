

#ifndef TEN_TRILLION_OPENGLBACKENDMANAGERSERVICE_H
#define TEN_TRILLION_OPENGLBACKENDMANAGERSERVICE_H
#include "renderingBackend.hpp"
#include "tentrillionService.hpp"
#include <SDL3/SDL_video.h>

namespace TenTrillionGameEngine {
class RenderingService;
class TENTRILLION_GAME_ENGINE_EXPORT OpenGlBackendManagerService
	: public TenTrillionGameEngine::RenderingBackendManager {

	SDL_GLContext openGlContext;

  public:
	explicit OpenGlBackendManagerService(RenderingService *renderingService,
										 TentrillionEngine *tenTrillionEngine);
};
} // namespace TenTrillionGameEngine

#endif // TEN_TRILLION_OPENGLBACKENDMANAGERSERVICE_H
