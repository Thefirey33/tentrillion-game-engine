
#ifndef TEN_TRILLION_VULKANBACKENDMANAGERSERVICE_H
#define TEN_TRILLION_VULKANBACKENDMANAGERSERVICE_H
#include "tentrillionService.hpp"

namespace TenTrillionGameEngine {
class RenderingService;
class VulkanBackendManagerService
	: public TenTrillionGameEngine::TenTrillionService {
  private:
	unsigned int vkExtensionCount = 0;
	RenderingService *renderingService;

  public:
	explicit VulkanBackendManagerService(RenderingService *renderingService,
										 TentrillionEngine *engine);
};
}; // namespace TenTrillionGameEngine

#endif // TEN_TRILLION_VULKANBACKENDMANAGERSERVICE_H
