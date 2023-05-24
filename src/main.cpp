#include "settings.h"
#include "logger.h"
#include "okx/client.h"

#ifdef _WIN32
#include <Windows.h>
#endif



int main() {
#ifdef _WIN32
    // prevent computer from sleeping
    ::SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED | ES_AWAYMODE_REQUIRED);
#endif

    if (!Settings::instance().load("settings.ini")) {
        LOG(fatal) << "load setting file failed!";
        return -1;
    }

    okx::Client client;
    if (!client.init()) {
        LOG(fatal) << "init client failed!";
        return -1;
    }


    return 0;
}