//#include <GL/glew.h>

#include "../include/SceneObject.hpp"
#include "../include/GameManager.hpp"
#include "../include/Snow.h"
#include "../include/stb_image.h"

#include <iostream>
#include <random>




Snow::Snow() {}

void Snow::texture(){
    //Init texture
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glGenTextures(1, &texName_);

    glBindTexture(GL_TEXTURE_2D, texName_);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


    //width of texture, height of texture and number of colour channels
    int widthTex, heightTex, nrChannels;
    unsigned char *data = stbi_load("D:/UIT/VG-3609/start_code/assets/Snowflake2.png",
                                        &widthTex, &heightTex, &nrChannels, 0);
    if(data){
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthTex, heightTex, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    }
    else{
        std::cout << "Failed to load landscape texture" << std::endl;
    }


    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);

}

void Snow::particleInit(GLuint loop){
        particle[loop].x = pos_.x;
        particle[loop].y = pos_.y;
        particle[loop].z = pos_.z;

        particle[loop].life = life;								// Give All The Particles Full Life
        particle[loop].fade = float(rand()%100)/1000.0f+0.003f;	// Random Fade Speed

        particle[loop].xi = float((rand()%60)-30.0f);	// X Axis Speed And Direction
        particle[loop].yi = float((rand()%60)-30.0f);	// Y Axis Speed And Direction
        particle[loop].zi = float((rand()%60)-30.0f);	// Z Axis Speed And Direction

        particle[loop].xg = fall_.x;
        particle[loop].yg = fall_.y;
        particle[loop].zg = fall_.z;
}

void Snow::privateInit() {

        texture();

    for (loop = 0 ; loop < MAX_PARTICLES ; loop++){				// Initials All The Textures
        particle[loop].active = true;
        particleInit(loop);
    }



}

void Snow::privateRender() {

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texName_);
    glLoadIdentity();										// Reset The ModelView Matrix
    for (loop = 0 ; loop < MAX_PARTICLES ; loop++){					// Loop Through All The Particles
            // If The Particle Is Active
            float x = particle[loop].x;						// Grab Our Particle X Position
            float y = particle[loop].y;						// Grab Our Particle Y Position
            float z = particle[loop].z ;					// Particle Z Pos + Zoom

            glColor3f(1.0f, 1.0f, 1.0f);

            glBegin(GL_TRIANGLE_STRIP);
                glNormal3f(0.0f, 0.0f, 1.0f); glTexCoord2d(1,1); glVertex3f(x + size, y + size, z); // Top Right
                glNormal3f(0.0f, 0.0f, 1.0f); glTexCoord2d(0,1); glVertex3f(x - size, y + size, z); // Top Left
                glNormal3f(0.0f, 0.0f, 1.0f); glTexCoord2d(1,0); glVertex3f(x + size, y - size, z); // Bottom Right
                glNormal3f(0.0f, 0.0f, 1.0f); glTexCoord2d(0,0); glVertex3f(x - size, y - size, z); // Bottom Left
            glEnd();

            particle[loop].x += particle[loop].xi/(slowdown.x);
            particle[loop].y += particle[loop].yi/(slowdown.y);
            particle[loop].z += particle[loop].zi/(slowdown.z);

            particle[loop].xi += particle[loop].xg;
            particle[loop].yi += particle[loop].yg;
            particle[loop].zi += particle[loop].zg;

            particle[loop].life -= particle[loop].fade;

            if (particle[loop].life < 0.0f){// If Particle Is Burned Out
                particleInit(loop);
            }

    }
    glBindTexture(GL_TEXTURE_2D, NULL);
    glDisable(GL_TEXTURE_2D);


}

void Snow::privateUpdate() {
}
