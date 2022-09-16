#pragma once
#include <jni.h>
#include <dlfcn.h>
#include <cstdio>
#include <pthread.h>


#define HOOK(symbol, newfunc, trampoline) HookManager::do_hook(HookManager::getPointerFromSymbol(dlopen(("libcocos2dcpp.so") != "" ? ("libcocos2dcpp.so") : NULL, RTLD_LAZY), symbol), (void*)newfunc, (void**)&trampoline);

class HookManager {
	public:
		
	static void do_hook(void* origin, void * newfunc, void* trampoline,bool hookzz = false);
	
	static void *getPointerFromSymbol(void *handle, const char *symbol) {	
		return reinterpret_cast<void *>(dlsym(handle, symbol));
	}
		
};
