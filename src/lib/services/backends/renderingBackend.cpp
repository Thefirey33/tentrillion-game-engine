#include "backends/renderingBackend.hpp"

TenTrillionGameEngine::RenderingBackendManager::RenderingBackendManager(
	RenderingService *renderingService, TentrillionEngine *engine)
	: TenTrillionService("RenderingBackendManager", engine),
	  renderingService(renderingService) {}

std::vector<TenTrillionGameEngine::GpuInformation>
TenTrillionGameEngine::RenderingBackendManager::getAvailableGpuInformation() {
	return {};
}