#include <cstdlib>

#include "backends/vulkanBackendManagerService.hpp"

#include "SDL3/SDL_log.h"
#include "SDL3/SDL_vulkan.h"
#include "services/renderingService.hpp"
#include <SDL3/SDL.h>

#include <algorithm>
#include <vulkan/vulkan_core.h>

TenTrillionGameEngine::VulkanBackendManagerService::VulkanBackendManagerService(
	RenderingService *renderingService, TentrillionEngine *engine)
	: RenderingBackendManager(renderingService, engine) {
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

std::vector<TenTrillionGameEngine::GpuInformation> TenTrillionGameEngine::
	VulkanBackendManagerService::getAvailableGpuInformation() {
	std::vector<GpuInformation> availableGpuInformation = {};
	uint32_t physicalDeviceCount = 0;
	vkEnumeratePhysicalDevices(this->vkInstance, &physicalDeviceCount, nullptr);
	std::vector<VkPhysicalDevice> physicalDevices(physicalDeviceCount);
	vkEnumeratePhysicalDevices(this->vkInstance, &physicalDeviceCount,
							   physicalDevices.data());
	// Retrieve the current GPU information by querying the information provided
	// by vulkan.
	std::for_each(
		physicalDevices.begin(), physicalDevices.end(),
		[&](const VkPhysicalDevice &device) {
			VkPhysicalDeviceProperties physicalDeviceProperties;
			vkGetPhysicalDeviceProperties(device, &physicalDeviceProperties);
			availableGpuInformation.push_back(
				{physicalDeviceProperties.deviceName,
				 std::to_string(physicalDeviceProperties.driverVersion)});
		});

	return availableGpuInformation;
}

void TenTrillionGameEngine::VulkanBackendManagerService::
	refreshVulkanInstance() {

	const char *const *vkInstanceExtensions =
		SDL_Vulkan_GetInstanceExtensions(&this->vkInstanceExtensionsCount);

	if (vkInstanceExtensions == nullptr) {
		SDL_LogWarn(
			SDL_LOG_CATEGORY_APPLICATION,
			"Attempted to recieve Instance Extensions, ENDED IN FAILURE!");
		exit(1);
	}

	VkInstanceCreateInfo vkInstanceCreateInfo = {};
	vkInstanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	vkInstanceCreateInfo.enabledExtensionCount =
		this->vkInstanceExtensionsCount;
	vkInstanceCreateInfo.ppEnabledExtensionNames = vkInstanceExtensions;

	// Attempt to create a vulkan instance, if failure, report the error to
	// the user and force switch back to the OpenGL runtime.
	if (vkCreateInstance(&vkInstanceCreateInfo, nullptr, &this->vkInstance) !=
		VK_SUCCESS) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
					 "Failed to create Vulkan instance\n");
		exit(1);
	}

	const std::vector<GpuInformation> &availableGpuInformation =
		this->getAvailableGpuInformation();

	std::for_each(
		availableGpuInformation.begin(), availableGpuInformation.end(),
		[&](const GpuInformation &gpuInfo) {
			SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
						"Vulkan GPU: %s, VERSION %s", gpuInfo.gpuName.c_str(),
						gpuInfo.driverVersion.c_str());
		});
	if (!SDL_Vulkan_CreateSurface(renderingService->getWindowInstance(),
								  this->vkInstance, nullptr,
								  &this->vkSurfaceKhr)) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
					 "Failed to create VULKAN surface!");
		exit(1);
	}
}

void TenTrillionGameEngine::VulkanBackendManagerService::quitService() {
	vkDestroyInstance(this->vkInstance, nullptr);
}