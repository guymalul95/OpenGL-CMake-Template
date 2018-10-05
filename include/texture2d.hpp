#pragma once
#include "opengl.h"
#include <assert.h>

class Texture2D
{
private:
  GLuint m_textureId;

  Texture2D(const GLuint textureId) : m_textureId(textureId) {}

public:
  ~Texture2D()
  {
    glDeleteTextures(1, &m_textureId);
  }

  static inline Texture2D *create()
  {
    GLuint textureId;
    glGenTextures(1, &textureId);

    assert(textureId > 0);

    Texture2D *obj = new Texture2D(textureId);
    return obj;
  }

  inline void activate(int textureIndex = 0) const
  {
    assert(textureIndex >= 0 && textureIndex <= 31);
    glActiveTexture(GL_TEXTURE0 + textureIndex);
  }

  inline void bind() const
  {
    glBindTexture(GL_TEXTURE_2D, m_textureId);
  }

  inline void unbind() const
  {
    glBindTexture(GL_TEXTURE_2D, 0);
  }
};