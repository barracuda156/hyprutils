#pragma once

#include <string>
#include <vector>

namespace Hyprutils {
    namespace OS {
        class CProcess {
          public:
            /* Creates a process object, doesn't run yet */
            CProcess(const std::string& binary_, const std::vector<std::string>& args_);

            /* Run the process, synchronously, get the stdout and stderr. False on fail */
            bool runSync();

            /* Run the process, asynchronously. This will detach the process from this object (and process) and let it live a happy life. False on fail. */
            bool runAsync();

            // only populated when ran sync
            const std::string& stdOut();
            const std::string& stdErr();

          private:
            std::string              binary, out, err;
            std::vector<std::string> args;
        };
    }
}