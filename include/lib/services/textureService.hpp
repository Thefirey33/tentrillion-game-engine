#ifndef TENTRILLIONGAMEENGINE_TEXTURESERVICE_H
#define TENTRILLIONGAMEENGINE_TEXTURESERVICE_H

#include "tentrillionService.hpp"
namespace TenTrillionGameEngine {
class TENTRILLION_GAME_ENGINE_EXPORT TextureService
	: public TenTrillionService {
  public:
	/**
	 * This initializes the TenTrillion Texturing Service.
	 */
	explicit TextureService(TentrillionEngine *tentrillionEngine);
};
} // namespace TenTrillionGameEngine

#endif // !TENTRILLIONGAMEENGINE_TEXTURESERVICE_H