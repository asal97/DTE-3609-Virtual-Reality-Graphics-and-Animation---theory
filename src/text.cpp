#include "../include/SceneObject.hpp"
#include "../include/GameManager.hpp"
#include "../include/Text.h"

Text::Text(char* string, P3 pos, void* font, ColourVec colour)
    : string_(string), pos_(pos), font_(font), colour_(colour) {}


void Text::strokeCharacter(){
    glPushMatrix();
    glTranslatef(pos_.x, pos_.y, pos_.z);

    glLineWidth(5.0f);

    for(char *c = string_ ; *c != '\0' ; c++){
        glutStrokeCharacter(font_, *c);
    }

    glLineWidth(1.0f);
    glPopMatrix();

}

void Text::privateInit(){

}

void Text::privateRender(){
    glEnable(GL_COLOR_MATERIAL);

    glColor3f(colour_.x, colour_.y, colour_.z);

      strokeCharacter();

    glDisable(GL_COLOR_MATERIAL);
}
void Text::privateUpdate(){

}
