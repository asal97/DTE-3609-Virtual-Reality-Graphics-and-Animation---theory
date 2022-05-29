#pragma once
#include <windows.h>

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"
#include "Shader.h"
#include "Texture.h"

#include <GL/freeglut.h>
#include <GL/glu.h>


#include <string>

#include "../../glm-master/glm/glm.hpp"
#include "SceneObject.hpp"



class Landscape : public SceneObject {
public:
  Landscape(glm::vec3 translate);
  ~Landscape();


protected:
  virtual void privateInit();
  virtual void privateRender();
  virtual void privateUpdate();

private:

  float size = 50.0f;


  unsigned int indices[4] = {
              0,1,2,3,
  };
  float positions[8*4] = {
      -2*size, -53.0f, 2*size,0.0f,1.0f,0.0f, 0.0f, 0.0f,
      2*size, -53.0f, 2*size,0.0f,1.0f,0.0f,  1.0f, 0.0f,
      2*size, -53.0f, -2*size,0.0f,1.0f,0.0f,  1.0f, 1.0f,
      -2*size, -53.0f, -2*size, 0.0f,1.0f,0.0f, 0.0f, 1.0f,
   };

  std::vector<glm::vec3>
      vertexArray_;



  VertexArray va;
  VertexBuffer vb = VertexBuffer(positions, 8*4 * sizeof(float));
  VertexBufferLayout layout;
  IndexBuffer ib = IndexBuffer(indices, 4);
  Shader shader;
  Texture texture = Texture("D:/UIT/VG-3609/start_code/assets/road.png");
  Texture texture1 = Texture("D:/UIT/VG-3609/start_code/assets/Tile.jpg");
  unsigned int texSlot = 0;


};
