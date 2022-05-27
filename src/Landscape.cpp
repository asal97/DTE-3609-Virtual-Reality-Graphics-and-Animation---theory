#include "../include/Landscape.hpp"
#include "../../glm-master/glm/gtc/matrix_transform.hpp"
#include "../../glm-master/glm/glm.hpp"
#include "../../glm-master/glm/gtc/type_ptr.hpp"
//#include"../include/Basic.shader"

Landscape::Landscape(glm::vec3 translate)
{
//    auto scale = glm::scale(glm::mat4(1.0f),glm::vec3(1.0f,1.0f,5.0f));
//    matrix_ = scale;
    matrix_ = glm::translate(glm::mat4(1.0f),translate) * glm::rotate(matrix_,glm::radians(15.0f), glm::vec3(0.0f, 0.0f, 1.0f));



}

Landscape::~Landscape()
{
}

void Landscape::privateInit()
{
  // Create vertex arrays



    VertexBufferLayout layout;
    layout.Push<float>(3);
    layout.Push<float>(2);
    va.AddBuffer(vb,layout);
    shader.initShader("D:/UIT/VG-3609/start_code/include/Landscape.shader");
    shader.Bind();
//    shader.SetUniform4f("u_Color",0.2f,0.3f,0.8f,1.0f);



    texture.Bind(texSlot);
    shader.SetUniform1i("u_Texture", texSlot);
    texture1.Bind(texSlot + 1);
    shader.SetUniform1i("u_Texture2", texSlot + 1);
    projectionMatrix_ = glm::perspective(glm::radians(60.0f), 900.0f / 700.0f, 1.0f, 30000.0f);

    texture.Unbind();
    texture1.Unbind();
    va.Unbind();
    vb.Unbind();
    ib.Unbind();
    shader.Unbind();

}

void Landscape::privateRender()
{


       shader.Bind();
       texture.Bind(texSlot);
       texture1.Bind(texSlot + 1);


       shader.SetUniformMat4f("u_MVP",projectionMatrix_ * viewMatrix_* matrix_);

       vb.Bind();
       va.Bind();
       ib.Bind();
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
 if(matrix_[3].x<-400){
     auto translate = glm::translate(glm::mat4(1.0f),glm::vec3(1200.0f,0.0f,0.0f));
     matrix_ = matrix_ * translate;
 }

 auto translate = glm::translate(glm::mat4(1.0f),glm::vec3(-1.0f,0.0f,0.0f)) ;
 matrix_ = matrix_ * translate;
}

