#include <GLES3/gl32.h>
//#include <GLES3/gl31.h>
//#include <GLES3/gl3.h>


//#include <GLES2/gl2.h>
//#include <GLES2/gl2ext.h>

#include <cstdio>
#include <iostream>

class FBO {

public:
 virtual ~FBO();

int width_;
int height_;
private:
 GLuint _fboTexture;
 GLuint _fboHandle;
 GLuint _rboDepth;

public:
void init(int width, int height);
void bindFbo();
void unbindFbo();
void drawFbo();
void readFbo(void* buffer);
};
