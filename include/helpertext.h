#pragma once

#include <windows.h>
#include <GL/GLU.h>

#include "../../glm-master/glm/gtc/matrix_transform.hpp"

#include "SceneObject.hpp"
#include "GameManager.hpp"

using P3 = glm::vec3;
using ColourVec = glm::vec3;


//Types


class HelperText : public SceneObject{
public:
    HelperText(char* string, P3 pos, void* font, ColourVec colour);

    void strokeCharacter();

    void privateInit();
    void privateRender();
    void privateUpdate();

private:

    P3 pos_;
    void *font_;
    std::string string_;
    int stringLength_;
    ColourVec colour_;
};
