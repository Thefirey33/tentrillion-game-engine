
#include "services/vulkanBackendManagerService.hpp"

#include "SDL3/SDL_log.h"
#include "SDL3/SDL_vulkan.h"
#include "services/renderingService.hpp"
#include <vulkan/vulkan_core.h>

TenTrillionGameEngine::VulkanBackendManagerService::VulkanBackendManagerService(
	RenderingService *renderingService, TentrillionEngine *engine)
	: TenTrillionService("VulkanBackendManagerService", engine) {
	// Assign the current pointer reference of the renderingService to the
	// variable.

	this->renderingService = renderingService;
	renderingService->backend = VULKAN;

	this->refreshVulkanInstance();
}

VkInstance &
TenTrillionGameEngine::VulkanBackendManagerService::getVkInstance() {
	return this->vkInstance;
}

void TenTrillionGameEngine::VulkanBackendManagerService::
	refreshVulkanInstance() {

	const char *const *vkInstanceExtensions =
		SDL_Vulkan_GetInstanceExtensions(&this->vkInstanceExtensionsCount);

	if (vkInstanceExtensions == nullptr) {
		SDL_LogWarn(
			SDL_LOG_CATEGORY_APPLICATION,
			"Attempted to recieve Instance Extensions, ENDED IN FAILURE!");
		renderingService->backend = OPENGL;
		return;
	}

	renderingService->executeOnVulkanOnly([&] {
		VkInstanceCreateInfo vkInstanceCreateInfo = {};
		vkInstanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		vkInstanceCreateInfo.enabledExtensionCount =
			this->vkInstanceExtensionsCount;
		vkInstanceCreateInfo.ppEnabledExtensionNames = vkInstanceExtensions;

		// Attempt to create a vulkan instance, if failure, report the error to
		// the user and force switch back to the OpenGL runtime.
		if (vkCreateInstance(&vkInstanceCreateInfo, nullptr,
							 &this->vkInstance) != VK_SUCCESS) {
			SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION,
						"Failed to create Vulkan instance");
			renderingService->backend = OPENGL;
		}

		// Create the specified vulkan surface and assign it to the current
		// TenTrillion Instance.
		SDL_Vulkan_CreateSurface(renderingService->getWindowInstance(),
								 this->vkInstance, nullptr,
								 &this->vkSurfaceKhr);
	});
}