#pragma once
#include "macros.h"
#include "resource_manager.hpp"
class Scene
{
private:
  NONCOPYABLE(Scene);
  const ResourceManager &m_resourceManager;

protected:
  const ResourceManager& getResourceManager() const 
  {
    return m_resourceManager;
  }
public:
  Scene(const ResourceManager &resourceManager) : m_resourceManager(resourceManager) {}
  virtual ~Scene() {}

  virtual void init() = 0;
  virtual void draw() = 0;
  virtual void update() = 0;
};