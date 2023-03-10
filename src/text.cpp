#include "../include/SceneObject.hpp"
#include "../include/GameManager.hpp"
#include "../include/Text.h"



Text::Text(char* string, P3 pos, void* font, ColourVec colour)
    : string_(string), pos_(pos), font_(font), colour_(colour) {
}


void Text::strokeCharacter(){

    //drawing the text in a fixed position in the left most corner of window
    glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();

        matrix_ = glm::scale(glm::mat4(1.0f),glm::vec3(1.0f,1.0f,5.0f));
        //starting from left most corner
        glRasterPos3f(-0.9f, -0.9f, 0.0f);

        glLineWidth(100.0f);

        for (char& c : string_) {
            glutBitmapCharacter(font_, c);
        }

        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
        glPopMatrix();

        glLineWidth(1.0f);


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
    //as long as the game is running keep adding the score
    if (state_ == Textstate::Tnormal){
        score +=1;
        string_ = "Score : "+ std::to_string(score) + "               " + "Level : " + std::to_string(((score/300)+1)) + "               Health : " + std::to_string(health)+ "               Highscore : " + std::to_string(highscore);
    }
}
