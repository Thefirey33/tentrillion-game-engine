#include "tentrillion.hpp"
#include <cstdio>

int main(int argc, const char **argv) {
	auto *tentrillionEngine = new TenTrillionGameEngine::TentrillionEngine();
	tentrillionEngine->initializeInstance(800, 600, "Test");
	tentrillionEngine->exitInstance();
	return 0;
}