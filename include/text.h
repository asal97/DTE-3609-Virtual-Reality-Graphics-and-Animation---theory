#pragma once

#include <windows.h>
//#include <GL/GL.h>
#include <GL/GLU.h>

#include "../../glm-master/glm/gtc/matrix_transform.hpp"

#include "SceneObject.hpp"
#include "GameManager.hpp"

using P3 = glm::vec3;
using ColourVec = glm::vec3;


//Types
int const STROKECHAR = 0;

enum Textstate{
    Tnormal,
    Tcollided
};
class Text : public SceneObject{
public:
    Text(char* string, P3 pos, void* font, ColourVec colour);

    void strokeCharacter();

    void privateInit();
    void privateRender();
    void privateUpdate();
    int state_ = Textstate::Tnormal;


private:
    int score = 0;
    P3 pos_;
    void *font_;
    std::string string_;
    int stringLength_;
    ColourVec colour_;


};
