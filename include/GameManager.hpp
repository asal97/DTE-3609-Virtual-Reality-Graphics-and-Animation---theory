#pragma once


#include <windows.h>

#include "Minimap.h"
#include <GL/gl.h>
#include <GL/glu.h>

#include "SceneObject.hpp"
#include "Landscape.hpp"
#include "Character.hpp"
#include "Camera.hpp"
#include "Text.h"
#include "Snow.h"
#include "Skybox.h"
#include "Billboard.h"
#include "Monster.h"
#include "helpertext.h"


class GameManager : public SceneObject
{
	public:
		GameManager();
		~GameManager();
    
    std::shared_ptr<Camera> getCam();
    std::shared_ptr<Character> getCharacter();

  protected:
    virtual void privateInit();
		virtual void privateRender();
		virtual void privateUpdate();
    void CollisionDetection();

	private:
    std::shared_ptr<Landscape> ls_;
    std::shared_ptr<Character> character_;
    std::shared_ptr<Camera> cam_;
    std::shared_ptr<Text> text_;
    std::shared_ptr<HelperText> helptext_;
    std::shared_ptr<Snow> snow_;
    std::shared_ptr<Minimap> minimap_;
    std::shared_ptr<Skybox> skybox_;
        std::shared_ptr<Billboard> billboard_;
        std::shared_ptr<Monster> monster_;
};

