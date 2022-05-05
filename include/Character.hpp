#pragma once

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "SceneObject.hpp"

class Character : public SceneObject
{
	public:
        Character();
        ~Character();
         void moveUpward();
         void moveDownward();

  protected:
    void privateInit();
		void privateRender();
		void privateUpdate();
        void DrawBillboard();
        void CreateTexture();
        void DrawTexture();


	private:
	  float speed_;
      float life_;
      float armor_;
      float size_ = 50.0f;
      unsigned int texture;
      std::vector<glm::vec3> billboardArray_;
      std::vector<glm::vec2> billboardTexture_;
    
};

