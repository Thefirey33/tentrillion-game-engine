#include <cstdlib>

#include "backends/vulkanBackendManagerService.hpp"

#include "SDL3/SDL_log.h"
#include "SDL3/SDL_vulkan.h"
#include "services/renderingService.hpp"
#include <SDL3/SDL.h>

#include <algorithm>
#include <iostream>
#include <ostream>
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

void TenTrillionGameEngine::VulkanBackendManagerService::createVkInstance() {
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
	if (vkCreateInstance(&vkInstanceCreateInfo, nullptr, &this->vkInstance) !=
		VK_SUCCESS) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
					 "Failed to create Vulkan instance\n");
		exit(1);
	}

	uint32_t physicalDeviceCount = 0;
	vkEnumeratePhysicalDevices(this->vkInstance, &physicalDeviceCount, nullptr);
	std::vector<VkPhysicalDevice> physicalDevices(physicalDeviceCount);
	vkEnumeratePhysicalDevices(this->vkInstance, &physicalDeviceCount,
							   physicalDevices.data());

	this->vkPhysicalDevice = physicalDevices[0];
}

void TenTrillionGameEngine::VulkanBackendManagerService::createVkDevice() {
	uint32_t queueFamilyCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties(this->vkPhysicalDevice,
											 &queueFamilyCount, nullptr);
	std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
	vkGetPhysicalDeviceQueueFamilyProperties(
		this->vkPhysicalDevice, &queueFamilyCount, queueFamilies.data());

	uint32_t graphicsQueueFamilyIndex{UINT32_MAX};
	uint32_t presentQueueFamilyIndex{UINT32_MAX};
	VkBool32 supportsGraphicsQueue{false};
	uint32_t i{0};

	for (const VkQueueFamilyProperties queueFamily : queueFamilies) {
		if (graphicsQueueFamilyIndex == UINT32_MAX &&
			queueFamily.queueCount > 0 &&
			queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)
			graphicsQueueFamilyIndex = i;

		if (presentQueueFamilyIndex == UINT32_MAX)
			vkGetPhysicalDeviceSurfaceSupportKHR(this->vkPhysicalDevice, i,
												 this->vkSurfaceKhr,
												 &supportsGraphicsQueue);
		if (supportsGraphicsQueue)
			presentQueueFamilyIndex = i;
		++i;
	}
	float queuePriority{1.0f};
	VkDeviceQueueCreateInfo vkDeviceQueueCreateInfo = {
		VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
		nullptr,
		0,
		graphicsQueueFamilyIndex,
		1,
		&queuePriority};

	VkPhysicalDeviceFeatures deviceFeatures = {};
	const char *deviceExtensionNames[] = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};

	const VkDeviceCreateInfo deviceCreateInfo = {
		VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
		nullptr,
		0,
		1,
		&vkDeviceQueueCreateInfo,
		0,
		nullptr,
		1,
		deviceExtensionNames,
		&deviceFeatures};

	vkCreateDevice(this->vkPhysicalDevice, &deviceCreateInfo, nullptr,
				   &this->vkDevice);
}

void TenTrillionGameEngine::VulkanBackendManagerService::
	refreshVulkanInstance() {
	this->createVkInstance();

	if (!SDL_Vulkan_CreateSurface(this->renderingService->getWindowInstance(),
								  this->vkInstance, nullptr,
								  &this->vkSurfaceKhr)) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
					 "Failed to create Vulkan surface");
		exit(1);
	}

	this->createVkDevice();
}

void TenTrillionGameEngine::VulkanBackendManagerService::quitService() {
	vkDestroyDevice(this->vkDevice, nullptr);
	vkDestroySurfaceKHR(this->vkInstance, this->vkSurfaceKhr, nullptr);
	vkDestroyInstance(this->vkInstance, nullptr);
	SDL_Vulkan_UnloadLibrary();
}