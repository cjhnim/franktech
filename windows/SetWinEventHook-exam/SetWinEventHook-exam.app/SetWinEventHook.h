#pragma once
#include <Windows.h>
#include <Oleacc.h>

HWINEVENTHOOK install_event_hook();
void uninstall_event_hook(HWINEVENTHOOK hook);
