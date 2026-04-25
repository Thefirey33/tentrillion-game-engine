#include "renderingService.hpp"

#include "SDL3/SDL_init.h"
#include "SDL3/SDL_video.h"
#include "SDL3/SDL_vulkan.h"
#include "backends/openGlBackendManagerService.hpp"
#include "backends/softwareBackendManager.hpp"
#include "backends/vulkanBackendManagerService.hpp"
#include "tentrillion.hpp"
#include "tentrillionService.hpp"
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

#include <memory>

namespace TenTrillionGameEngine {
RenderingService::RenderingService(const Vector windowSize,
								   const char *windowTitle,
								   TentrillionEngine *engine)
	: TenTrillionService("WindowService", engine) {
	this->windowSize = windowSize;
	backend = SDL_Vulkan_LoadLibrary(nullptr) ? VULKAN
			  : SDL_GL_LoadLibrary(nullptr)	  ? OPENGL
											  : SOFTWARE;

	this->windowInstance =
		SDL_CreateWindow(windowTitle, this->windowSize.x, this->windowSize.z,
						 backend			 ? SDL_WINDOW_VULKAN
						 : backend == OPENGL ? SDL_WINDOW_OPENGL
											 : 0);

	// Create the specified backend for the engine to use.
	switch (backend) {
	case VULKAN:
		this->renderingBackendService = std::unique_ptr<TenTrillionService>(
			new VulkanBackendManagerService(this, engine));
		break;
	case OPENGL:
		this->renderingBackendService = std::unique_ptr<TenTrillionService>(
			new OpenGlBackendManagerService(this, engine));
		break;
	case SOFTWARE:
		this->renderingBackendService = std::unique_ptr<TenTrillionService>(
			new SoftwareBackendManager(this, engine));
		break;
	}
}

Vector &RenderingService::getWindowSize() { return this->windowSize; }

SDL_Renderer *RenderingService::getRendererInstance() const {
	return rendererInstance;
}

void RenderingService::setRendererInstance(SDL_Renderer *m_rendererInstance) {
	this->rendererInstance = m_rendererInstance;
}

SDL_Window *RenderingService::getWindowInstance() const {
	return this->windowInstance;
}

void RenderingService::quitService() { SDL_Quit(); }
} // namespace TenTrillionGameEngine