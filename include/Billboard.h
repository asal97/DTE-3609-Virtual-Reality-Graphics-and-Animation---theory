#pragma once
#include <windows.h>

#include <GL/freeglut.h>
#include <GL/glu.h>


#include <string>

#include "../../glm-master/glm/glm.hpp"
#include "SceneObject.hpp"


class Billboard : public SceneObject
{
public:
    Billboard();
    ~Billboard();
    bool draw = false;

protected:
  void privateInit();
 void privateRender();
  void privateUpdate();
  void DrawTexture();

private:
      float size_ = 50.0f;
    unsigned int texture1;
    std::vector<glm::vec3> billboardArray_;
    std::vector<glm::vec3> billboardNormal_;
    std::vector<glm::vec2> billboardTexture_;
};



