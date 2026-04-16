

#include "backends/softwareBackendManager.hpp"

#include "renderingService.hpp"

TenTrillionGameEngine::SoftwareBackendManager::SoftwareBackendManager(
	RenderingService *renderingService, TentrillionEngine *tenTrillionEngine)
	: RenderingBackendManager(renderingService, tenTrillionEngine) {

	currentRenderingSurface =
		SDL_GetWindowSurface(renderingService->getWindowInstance());

	renderingService->setRendererInstance(
		SDL_CreateSoftwareRenderer(currentRenderingSurface));
}