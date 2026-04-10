
#ifndef TEN_TRILLION_VULKANBACKENDMANAGERSERVICE_H
#define TEN_TRILLION_VULKANBACKENDMANAGERSERVICE_H
#include "SDL3/SDL_vulkan.h"
#include "tentrillionService.hpp"

#include <vector>

namespace TenTrillionGameEngine {
class RenderingService;
class VulkanBackendManagerService : public TenTrillionService {
	unsigned int vkInstanceExtensionsCount{0};
	RenderingService *renderingService;

	// The vulkan instance that is currently in charge.
	VkInstance vkInstance{};
	VkSurfaceKHR vkSurfaceKhr{};

  public:
	// Get the current vkInstance, from the Vulkan.
	VkInstance &getVkInstance();

	// Create or Re-Create the current VULKAN instance;
	void refreshVulkanInstance();

	explicit VulkanBackendManagerService(RenderingService *renderingService,
										 TentrillionEngine *engine);
};
}; // namespace TenTrillionGameEngine

#endif // TEN_TRILLION_VULKANBACKENDMANAGERSERVICE_H
