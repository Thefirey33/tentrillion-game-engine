#include "tentrillionService.hpp"

namespace TenTrillionGameEngine {
TenTrillionService::TenTrillionService(const std::string &serviceName,
									   TentrillionEngine *tentrillionEngine) {
	this->serviceName = serviceName;
	this->engine = tentrillionEngine;
}
}; // namespace TenTrillionGameEngine