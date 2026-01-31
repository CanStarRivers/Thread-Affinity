#ifndef CONFIG_LOADER_H
#define CONFIG_LOADER_H

#include <string>
#include <shared_mutex>
#include <yaml-cpp/yaml.h>
#include <sys/inotify.h>
#include <thread>
#include <vector>
#include <functional>

class ConfigLoader {
public:
    ConfigLoader(const std::string& filePath);
    ~ConfigLoader();

    void load();
    void reload();
    void setThreadBindingRules(const std::vector<int>& rules);
    std::vector<int> getThreadBindingRules();

private:
    std::string filePath;
    std::shared_mutex mutex;
    std::vector<int> threadBindingRules;
    int inotifyFd;
    int watchDescriptor;
    std::thread watchThread;
    bool running;

    void watchForFileChanges();
    void notifyChange();
};

#endif // CONFIG_LOADER_H
