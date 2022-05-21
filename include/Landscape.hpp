#pragma once
#include <windows.h>

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"
#include "Shader.h"
#include "Texture.h"

#include <GL/freeglut.h>
//#include <GL/gl.h>
#include <GL/glu.h>


#include <string>

#include "../../glm-master/glm/glm.hpp"
#include "SceneObject.hpp"

class Landscape : public SceneObject {
public:
  Landscape();
  ~Landscape();


protected:
  virtual void privateInit();
  virtual void privateRender();
  virtual void privateUpdate();

private:
  unsigned int indices[12] = {
              0,1,2,3,
              4,5,6,7,
              8,9,10,11
  };

  float size = 50.0f;

//  float positions[3*4*3] = {
//      -2*size,-53.0f,2*size,
//      2*size,-53.0f,2*size,
//      2*size,-53.0f,-2*size,
//      -2*size,-53.0f,-2*size,

//      -6*size,-53.0f,2*size,
//     -2*size,-53.0f,2*size,
//      -2*size,-53.0f,-2*size,
//      -6*size,-53.0f,-2*size,

//      2*size,-53.0f,2*size,
//      6*size,-53.0f,2*size,
//      6*size,-53.0f,-2*size,
//      2*size,-53.0f,-2*size,
//       };

  float positions[5*4*3] = {
      -2*size, -53.0f, 2*size, 0.0f, 0.0f,
      2*size, -53.0f, 2*size, 1.0f, 0.0f,
      2*size, -53.0f, -2*size, 1.0f, 1.0f,
      -2*size, -53.0f, -2*size, 0.0f, 1.0f,

      -6*size, -53.0f, 2*size, 0.0f, 0.0f,
     -2*size, -53.0f, 2*size, 1.0f, 0.0f,
      -2*size, -53.0f, -2*size, 1.0f, 1.0f,
      -6*size, -53.0f, -2*size, 0.0f, 1.0f,

      2*size, -53.0f, 2*size, 0.0f, 0.0f,
      6*size, -53.0f, 2*size, 1.0f, 0.0f,
      6*size, -53.0f, -2*size, 1.0f, 1.0f,
      2*size, -53.0f, -2*size, 0.0f, 1.0f,
       };
  std::vector<glm::vec3>
      vertexArray_; // Maybe two-dim vector and several arrays
                    // normal array.
                    // texture coord array




  VertexArray va;
  VertexBuffer vb = VertexBuffer(positions, 5* 4* 3 * sizeof(float));;
  VertexBufferLayout layout;
  IndexBuffer ib = IndexBuffer(indices, 12);
  Shader shader;
  Texture texture = Texture("D:/UIT/VG-3609/start_code/assets/road.png");
  unsigned int texSlot = 0;


};
