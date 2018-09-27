#pragma once

class Scene
{
private:
  Scene(const Scene &) = delete;
  Scene &operator=(const Scene &) = delete;

public:
  Scene() {}
  virtual ~Scene() {}

  virtual void init() = 0;
  virtual void draw() = 0;
  virtual void update() = 0;
};