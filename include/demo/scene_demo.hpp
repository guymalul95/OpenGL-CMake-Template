#pragma once
#include "scene.hpp"

class DemoScene : public Scene
{
public:
  virtual ~DemoScene() {}

  void init() override;
  void loadAssets() override;
  void unloadAssets() override;
  void draw() override;
  void update() override;
};
