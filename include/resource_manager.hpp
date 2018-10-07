#pragma once
#include "macros.h"
#include "opengl.h"
#include "texture2d.hpp"
#include "shader.hpp"
#include <string>
#include <stb_image.h>

class ResourceManager
{
private:
  NONCOPYABLE(ResourceManager);

  const std::string m_assetBasePath;

  inline std::string getAbsolutePath(const std::string assetRelativePath) const 
  {
    return m_assetBasePath + assetRelativePath;
  }
public:
  ResourceManager(std::string assetBasePath)  : m_assetBasePath(assetBasePath) {}
  ~ResourceManager() {}

  int init();

  Texture2D* loadTexture2D(const std::string textureAsset) const;

  Shader* loadShader(const std::string vertexShader,const std::string fragmentShader) const;
};