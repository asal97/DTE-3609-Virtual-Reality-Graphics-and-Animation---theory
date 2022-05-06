#pragma once

#include <windows.h>
//#include <GL/gl.h>
#include <GL/glu.h>

#include "../../glm-master/glm/gtc/matrix_transform.hpp"

#include "SceneObject.hpp"
#include "GameManager.hpp"
#include "Camera.hpp"

#include <string>
#include <vector>

using P3         = glm::vec3;
using V3         = glm::vec3;
using String     = std::string;



typedef struct						// Create A Structure For Particle
{
    bool	active;					// Active (Yes/No)
    float	life;					// Particle Life
    float	fade;					// Fade Speed
    float	x;						// X Position
    float	y;						// Y Position
    float	z;						// Z Position
    float	xi;						// X Direction
    float	yi;						// Y Direction
    float	zi;						// Z Direction
    float	xg;						// X Gravity
    float	yg;						// Y Gravity
    float	zg;						// Z Gravity
}
particles;							// Particles Structure


class Snow : public SceneObject {
public:

  Snow();
  void privateInit();
  void privateRender();
  void privateUpdate();
  void texture();
  void particleInit(GLuint loop);

protected:
private:

  #define	MAX_PARTICLES	300	// Number Of Particles To Create
  particles particle[MAX_PARTICLES];
  GLuint texName_;
  GLuint loop;						// Loop Variable


   P3 pos_ = {0.0f, 30.0f, -40.0f};
   V3 fall_ = {0.0f, -2.0f, 0.0f};
   V3 slowdown = {1000.0f, 20000.0f, 1000.0f}; // Slow Down Particles. On The Axis By Speed
   float size = 0.5f;
   float life = 5.0f;



};
