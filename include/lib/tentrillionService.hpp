#ifndef TENTRILLIONGAMEENGINE_TENTRILLIONSERVICE_H
#define TENTRILLIONGAMEENGINE_TENTRILLIONSERVICE_H

#include "tentrillion_export.h"
#include <string>

namespace TenTrillionGameEngine {

/**
	The base class for the TenTrillion's Services.
*/
class TENTRILLION_GAME_ENGINE_EXPORT TenTrillionService {
  private:
	std::string serviceName;

  public:
	TenTrillionService(const std::string &serviceName);
	std::string &getServiceName();
};
} // namespace TenTrillionGameEngine

#endif // !TENTRILLIONGAMEENGINE_TENTRILLIONSERVICE_H