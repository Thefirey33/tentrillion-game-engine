#ifndef TENTRILLIONGAMEENGINE_WINDOWSERVICE_H
#define TENTRILLIONGAMEENGINE_WINDOWSERVICE_H

#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"
#include "services/vulkanBackendManagerService.hpp"
#include "tentrillionService.hpp"
#include <functional>
#include <memory>
namespace TenTrillionGameEngine {

enum RenderingBackend { OPENGL, VULKAN };
class TENTRILLION_GAME_ENGINE_EXPORT RenderingService
	: public TenTrillionService {
	std::unique_ptr<VulkanBackendManagerService> vulkanBackendManagerService;

	int windowWidth{0};
	int windowHeight{0};

	SDL_Window *windowInstance{};
	SDL_Renderer *rendererInstance{};

  public:
	// The current rendering backend being used.
	RenderingBackend backend;

	/* The Initializer of the TenTrillion Rendering Service.
	 * @param windowWidth Window Width.
	 * @param windowHeight Window Height.
	 * @param windowTitle Window Title.
	 */
	RenderingService(int windowWidth, int windowHeight, const char *windowTitle,
					 TenTrillionGameEngine::TentrillionEngine *engine);

	[[nodiscard]] SDL_Window *getWindowInstance() const;

	/* This function only executes it's callback code on VULKAN instances.
	 * @param callback the function to execute.
	 */
	void executeOnVulkanOnly(const std::function<void()> &callback) const;

	/*
	 * This function only executes it's callback code on OPENGL instances.
	 * @param callback the function to execute.
	 */
	void executeOnOpenGlOnly(const std::function<void()> &callback) const;

	// Quit the rendering instance.
	void quitService() override;
};

} // namespace TenTrillionGameEngine

#endif // !TENTRILLIONGAMEENGINE_WINDOWSERVICE_H