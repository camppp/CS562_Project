// HookManager.h
#pragma once

#include <vector>
#include <memory>

class Listener;

class HookManager
{
public:
    void AddPlayerRunCommandListener(std::shared_ptr<Listener> listener);
    void RemovePlayerRunCommandListener(std::shared_ptr<Listener> listener);
    void AddUserMessageListener(std::shared_ptr<Listener> listener);
    void RemoveUserMessageListener(std::shared_ptr<Listener> listener);
    void UnloadAllListeners();

private:
    std::vector<std::shared_ptr<Listener>> playerRunCommandListeners;
    std::vector<std::shared_ptr<Listener>> userMessageListeners;
};

// Listener.h
#pragma once

#include <memory>

class Listener
{
public:
    virtual ~Listener() = default;
};

// HookManager.cpp
#include "HookManager.h"

void HookManager::AddPlayerRunCommandListener(std::shared_ptr<Listener> listener)
{
    playerRunCommandListeners.push_back(listener);
}

void HookManager::RemovePlayerRunCommandListener(std::shared_ptr<Listener> listener)
{
    playerRunCommandListeners.erase(std::remove(playerRunCommandListeners.begin(), playerRunCommandListeners.end(), listener), playerRunCommandListeners.end());
}

void HookManager::AddUserMessageListener(std::shared_ptr<Listener> listener)
{
    userMessageListeners.push_back(listener);
}

void HookManager::RemoveUserMessageListener(std::shared_ptr<Listener> listener)
{
    userMessageListeners.erase(std::remove(userMessageListeners.begin(), userMessageListeners.end(), listener), userMessageListeners.end());
}

void HookManager::UnloadAllListeners()
{
    playerRunCommandListeners.clear();
    userMessageListeners.clear();
}
