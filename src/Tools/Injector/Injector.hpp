#include <iostream>
#include <Windows.h>
#include <string>
#include <thread>
#include <libloaderapi.h>

class Injector
{
    private:
        DWORD mProcessId;
        char mDllPath[MAX_PATH];
        const char* mDllName;
        const char* mTargetWindowTitle;
    public:
        Injector(DWORD processId, const char* dllPath, const char* dllName, const char* targetWindowTitle);
        ~Injector();
        
        bool Inject();
};