#include <stdio.h>
#include "OpenGLRenderer.h"

using namespace gl;
using namespace globjects;

OpenGLRenderer::OpenGLRenderer()
{
}

OpenGLRenderer::~OpenGLRenderer()
{
}

int OpenGLRenderer::shutdown()
{
	SDL_GL_DeleteContext(context);
	SDL_Quit();
	return 0;
}

void OpenGLRenderer::swapBuffers()
{
	SDL_GL_SwapWindow(window);
}

int OpenGLRenderer::initialize(unsigned int width, unsigned int height) {

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		fprintf(stderr, "%s", SDL_GetError());
		exit(-1);
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

	window = SDL_CreateWindow("OpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	context = SDL_GL_CreateContext(window);

	// initialize and resolve all functions from the start.
	glbinding::Binding::initialize(false);

	//globjects::init();

	//glewExperimental = GL_TRUE;
	//GLenum err = glewInit();
	//if (GLEW_OK != err)
	//{
	//	fprintf(stderr, "Error GLEW: %s\n", glewGetErrorString(err));
	//}

	GLuint vertexBuffer[10];
	glGenBuffers(10, &vertexBuffer[0]);
	//fprintf(stderr, "%u\n", vertexBuffer[3]);
	return 0;
}

void OpenGLRenderer::setClearColor(float, float, float, float) {};
void OpenGLRenderer::clearBuffer(Renderer::CLEAR_BUFFER_FLAGS) {};
void OpenGLRenderer::setRenderTarget(RenderTarget* rt, DepthStencil* depthStencil) {};
void OpenGLRenderer::setPipelineState(PipelineState* ps) {};
void OpenGLRenderer::draw(Mesh* mesh, DrawInfo* data) {};