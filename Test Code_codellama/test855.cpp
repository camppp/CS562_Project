#include <berryWorkbench.h>
#include <berryWorkbenchPlugin.h>

namespace berry {

class Plugin {
public:
    Plugin(const std::string& name, const std::string& version);
    ~Plugin();

    void Load();
    void Unload();

    void Execute();

private:
    std::string name_;
    std::string version_;
    berryWorkbench* workbench_;
    berryWorkbenchPlugin* plugin_;
};

} // namespace berry
