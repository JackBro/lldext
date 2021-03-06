#include "DbgExts.h"

void CheckHResult(HRESULT const result) {
    if (result != S_OK) {
        throw Exception(result);
    }
}

HRESULT CALLBACK help(IDebugClient* pDebugClient, PCSTR args) {
    IDebugControl* pDebugControl;
    UNREFERENCED_PARAMETER(args);
    if (SUCCEEDED(pDebugClient->QueryInterface(__uuidof(IDebugControl), (void **)&pDebugControl))) {
        pDebugControl->Output(DEBUG_OUTPUT_NORMAL, "==============================================================\n");
        pDebugControl->Output(DEBUG_OUTPUT_NORMAL, "  LLD v1.1 - Copyright 2016 Sebastian Solnica\n");
        pDebugControl->Output(DEBUG_OUTPUT_NORMAL, "==============================================================\n\n");
        pDebugControl->Output(DEBUG_OUTPUT_NORMAL, "  !help                - shows this help view\n\n");
        pDebugControl->Output(DEBUG_OUTPUT_NORMAL, "  !injectdll <path>    - injects DLL into the debugee\n\n");
        pDebugControl->Output(DEBUG_OUTPUT_NORMAL, "==============================================================\n\n");

        pDebugControl->Release();
    }
    return S_OK;
}
