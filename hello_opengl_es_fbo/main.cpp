#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

#include <EGL/egl.h>
#include <GLES3/gl32.h>

//#include <EGL/egl.h>
//#include <GLES2/gl2.h>
//#include <GLES2/gl2ext.h>

#include <screen/screen.h>

#include "FBO.h"
#include "AFileUtil.h"

screen_context_t screen_ctx;
screen_window_t screen_win;

EGLDisplay egl_display;
EGLContext egl_ctx;
EGLSurface egl_surface;

static FBO* fbo_ = nullptr;

static int initScreen()
{
    int rc;

    //Create the screen context
    rc = screen_create_context(&screen_ctx, SCREEN_APPLICATION_CONTEXT);
    if (rc) {
        printf("hsp hsp hsp screen_create_window \n");
        return EXIT_FAILURE;
    }

    //Create the screen window that will be render onto
    rc = screen_create_window(&screen_win, screen_ctx);
    if (rc) {
        printf("hsp hsp hsp screen_create_window \n");
        return EXIT_FAILURE;
    }

    rc = screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_FORMAT, (const int[]){ SCREEN_FORMAT_RGBA8888 });
    if(rc != 0) {
        printf("hsp hsp hsp SCREEN_PROPERTY_FORMAT -> RGBA error. \n");
    }
    rc = screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_USAGE, (const int[]){ SCREEN_USAGE_OPENGL_ES3 });
    if(rc != 0) {
       printf("hsp hsp hsp hsp hsp SCREEN_PROPERTY_USAGE -> OPENGLES3 error. \n");
    }
    rc = screen_create_window_buffers(screen_win, 2);
    if (rc) {
        printf("hsp hsp hsp hsp screen_create_window_buffers \n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

static int initEGL(void)
{
    EGLBoolean rc;
    EGLConfig egl_conf = (EGLConfig)0;
    EGLint num_confs = 0;
    const EGLint egl_ctx_attr[] = {
        EGL_CONTEXT_CLIENT_VERSION, 3,
        EGL_NONE
    };

    const EGLint egl_attrib_list[] = {
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_ALPHA_SIZE, 8,
        EGL_DEPTH_SIZE, 24,
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT,
        EGL_SAMPLE_BUFFERS, 1,	// Added for anti-aliased lines
        EGL_NONE
    };

    egl_display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if (egl_display == EGL_NO_DISPLAY) {
        printf("hsp hsp hsp eglGetDisplay failed\n");
        return EXIT_FAILURE;
    }

    rc = eglInitialize(egl_display, NULL, NULL);
    if (rc != EGL_TRUE) {
        printf("hsp hsp hsp eglInitialize failed\n");
        return EXIT_FAILURE;
    }

    rc = eglChooseConfig(egl_display, egl_attrib_list, &egl_conf, 1, &num_confs);
    if ((rc != EGL_TRUE) || (num_confs == 0)) {
        printf("hsp hsp hsp eglChooseConfig failed\n");
        return EXIT_FAILURE;
    }

    egl_ctx = eglCreateContext(egl_display, egl_conf, EGL_NO_CONTEXT, (EGLint*)&egl_ctx_attr);
    if (egl_ctx == EGL_NO_CONTEXT) {
        printf("hsp hsp hsp eglCreateContext failed\n");
        return EXIT_FAILURE;
    }

    //Create the EGL surface from the screen window
    egl_surface = eglCreateWindowSurface(egl_display, egl_conf, screen_win, NULL);
    if (egl_surface == EGL_NO_SURFACE) {
        printf("hsp hsp hsp eglCreateWindowSurface failed\n");
        return EXIT_FAILURE;
    }

    rc = eglMakeCurrent(egl_display, egl_surface, egl_surface, egl_ctx);
    if (rc != EGL_TRUE) {
        printf("hsp hsp hsp eglMakeCurrent failed\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

GLuint LoadShader ( EGLenum type, const char *shaderSrc )
{
   GLuint shader = 0;
   GLint compiled;

   // Create the shader object
   shader = glCreateShader ( type );

   if ( !shader ) {
      return 0;
   }

   // Load the shader source
   glShaderSource( shader, 1, &shaderSrc, 0 );

   // Compile the shader
   glCompileShader( shader );

   // Check the compile status
   glGetShaderiv( shader, GL_COMPILE_STATUS, &compiled );
   if ( !compiled ) {
      GLint infoLen = 0;

      glGetShaderiv ( shader, GL_INFO_LOG_LENGTH, &infoLen );

      if ( infoLen > 1 ) {
         char *infoLog = static_cast<char*>(malloc ( sizeof ( char ) * infoLen ));
         glGetShaderInfoLog ( shader, infoLen, NULL, infoLog );
         printf("hsp hsp hsp hsp glGetShaderInfoLog  error:%s \n", infoLog);
         free ( infoLog );
      }

      glDeleteShader ( shader );
      return 0;
   }

   return shader;
}

static int initOpenGL(void)
{
    char vShaderStr[] =
                "#version 300 es \n"
    	        "precision highp float;\n"
                "layout (location = 0) in vec3 Position;\n"
                "void main()\n"
                "{\n"
                "    gl_Position = vec4(Position.xy,0.0,1.0);\n"
                "}\n";

    char fShaderStr[] =
                     "#version 300 es \n"
    		     "precision mediump float;\n"
                     "layout (location = 0) out vec4 Out_Color;\n"
                     "void main()\n"
                     "{\n"
                     "    Out_Color = vec4(0.0, 1.0, 0.0, 1.0);\n"
                     "}\n";                                     

    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint programObject;
    GLint linked;

    // Load the vertex/fragment shaders
    vertexShader = LoadShader ( GL_VERTEX_SHADER, vShaderStr );
    fragmentShader = LoadShader ( GL_FRAGMENT_SHADER, fShaderStr );

    // Create the program object
    programObject = glCreateProgram ( );

    if ( programObject == 0 ) {
          printf("hsp hsp hsp hsp programObject ====0 error.\n");
 	  return 0;
    }

    glAttachShader ( programObject, vertexShader );
    glAttachShader ( programObject, fragmentShader );

    // Link the program
    glLinkProgram ( programObject );

    // Check the link status
    glGetProgramiv ( programObject, GL_LINK_STATUS, &linked );
    if ( !linked ) {
 	  GLint infoLen = 0;

 	  glGetProgramiv ( programObject, GL_INFO_LOG_LENGTH, &infoLen );
 	  if ( infoLen > 1 ) {
 		 char *infoLog = static_cast<char*>(malloc ( sizeof ( char ) * infoLen ));
 		 glGetProgramInfoLog ( programObject, infoLen, NULL, infoLog );

                 printf("hsp hsp hsp hsp glGetProgramInfoLog error: %s.\n", infoLog);
 		 free ( infoLog );
 	  }

 	  glDeleteProgram ( programObject );

 	  return EXIT_FAILURE;
    }

    // Store the program object
    glUseProgram (programObject);

    // We don't need the shaders anymore
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);

    return EXIT_SUCCESS;
}

static EGLint surface_width;
static EGLint surface_height;

void render()
{
	
        
        if(fbo_ == nullptr) {
           fbo_ = new FBO();
           fbo_->init(1420,720);
   
        }
	GLfloat vTriangle[] = {
		   -1.f, -1.f, 0.0f,
		   -1.f, 1.f, 0.0f,
		   1.0f, 1.f, 0.0f
	};

         
        eglQuerySurface(egl_display, egl_surface, EGL_WIDTH, &surface_width);
        eglQuerySurface(egl_display, egl_surface, EGL_HEIGHT, &surface_height);
        
        printf("hsp hsp hsp hsp surface_width: %d  surface_height:%d .\n",surface_width, surface_height);

   
        fbo_->bindFbo();
        fbo_->drawFbo();
       
        //glViewport(0,0,surface_width, surface_height);
        //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(1.f, 0.f, 0.f, 1.f);
 GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
    printf("hsp hsp hsp hsp GL_has error.  error:%d  file:%s line:%d \n", error, __FILE__, __LINE__);
}
	// Load the vertex data
	glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, vTriangle);
	glEnableVertexAttribArray ( 0 );
	glDrawArrays ( GL_TRIANGLES, 0, 3 );

        
  error = glGetError();
    if (error != GL_NO_ERROR) {
    printf("hsp hsp hsp hsp GL_has error.  error:%d  file:%s line:%d \n", error, __FILE__, __LINE__);
}
      

        fbo_->unbindFbo();
    error = glGetError();
    if (error != GL_NO_ERROR) {
    printf("hsp hsp hsp hsp GL_has error.  error:%d  file:%s line:%d \n", error, __FILE__, __LINE__);}

    glFinish();
             error = glGetError();
    if (error != GL_NO_ERROR) {
    printf("hsp hsp hsp hsp GL_has error.  error:%d  file:%s line:%d \n", error, __FILE__, __LINE__);
}

    fbo_->bindFbo();
      error = glGetError();
    if (error != GL_NO_ERROR) {
    printf("hsp hsp hsp hsp GL_has error.  error:%d  file:%s line:%d \n", error, __FILE__, __LINE__);
}
    glViewport(0,0,1420,720);
      error = glGetError();
    if (error != GL_NO_ERROR) {
    printf("hsp hsp hsp hsp GL_has error.  error:%d  file:%s line:%d \n", error, __FILE__, __LINE__);
}
    unsigned char* read_buffer = (unsigned char*) malloc(1420 * 720 * 4);

    fbo_->readFbo(read_buffer);


     fbo_->unbindFbo();



// 	glFinish();
// 	void* read_buffer = (void*) malloc(960 * 960 * 4);
// 	 glReadPixels(0, 0, (GLsizei)960, (GLsizei)960, GL_RGBA, GL_UNSIGNED_BYTE, read_buffer);
//      error = glGetError();
//     if (error != GL_NO_ERROR) {
//     printf("hsp hsp hsp hsp GL_has error.  error:%d  file:%s line:%d \n", error, __FILE__, __LINE__);
//     unsigned char *ptr = (unsigned char*) read_buffer;
//     printf("hsp FBO::readFBO ptr[0] = %d  ptr[1] = %d  ptr[2] = %d  ptr[3] = %d   \n", (int)ptr[0], (int)ptr[1], (int)ptr[2], (int)ptr[3]); 
// }


 std::string savePath = "/tmp/main_test/avmsource";
 std::string output = savePath + std::string("/output/") + std::string("test") + std::string(".raw");
                    printf("hsp hsp output file: %s \n",output.c_str());
                    AFileUtil::save(
                        output.c_str(),
                        read_buffer,
                        surface_width * surface_height * 4
                    );
                    if (read_buffer != NULL) {
                        free(read_buffer);
                    }
}


static int frame_count = 0;

int main(int argc, char *argv[])
{
    int rc;

    rc = initScreen();
    if (rc != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    rc = initEGL();
    if (rc != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    rc = initOpenGL();
    if (rc != EXIT_SUCCESS) {
    	return EXIT_FAILURE;
    }

    while (1) {

    	// Draw a triangle
    	render();

        if(frame_count++ > 5) {
           break; 
        }

    	rc = eglSwapBuffers(egl_display, egl_surface);
        if (rc != EGL_TRUE) {
            printf("hsp hsp eglSwapBuffers failed\n");
            break;
        }
    }

if(fbo_ != nullptr) {
  delete fbo_;
}

    // Clean up EGL related objects
    eglMakeCurrent(egl_display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    eglDestroySurface(egl_display, egl_surface);
    eglDestroyContext(egl_display, egl_ctx);
    eglTerminate(egl_display);
    eglReleaseThread();

    // Clean up screen-related objects
    screen_destroy_window(screen_win);
    screen_destroy_context(screen_ctx);

    return EXIT_SUCCESS;
}
