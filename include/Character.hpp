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
#include "SceneObject.hpp"

#include "../../glm-master/glm/gtc/matrix_transform.hpp"
#include "../../glm-master/glm/glm.hpp"
#include "../../glm-master/glm/gtc/type_ptr.hpp"

enum state{
    notColided,
    collided
};
enum Jstate{
    jump,
    notJump
};

class Character : public SceneObject
{
public:
        Character();
        ~Character();
         void moveUpward();
         float getSize(){return size_;}
         glm::vec3 getPos(){return glm::vec3(matrix_[3].x,matrix_[3].y,matrix_[3].z);}
         int colState_ = state::notColided;
         int jumpState_ = Jstate::notJump;

  protected:
    void privateInit();
		void privateRender();
		void privateUpdate();


	private:

        float size_ = 50.0f;
        unsigned int indices[24] = {
            0,1,2,3,
            4,5,6,7,
            8,9,10,11,
            12,13,14,15,
            16,17,18,19,
            20,21,22,23
        };
        float positions[8*6*4] = {
           -size_, -size_,  size_,  -1.0f, -1.0f, 1.0f ,  0.0f, 0.0f,
            size_, -size_,  size_, 1.0f, -1.0f, 1.0f,     1.0f, 0.0f,
            size_,  size_,  size_,  1.0f, 1.0f, 1.0f,     1.0f, 1.0f,
            -size_,  size_,  size_,  -1.0f, 1.0f, 1.0f ,  0.0f, 1.0f,

            -size_, size_,  size_,  -1.0f, 1.0f, 1.0f,    0.0f, 0.0f,
           size_, size_,  size_, 1.0f, 1.0f, 1.0f,        1.0f, 0.0f,
            size_,  size_,  -size_, 1.0f, 1.0f, -1.0f,    1.0f, 1.0f,
            -size_,  size_,  -size_,-1.0f, 1.0f, -1.0f,   0.0f, 1.0f,

            size_, -size_,  size_, 1.0f, -1.0f, 1.0f,     0.0f, 0.0f,
            size_, -size_,  -size_, 1.0f, -1.0f, -1.0f,   1.0f, 0.0f,
            size_,  size_,  -size_,1.0f, 1.0f, -1.0f,     1.0f, 1.0f,
             size_,  size_,  size_, 1.0f, 1.0f, 1.0f,     0.0f, 1.0f,

            -size_, -size_, -size_,-1.0f, -1.0f, -1.0f,     0.0f, 0.0f,
             -size_, -size_,  size_, -1.0f, -1.0f, 1.0f,    1.0f, 0.0f,
             -size_,  size_,  size_, -1.0f, 1.0f, 1.0f,     1.0f, 1.0f,
               -size_,  size_,  -size_, -1.0f, 1.0f, -1.0f, 0.0f, 1.0f,

            size_, -size_,  -size_,1.0f, -1.0f, -1.0f,    0.0f, 0.0f,
            -size_, -size_,  -size_,-1.0f, -1.0f, -1.0f,  1.0f, 0.0f,
             -size_,  size_,  -size_,-1.0f, 1.0f, -1.0f,  1.0f, 1.0f,
             size_,  size_,  -size_,1.0f, 1.0f, -1.0f,    0.0f, 1.0f,

             -size_, -size_,  -size_,-1.0f, -1.0f, -1.0f,  0.0f, 0.0f,
             size_, -size_,  -size_,1.0f, -1.0f, -1.0f,    1.0f, 0.0f,
            size_,  -size_,  size_, 1.0f, -1.0f, 1.0f,     1.0f, 1.0f,
              -size_, -size_,  size_, -1.0f, -1.0f, 1.0f,  0.0f, 1.0f,
             };
        VertexArray va;
        VertexBuffer vb = VertexBuffer(positions, 8* 6* 4 * sizeof(float));;
        VertexBufferLayout layout;
        IndexBuffer ib = IndexBuffer(indices, 24);
        Shader shader;
        Texture texture = Texture("D:/UIT/VG-3609/start_code/assets/Box.jpg");
        unsigned int texSlot = 0;
        float speed_;
        float life_;
        float armor_;

        glm::vec3 gravity_ = glm::vec3(0.0f,-0.06f,0.0f);
        glm::vec3 velocity_ = glm::vec3(0.0f,0.0f,0.0f);
        glm::vec3 position_ = getPos();
        int count =0;
    
};

