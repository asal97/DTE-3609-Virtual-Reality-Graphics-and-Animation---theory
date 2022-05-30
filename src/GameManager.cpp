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
//   glEnable(GL_CULL_FACE);

   //Adding fog in game application

//   glEnable(GL_FOG);
//   GLfloat color[] = {0.5f, 0.5f, 0.5f, 1.0f};
//   glFogfv(GL_FOG_COLOR, color);
//   glFogf(GL_FOG_DENSITY, 0.01f);
//   glFogi(GL_FOG_MODE, GL_EXP);





   glEnable(GL_NORMALIZE);

   glShadeModel(GL_SMOOTH);


  // Adding the camera to the scene
  cam_.reset(new Camera());
//  snow_.reset(new Snow());
//     this->addSubObject(snow_);


  ls_.reset(new Landscape(glm::vec3(-200.0f* cos(glm::radians(15.0f)),-200*sin(glm::radians(15.0f)),0.0f)));
   this->addSubObject(ls_);
  ls_.reset(new Landscape(glm::vec3(0.0f,0.0f,0.0f)));
  this->addSubObject(ls_);
  ls_.reset(new Landscape(glm::vec3(200.0f * cos(glm::radians(15.0f)),200*sin(glm::radians(15.0f)),0.0f)));
   this->addSubObject(ls_);
  ls_.reset(new Landscape(glm::vec3(2 * 200.0f * cos(glm::radians(15.0f)),2 * 200*sin(glm::radians(15.0f)),0.0f)));
  this->addSubObject(ls_);
  ls_.reset(new Landscape(glm::vec3(3 * 200.0f * cos(glm::radians(15.0f)),3 * 200*sin(glm::radians(15.0f)),0.0f)));
  this->addSubObject(ls_);
  ls_.reset(new Landscape(glm::vec3(4 * 200.0f * cos(glm::radians(15.0f)),4 * 200*sin(glm::radians(15.0f)),0.0f)));
  this->addSubObject(ls_);



  character_.reset(new Character());
  this->addSubObject(character_);

    text_.reset(new Text(
                    "Score", {100.0f,100.0f, 50.0f}, GLUT_BITMAP_TIMES_ROMAN_24, {0.0f, 1.0f, 0.0f} ));
    this->addSubObject(text_);

//    minimap_.reset(new Minimap());
//    this->addSubObject(minimap_);

    skybox_.reset(new Skybox());
    this->addSubObject(skybox_);



    monster_.reset(new Monster());
    this->addSubObject(monster_);


    billboard_.reset(new Billboard());
    this->addSubObject(billboard_);

}

void GameManager::privateRender()
{
  // Nothing to render
}

void GameManager::privateUpdate()
{
  CollisionDetection();
  // Instead of adding alle objects in the scene as subobject to the camera they are added as subobjects
  // to the game manager. Therefore, we set the game manager matrix equal to the camera matrix. 
  this->matrix_ = cam_->getMatrix();

}
void GameManager::CollisionDetection(){
    glm::vec3 charPos = character_->getPos();
    float charSize = character_->getSize();
    glm::vec3 monsterPos = monster_->getPos();
    float monsterSize = monster_->getSize();

//    std::cout << "monster x "<<monsterPos.x <<" monster y " << monsterPos.y<<std::endl;
//    std::cout << "char x "<<charPos.x <<" char y " << charPos.y<<std::endl;

    bool colX = (charPos.x - charSize) <= (monsterPos.x + monsterSize) && (charPos.x + charSize) >= (monsterPos.x - monsterSize);
    bool colY = (charPos.y - charSize) <= (monsterPos.y + monsterSize) && (charPos.y + charSize) >= (monsterPos.y - monsterSize);
    bool colZ = (charPos.z - charSize) <= (monsterPos.z + monsterSize) && (charPos.z + charSize) >= (monsterPos.z - monsterSize);

    if(colX && colY &&  colZ){
        if(character_->state_ != state::collided){
            character_->state_ = state::collided;
            text_->state_ = Textstate::Tcollided;
            ls_->state_ = Lstate::Lcollided;
            billboard_->draw = true;
            std::cout<<character_->state_<<std::endl;
        }
        return;
    }
}

std::shared_ptr<Camera> GameManager::getCam()
{
  return cam_;
}

std::shared_ptr<Character> GameManager::getCharacter()
{
  return character_;
}
