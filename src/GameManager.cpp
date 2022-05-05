#include "../include/GameManager.hpp"
#include <iostream>
GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

void GameManager::privateInit()
{
  // Set default OpenGL states
   glEnable(GL_CULL_FACE);

   //Adding fog in game application

//   glEnable(GL_FOG);
//   GLfloat color[] = {0.5f, 0.5f, 0.5f, 1.0f};
//   glFogfv(GL_FOG_COLOR, color);
//   glFogf(GL_FOG_DENSITY, 0.001f);
//   glFogi(GL_FOG_MODE, GL_EXP);



   glEnable(GL_DEPTH_TEST);


   glEnable(GL_NORMALIZE);

   glShadeModel(GL_SMOOTH);


  // Adding the camera to the scene
  cam_.reset(new Camera());
  snow_.reset(new Snow());
     this->addSubObject(snow_);



  ls_.reset(new Landscape());
  this->addSubObject(ls_);

  character_.reset(new Character());
  this->addSubObject(character_);

    text_.reset(new Text(
                    "Hi", {100.0f,100.0f, 50.0f}, GLUT_STROKE_ROMAN, {1.0f, 1.0f, 1.0f} ));
    this->addSubObject(text_);

    minimap_.reset(new Minimap());
    this->addSubObject(minimap_);


}

void GameManager::privateRender()
{
  // Nothing to render
}

void GameManager::privateUpdate()
{
  // Instead of adding alle objects in the scene as subobject to the camera they are added as subobjects
  // to the game manager. Therefore, we set the game manager matrix equal to the camera matrix. 
  this->matrix_ = cam_->getMatrix();

}

std::shared_ptr<Camera> GameManager::getCam()
{
  return cam_;
}

std::shared_ptr<Character> GameManager::getCharacter()
{
  return character_;
}
