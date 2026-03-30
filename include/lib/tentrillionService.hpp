#ifndef TENTRILLIONGAMEENGINE_TENTRILLIONSERVICE_H
#define TENTRILLIONGAMEENGINE_TENTRILLIONSERVICE_H

#include "tentrillion_export.h"
#include <string>

namespace TenTrillionGameEngine {
class TentrillionEngine;

/**
	The base class for the TenTrillion's Services.
*/
class TENTRILLION_GAME_ENGINE_EXPORT TenTrillionService {
  protected:
	TentrillionEngine *engine;
	std::string serviceName;

  public:
	virtual ~TenTrillionService() = default;
	explicit TenTrillionService(
		const std::string &serviceName,
		TenTrillionGameEngine::TentrillionEngine *tentrillionEngine);
	std::string &getServiceName() { return serviceName; }

	virtual void quitService() {}
};
} // namespace TenTrillionGameEngine

#endif // !TENTRILLIONGAMEENGINE_TENTRILLIONSERVICE_H