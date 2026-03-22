#include "tentrillion.hpp"
#include <cstdio>

int main(int argc, const char **argv) {
	TenTrillionGameEngine::TentrillionEngine *tentrillionEngine =
		new TenTrillionGameEngine::TentrillionEngine();
	tentrillionEngine->init();
	tentrillionEngine->quit();
	return 0;
}