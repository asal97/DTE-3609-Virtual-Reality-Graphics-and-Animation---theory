#include "../include/Landscape.hpp"
#include "../../glm-master/glm/gtc/matrix_transform.hpp"
#include "../../glm-master/glm/glm.hpp"
#include "../../glm-master/glm/gtc/type_ptr.hpp"
//#include"../include/Basic.shader"

Landscape::Landscape()
{
}

Landscape::~Landscape()
{
}

//void Landscape::texture(){
//    //Init texture
//    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

//    glGenTextures(1, &texName_);

//    glBindTexture(GL_TEXTURE_2D, texName_);

//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


//    //width of texture, height of texture and number of colour channels
//    int widthTex, heightTex, nrChannels;
//    unsigned char *data = stbi_load("D:/UIT/VG-3609/start_code/assets/Snowflake2.png",
//                                        &widthTex, &heightTex, &nrChannels, 0);
//    if(data){
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthTex, heightTex, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//    }
//    else{
//        std::cout << "Failed to load landscape texture" << std::endl;
//    }


//    glBindTexture(GL_TEXTURE_2D, 0);
//    stbi_image_free(data);

//}

void Landscape::privateInit()
{
  // Create vertex arrays

//    float size = 50.0f;
//    vertexArray_.push_back(glm::vec3(-2*size,-53.0f,2*size));
//    vertexArray_.push_back(glm::vec3(2*size,-53.0f,2*size));
//    vertexArray_.push_back(glm::vec3(2*size,-53.0f,-2*size));
//    vertexArray_.push_back(glm::vec3(-2*size,-53.0f,-2*size));

//    vertexArray_.push_back(glm::vec3(-6*size,-53.0f,2*size));
//    vertexArray_.push_back(glm::vec3(-2*size,-53.0f,2*size));
//    vertexArray_.push_back(glm::vec3(-2*size,-53.0f,-2*size));
//    vertexArray_.push_back(glm::vec3(-6*size,-53.0f,-2*size));

//    vertexArray_.push_back(glm::vec3(2*size,-53.0f,2*size));
//    vertexArray_.push_back(glm::vec3(6*size,-53.0f,2*size));
//    vertexArray_.push_back(glm::vec3(6*size,-53.0f,-2*size));
//    vertexArray_.push_back(glm::vec3(2*size,-53.0f,-2*size));




    VertexBufferLayout layout;
    layout.Push<float>(3);
    layout.Push<float>(2);
    va.AddBuffer(vb,layout);
    shader.initShader("D:/UIT/VG-3609/start_code/include/Basic.shader");
    shader.Bind();
    shader.SetUniform4f("u_Color",0.2f,0.3f,0.8f,1.0f);



    texture.Bind(texSlot);
    shader.SetUniform1i("u_Texture", texSlot);
    projectionMatrix_ = glm::perspective(glm::radians(60.0f), 900.0f / 700.0f, 1.0f, 3000.0f);

    texture.Unbind();
    va.Unbind();
    vb.Unbind();
    ib.Unbind();
    shader.Unbind();

}

void Landscape::privateRender()
{


       shader.Bind();
       texture.Bind(texSlot);


       shader.SetUniformMat4f("u_MVP",projectionMatrix_ * viewMatrix_* matrix_);

       vb.Bind();
       va.Bind();
       ib.Bind();
       GLCall(glDrawElements(GL_QUADS, ib.GetCount(), GL_UNSIGNED_INT, nullptr));


//    glEnable(GL_POLYGON_OFFSET_FILL);
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//    glPolygonOffset(1.0f, 1.0f);


//    glEnable(GL_COLOR_MATERIAL);
//    glColor3f( 0.0f, 1.0f, 0.0f);
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glVertexPointer(3,GL_FLOAT,0,vertexArray_.data());
//    glDrawArrays(GL_QUADS,0,4);
//    glDisableClientState(GL_VERTEX_ARRAY);


//    glColor3f( 0.0f, 1.0f, 0.0f);
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glVertexPointer(3,GL_FLOAT,0,vertexArray_.data());
//    glDrawArrays(GL_QUADS,4,4);
//    glDisableClientState(GL_VERTEX_ARRAY);



//glColor3f( 0.0f, 1.0f, 0.0f);

//    glEnableClientState(GL_VERTEX_ARRAY);
//    glVertexPointer(3,GL_FLOAT,0,vertexArray_.data());
//    glDrawArrays(GL_QUADS,8,4);
//    glDisableClientState(GL_VERTEX_ARRAY);

//    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

//    glEnable(GL_COLOR_MATERIAL);
//    glColor3f( 1.0f, 1.0f, 1.0f);
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glVertexPointer(3,GL_FLOAT,0,vertexArray_.data());
//    glDrawArrays(GL_QUADS,0,4);
//    glDisableClientState(GL_VERTEX_ARRAY);


//    glColor3f( 1.0f, 1.0f, 1.0f);
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glVertexPointer(3,GL_FLOAT,0,vertexArray_.data());
//    glDrawArrays(GL_QUADS,4,4);
//    glDisableClientState(GL_VERTEX_ARRAY);



//    glColor3f( 1.0f, 1.0f, 1.0f);
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glVertexPointer(3,GL_FLOAT,0,vertexArray_.data());
//    glDrawArrays(GL_QUADS,8,4);
//    glDisableClientState(GL_VERTEX_ARRAY);


    glDisable(GL_COLOR_MATERIAL);
    glDisable(GL_POLYGON_OFFSET_FILL);
    shader.Unbind();
    va.Unbind();
    ib.Unbind();
    vb.Unbind();
    texture.Unbind();

  // Render the Landscape
}

void Landscape::privateUpdate()
{
}

