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

	private:
    std::shared_ptr<Landscape> ls_;
    std::shared_ptr<Character> character_;
    std::shared_ptr<Camera> cam_;
    std::shared_ptr<Text> text_;
    std::shared_ptr<Snow> snow_;
    std::shared_ptr<Minimap> minimap_;
};

