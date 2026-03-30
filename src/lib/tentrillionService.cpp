#include "tentrillionService.hpp"

namespace TenTrillionGameEngine {
TenTrillionService::TenTrillionService(const std::string &serviceName,
									   TentrillionEngine *engine) {
	this->serviceName = serviceName;
	this->engine = engine;
}
}; // namespace TenTrillionGameEngine