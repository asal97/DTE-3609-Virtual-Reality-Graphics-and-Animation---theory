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
#include "../../glm-master/glm/gtc/matrix_transform.hpp"
#include "../../glm-master/glm/glm.hpp"
#include "../../glm-master/glm/gtc/type_ptr.hpp"
#include "SceneObject.hpp"

class Monster : public SceneObject
{
public:
    Monster();
    ~Monster();
    float getSize(){return size;}
    glm::vec3 getPos(){return glm::vec3(matrix_[3].x,matrix_[3].y,matrix_[3].z);}

protected:
  virtual void privateInit();
  virtual void privateRender();
  virtual void privateUpdate();


private:
    float size = 50.0f;
    unsigned int indices[4] = {
                0,1,2,3,
    };
    float positions[5*4] = {
        -size,-size, size, 0.0f, 0.0f,
        size , -size, size, 1.0f, 0.0f,
        size, size, size, 1.0f, 1.0f,
        -size ,size, size, 0.0f, 1.0f,
     };
    VertexArray va;
    VertexBuffer vb = VertexBuffer(positions, 5*4 * sizeof(float));
    VertexBufferLayout layout;
    IndexBuffer ib = IndexBuffer(indices, 4);
    Shader shader;
    Texture texture = Texture("D:/UIT/VG-3609/start_code/assets/monster.png");
    unsigned int texSlot = 0;
};


