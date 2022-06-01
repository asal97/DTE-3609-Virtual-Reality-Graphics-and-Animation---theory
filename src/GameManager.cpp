#include "../include/GameManager.hpp"
#include <iostream>
#include <fstream>
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



  ls_.reset(new Landscape(glm::vec3(-200.0f* cos(glm::radians(20.0f)),-200*sin(glm::radians(20.0f)),0.0f)));
   this->addSubObject(ls_);
  ls_.reset(new Landscape(glm::vec3(0.0f,0.0f,0.0f)));
  this->addSubObject(ls_);
  ls_.reset(new Landscape(glm::vec3(200.0f * cos(glm::radians(20.0f)),200*sin(glm::radians(20.0f)),0.0f)));
   this->addSubObject(ls_);
  ls_.reset(new Landscape(glm::vec3(2 * 200.0f * cos(glm::radians(20.0f)),2 * 200*sin(glm::radians(20.0f)),0.0f)));
  this->addSubObject(ls_);
  ls_.reset(new Landscape(glm::vec3(3 * 200.0f * cos(glm::radians(20.0f)),3 * 200*sin(glm::radians(20.0f)),0.0f)));
  this->addSubObject(ls_);
  ls_.reset(new Landscape(glm::vec3(4 * 200.0f * cos(glm::radians(20.0f)),4 * 200*sin(glm::radians(20.0f)),0.0f)));
  this->addSubObject(ls_);



  character_.reset(new Character());
  this->addSubObject(character_);

    text_.reset(new Text(
                    "Score", {100.0f,100.0f, 50.0f}, GLUT_BITMAP_TIMES_ROMAN_24, {1.0f, 1.0f, 1.0f} ));
    this->addSubObject(text_);



    std::ifstream infile;
    infile.open("Highscore.dat");
    int data;
    infile >> data;
    text_->highscore = (int)data;

    minimap_.reset(new Minimap());
    this->addSubObject(minimap_);

    skybox_.reset(new Skybox());
    this->addSubObject(skybox_);



    monster_.reset(new Monster());
    this->addSubObject(monster_);


    billboard_.reset(new Billboard());
    this->addSubObject(billboard_);

    snow_.reset(new Snow());
       this->addSubObject(snow_);

    helptext_.reset(new HelperText(
                    "Press J for jump", {100.0f,100.0f, 50.0f}, GLUT_BITMAP_TIMES_ROMAN_24, {0.0f, 0.0f, 0.0f} ));
    this->addSubObject(helptext_);

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


    bool colX = (charPos.x - charSize) <= (monsterPos.x + monsterSize) && (charPos.x + charSize) >= (monsterPos.x - monsterSize);
    bool colY = (charPos.y - charSize) <= (monsterPos.y + monsterSize) && (charPos.y + charSize) >= (monsterPos.y - monsterSize);
    bool colZ = (charPos.z - charSize) <= (monsterPos.z + monsterSize) && (charPos.z + charSize) >= (monsterPos.z - monsterSize);

    if(colX && colY &&  colZ){
        if(character_->colState_ != state::collided){
            character_->colState_ = state::collided;
            if(text_->health != 0){
                text_->health -= 1;
            }
            else
            {
                text_->state_ = Textstate::Tcollided;
                if(text_->score > text_->highscore){
                    text_->highscore = text_->score;
                    std::ofstream outfile;
                    outfile.open("Highscore.dat",std::ios::trunc);
                    outfile << text_->score;
                }
                billboard_->draw = true;
            }
            std::cout<<character_->colState_<<std::endl;
        }
        return;
    }
    character_->colState_ = state::notColided;


}

std::shared_ptr<Camera> GameManager::getCam()
{
  return cam_;
}

std::shared_ptr<Character> GameManager::getCharacter()
{
  return character_;
}
