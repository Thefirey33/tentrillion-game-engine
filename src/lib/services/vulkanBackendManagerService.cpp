
#include "services/vulkanBackendManagerService.hpp"

#include "SDL3/SDL_log.h"
#include "SDL3/SDL_vulkan.h"
#include "services/renderingService.hpp"

#include <iostream>

TenTrillionGameEngine::VulkanBackendManagerService::VulkanBackendManagerService(
	RenderingService *renderingService, TentrillionEngine *engine)
	: TenTrillionService("VulkanBackendManagerService", engine) {
	this->renderingService = renderingService;

	if (!SDL_Vulkan_GetInstanceExtensions(&this->vkExtensionCount)) {
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION,
					"vulkan instance extensions could not be retrieved, "
					"defaulting to OpenGL.\n");
		renderingService->backend = OPENGL;
		return;
	}

	renderingService->backend = VULKAN;
}