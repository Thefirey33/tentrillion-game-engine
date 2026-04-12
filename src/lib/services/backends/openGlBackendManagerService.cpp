#include "backends/openGlBackendManagerService.hpp"

TenTrillionGameEngine::OpenGlBackendManagerService::OpenGlBackendManagerService(
	RenderingService *renderingService, TentrillionEngine *tenTrillionEngine)
	: RenderingBackendManager(renderingService, tenTrillionEngine) {}