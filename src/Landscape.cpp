#include "../include/Landscape.hpp"
#include "../../glm-master/glm/gtc/matrix_transform.hpp"
#include "../../glm-master/glm/glm.hpp"
#include "../../glm-master/glm/gtc/type_ptr.hpp"
#include "../include/Camera.hpp"
//#include"../include/Basic.shader"

Landscape::Landscape(glm::vec3 translate)
{
   //rotating to make hill
    matrix_ = glm::translate(glm::mat4(1.0f),translate) * glm::rotate(matrix_,glm::radians(20.0f), glm::vec3(0.0f, 0.0f, 1.0f));

    projectionMatrix_ = glm::perspective(glm::radians(60.0f), 900.0f / 700.0f, 1.0f, 30000.0f);

}

Landscape::~Landscape()
{
}

void Landscape::privateInit()
{
    // below we initialize our shader, vertex array and vertex buffer to draw the landscape
    //with shader


    VertexBufferLayout layout;
    // position layout
    layout.Push<float>(3);
    // normal layout
    layout.Push<float>(3);
    // texture coordinate layout

    layout.Push<float>(2);
    va.AddBuffer(vb,layout);
    shader.initShader("D:/UIT/VG-3609/start_code/include/Landscape.shader");
    shader.Bind();


   //sending in two textures to the fragment shader
    texture.Bind(texSlot);
    shader.SetUniform1i("u_Texture", texSlot);
    texture1.Bind(texSlot + 1);
    shader.SetUniform1i("u_Texture2", texSlot + 1);
    //setting uniform for diffuse map
    shader.SetUniform1i("material_diffuse",0);




    texture.Unbind();
    texture1.Unbind();
    va.Unbind();
    vb.Unbind();
    ib.Unbind();
    shader.Unbind();

}

void Landscape::privateRender()
{

    //drawing the landscape with shaders

       shader.Bind();
       texture.Bind(texSlot);
       texture1.Bind(texSlot + 1);

       // sending in model, view and projection matrix and the light position and camera position
       //for landscape

       shader.SetUniformMat4f("model",matrix_);
       shader.SetUniformMat4f("view",viewMatrix_);
       shader.SetUniformMat4f("projection",projectionMatrix_);
       shader.SetUniform4f("lightPos",1.0f,1.0f,2.0f,1.0);
       shader.SetUniform3f("camera",viewMatrix_[3].x,viewMatrix_[3].y,viewMatrix_[3].z);


       vb.Bind();
       va.Bind();
       ib.Bind();
       //draw as quads
       GLCall(glDrawElements(GL_QUADS, ib.GetCount(), GL_UNSIGNED_INT, nullptr));




    shader.Unbind();
    va.Unbind();
    ib.Unbind();
    vb.Unbind();
    texture.Unbind();
    texture1.Unbind();

  // Render the Landscape
}

void Landscape::privateUpdate()
{
// check if it reaches a certain point remove and translate it to make an endless road effect
 if(matrix_[3].x<-400){
     auto translate = glm::translate(glm::mat4(1.0f),glm::vec3(1200.0f,0.0f,0.0f));
     matrix_ = matrix_ * translate;
 }

 // keeps moving
 auto translate = glm::translate(glm::mat4(1.0f),glm::vec3(-1.0f,0.0f,0.0f)) ;
 matrix_ = matrix_ * translate;
}

