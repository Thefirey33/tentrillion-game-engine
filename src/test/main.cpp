#include "tentrillion.hpp"
#include <cstdio>

int main(int argc, const char **argv) {
	auto *tentrillionEngine = new TenTrillionGameEngine::TentrillionEngine();
	tentrillionEngine->init(800, 600, "Test");
	tentrillionEngine->quit();
	return 0;
}