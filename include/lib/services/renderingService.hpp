#ifndef TENTRILLIONGAMEENGINE_WINDOWSERVICE_H
#define TENTRILLIONGAMEENGINE_WINDOWSERVICE_H

#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"
#include "tentrillionService.hpp"
namespace TenTrillionGameEngine {

enum RenderingBackend { OPENGL, VULKAN };
class TENTRILLION_GAME_ENGINE_EXPORT RenderingService
	: public TenTrillionService {
  private:
	int windowWidth{0};
	int windowHeight{0};
	RenderingBackend backend;

	SDL_Window *windowInstance;
	SDL_Renderer *rendererInstance;

  public:
	RenderingService(int windowWidth, int windowHeight,
					 const char *windowTitle);
	void quitService() override;
};
} // namespace TenTrillionGameEngine

#endif // !TENTRILLIONGAMEENGINE_WINDOWSERVICE_H