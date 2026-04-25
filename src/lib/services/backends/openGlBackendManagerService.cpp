#include "backends/openGlBackendManagerService.hpp"

#include "SDL3/SDL_log.h"
#include "SDL3/SDL_opengl.h"
#include "SDL3/SDL_video.h"
#include "renderingService.hpp"

#include <algorithm>

TenTrillionGameEngine::OpenGlBackendManagerService::OpenGlBackendManagerService(
	RenderingService *renderingService, TentrillionEngine *tenTrillionEngine)
	: RenderingBackendManager(renderingService, tenTrillionEngine) {
	this->openGlContext =
		SDL_GL_CreateContext(renderingService->getWindowInstance());

	const std::vector<GpuInformation> &availableGpuInformation =
		this->OpenGlBackendManagerService::getAvailableGpuInformation();

	std::for_each(
		availableGpuInformation.begin(), availableGpuInformation.end(),
		[&](const GpuInformation &gpuInfo) {
			SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
						"OpenGL GPU: %s, VERSION %s", gpuInfo.gpuName.c_str(),
						gpuInfo.driverVersion.c_str());
		});
}
