

#ifndef TEN_TRILLION_RENDERINGBACKEND_HPP
#define TEN_TRILLION_RENDERINGBACKEND_HPP
#include "SDL3/SDL_surface.h"
#include "tentrillionService.hpp"

#include <cstdint>
#include <vector>

namespace TenTrillionGameEngine {
class RenderingService;

// This is a struct that contains GPU information for the TenTrillion engine to
// use.
struct GpuInformation {
	/**
	 * This is the name of the Graphics Adapter.
	 */
	std::string gpuName;
	/**
	 * This is the version of the current GPU driver.
	 */
	std::string driverVersion;
};

class TENTRILLION_GAME_ENGINE_EXPORT RenderingBackendManager
	: public TenTrillionService {
  protected:
	/**
	 * The reference to the rendering service.
	 */
	RenderingService *renderingService{};

	/**
	 * The surface that the renderer is referencing.
	 */
	SDL_Surface *currentRenderingSurface{};

  public:
	/**
	 * This is the rendering backend manager initializer.
	 * @param renderingService The rendering service pointer to reference.
	 * @param engine The engine pointer to reference.
	 */
	RenderingBackendManager(RenderingService *renderingService,
							TentrillionEngine *engine);

	/**
	 * This retrieves the current GPU information from the backend driver.
	 * @return The available GPU information.
	 */
	virtual std::vector<GpuInformation> getAvailableGpuInformation();
};
}; // namespace TenTrillionGameEngine

#endif // TEN_TRILLION_RENDERINGBACKEND_HPP
