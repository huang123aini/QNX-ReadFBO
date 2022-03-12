#include "FBO.h"

void FBO::init(int width, int height) {

 width_ = width;
 height_ = height;         
 GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
    printf("hsp hsp hsp hsp GL_has error.  error:%d  file:%s line:%d \n", error, __FILE__, __LINE__);
}
        //render color texture
        _fboTexture = 0;
        glGenTextures(1, &_fboTexture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
        glBindTexture(GL_TEXTURE_2D, _fboTexture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glBindTexture(GL_TEXTURE_2D, 0);
  error = glGetError();
    if (error != GL_NO_ERROR) {
    printf("hsp hsp hsp hsp GL_has error.  error:%d  file:%s line:%d \n", error, __FILE__, __LINE__);
}
        
        //depth render buffer
        _rboDepth = 0;
        glGenRenderbuffers(1, &_rboDepth);
        glBindRenderbuffer(GL_RENDERBUFFER, _rboDepth);

          error = glGetError();
    if (error != GL_NO_ERROR) {
    printf("hsp hsp hsp hsp GL_has error.  error:%d  file:%s line:%d \n", error, __FILE__, __LINE__);
}
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
          error = glGetError();
    if (error != GL_NO_ERROR) {
    printf("hsp hsp hsp hsp GL_has error.  error:%d  file:%s line:%d \n", error, __FILE__, __LINE__);
}

        

  error = glGetError();
    if (error != GL_NO_ERROR) {
    printf("hsp hsp hsp hsp GL_has error.  error:%d  file:%s line:%d \n", error, __FILE__, __LINE__);
}
        _fboHandle = 0;
        glGenFramebuffers(1, &_fboHandle);
        glBindFramebuffer(GL_FRAMEBUFFER, _fboHandle);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, _fboTexture, 0);
          error = glGetError();
    if (error != GL_NO_ERROR) {
    printf("hsp hsp hsp hsp GL_has error.  error:%d  file:%s line:%d \n", error, __FILE__, __LINE__);
}       
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, _rboDepth);
          error = glGetError();
    if (error != GL_NO_ERROR) {
    printf("hsp hsp hsp hsp GL_has error.  error:%d  file:%s line:%d \n", error, __FILE__, __LINE__);
}
        GLenum fboStatus = glCheckFramebufferStatus(GL_FRAMEBUFFER);
        if (fboStatus != GL_FRAMEBUFFER_COMPLETE) {
            printf("hsp hsp hsp framebuffer is not complete . fboStatus:%d \n", fboStatus);
        }
        glBindRenderbuffer(GL_RENDERBUFFER, 0);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
  error = glGetError();
    if (error != GL_NO_ERROR) {
    printf("hsp hsp hsp hsp GL_has error.  error:%d  file:%s line:%d \n", error, __FILE__, __LINE__);
}
}


FBO::~FBO() {
    glDeleteFramebuffers(1, &_fboHandle);
    glDeleteTextures(1, &_fboTexture);
    glDeleteRenderbuffers(1, &_rboDepth);
}

void FBO::bindFbo() {
glBindFramebuffer(GL_FRAMEBUFFER, _fboHandle);
 GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
    printf("hsp hsp hsp hsp GL_has error.  error:%d  file:%s line:%d \n", error, __FILE__, __LINE__);
}
}

void FBO::unbindFbo() {
 glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void FBO::drawFbo() {
    glViewport(0, 0, width_ , height_);
GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
    printf("hsp hsp hsp hsp GL_has error.  error:%d  file:%s line:%d \n", error, __FILE__, __LINE__);
}
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  error = glGetError();
    if (error != GL_NO_ERROR) {
    printf("hsp hsp hsp hsp GL_has error.  error:%d  file:%s line:%d \n", error, __FILE__, __LINE__);
}
}

void FBO::readFbo(void* buffer) {

 printf("hsp hsp hsp hsp hsp hsp readFbo width:%d  height:%d \n", width_, height_);
  GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
    printf("hsp hsp hsp hsp GL_has error.  error:%d  file:%s line:%d \n", error, __FILE__, __LINE__);
}
 glReadPixels(0, 0, (GLsizei)width_, (GLsizei)height_, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
 error = glGetError();
    if (error != GL_NO_ERROR) {
    printf("hsp hsp hsp hsp GL_has error.  error:%d  file:%s line:%d \n", error, __FILE__, __LINE__);
}
 unsigned char *ptr = (unsigned char*) buffer;
    printf("hsp FBO::readFBO ptr[0] = %d  ptr[1] = %d  ptr[2] = %d  ptr[3] = %d   \n", (int)ptr[0], (int)ptr[1], (int)ptr[2], (int)ptr[3]); 

}
