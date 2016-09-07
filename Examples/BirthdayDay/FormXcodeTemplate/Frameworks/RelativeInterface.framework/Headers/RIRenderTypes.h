//
//  RIRenderTypes.h
//  RelativeInterface
//
//  Created by Max Weisel on 11/20/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

// Base
#import "RIBase.h"

// OpenGL
#import "RIOpenGL.h"

#if TARGET_OS_IPHONE

// Render Surface enums
typedef enum {
	RIRenderDepthFormatNone = GL_NONE,
	RIRenderDepthFormat16 = GL_DEPTH_COMPONENT16,
	RIRenderDepthFormat24 = GL_DEPTH_COMPONENT24_OES,
    RIRenderDepthFormat24StencilFormat8 = GL_DEPTH24_STENCIL8_OES
} RIRenderDepthFormat;

typedef enum {
    RIRenderStencilFormatNone = GL_NONE,
    RIRenderStencilFormat8 = GL_STENCIL_INDEX8
} RIRenderStencilFormat;

typedef enum {
	RIRenderMultisampleFormatNone = 0,
	RIRenderMultisampleFormat4X = 4,
} RIRenderMultisampleFormat;

#elif TARGET_OS_MAC

// Render Surface enums
typedef enum {
	RIRenderDepthFormatNone = GL_NONE,
	RIRenderDepthFormat16 = GL_DEPTH_COMPONENT16,
	RIRenderDepthFormat24 = GL_DEPTH_COMPONENT24,
} RIRenderDepthFormat;

typedef enum {
    RIRenderStencilFormatNone = GL_NONE,
    RIRenderStencilFormat8 = GL_STENCIL_INDEX8
} RIRenderStencilFormat;

typedef enum {
	RIRenderMultisampleFormatNone = 0,
} RIRenderMultisampleFormat;

#endif

typedef struct {
    GLint x;
 	GLint y;
 	GLsizei width;
 	GLsizei height;
} RIRenderSurfaceViewport;

RI_INLINE RIRenderSurfaceViewport RIRenderSurfaceViewportMake(GLint x, GLint y, GLsizei width, GLsizei height) {
    RIRenderSurfaceViewport viewport = {.x = x, .y = y, .width = width, .height = height};
    return viewport;
}
