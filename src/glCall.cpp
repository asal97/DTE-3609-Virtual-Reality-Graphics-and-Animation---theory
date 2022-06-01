#include "../include/glCall.h"

// for being able to identify possible errors happening with their specific

void GLClearError() {
    while (glGetError() != GL_NO_ERROR);

}

bool GLLogCall(const char* function, const char* file, int line) {
    while (GLenum error = glGetError())
    {
        std::cout << "Error " << error << std::endl;
        std::cout << "function " << function << std::endl;
        std::cout << "file " << file << std::endl;
        std::cout << "line " << line << std::endl;
        return false;
    }
    return true;
}
