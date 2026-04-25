#ifndef TEN_TRILLION_VULKANBACKENDMANAGERSERVICE_H
#define TEN_TRILLION_VULKANBACKENDMANAGERSERVICE_H
#include "SDL3/SDL_vulkan.h"
#include "renderingBackend.hpp"
#include "tentrillionService.hpp"

#include <vector>
#include <vulkan/vulkan.h>

namespace TenTrillionGameEngine {

struct GpuInformation;
class RenderingService;

class TENTRILLION_GAME_ENGINE_EXPORT VulkanBackendManagerService
	: public RenderingBackendManager {
	unsigned int vkInstanceExtensionsCount{0};

	/**
	 * The current VULKAN instance.
	 */
	VkInstance vkInstance{};
	/**
	 * The VULKAN surface that is being used. The TenTrillion Vulkan Backend
	 * uses its own surface and rendering logic compared to the other backends,
	 * which use SDL_Surface.
	 */
	VkSurfaceKHR vkSurfaceKhr{};

	/**
	 * The Physical Device of the VULKAN instance.
	 */
	VkPhysicalDevice vkPhysicalDevice{};

	/**
	 * Current VULKAN device of the TenTrillion.
	 */
	VkDevice vkDevice{};
	VkQueue graphicsQueue{};
	VkQueue presentQueue{};

  public:
	/**
	 * Get the current Vulkan Instance.
	 * @return Vulkan Instance.
	 */
	VkInstance &getVkInstance();
	/**
	 * This creates a VULKAN instance to be used.
	 */
	void refreshVulkanInstance();
	/**
	 * This creates the VULKAN backend for the TenTrillion. Can be also used to
	 * retrieve VULKAN information.
	 * @param renderingService The current rendering service being used.
	 * @param engine The TenTrillion Game Engine reference.
	 */
	explicit VulkanBackendManagerService(RenderingService *renderingService,
										 TentrillionEngine *engine);

	/**
	 * Create the VULKAN instance.
	 */
	void createVkInstance();

	/**
	 * Create the VULKAN device responsible for the rendering.
	 */
	void createVkDevice();

	/**
	 * @brief This quits the current Vulkan Instance.
	 */
	void quitService() override;
};
}; // namespace TenTrillionGameEngine

#endif // TEN_TRILLION_VULKANBACKENDMANAGERSERVICE_H