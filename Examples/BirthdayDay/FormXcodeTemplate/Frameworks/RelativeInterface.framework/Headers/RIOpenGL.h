//
//  RIGL.h
//  RelativeInterface
//
//  Created by Max Weisel on 1/5/14.
//  Copyright (c) 2014 RelativeWave. All rights reserved.
//

#if TARGET_OS_IPHONE

// External
#  import <OpenGLES/ES2/gl.h>
#  import <OpenGLES/ES2/glext.h>

#  define glGenVertexArrays glGenVertexArraysOES
#  define glBindVertexArray glBindVertexArrayOES
#  define glDeleteVertexArrays glDeleteVertexArraysOES
#  define glIsVertexArray glIsVertexArrayOES

#elif TARGET_OS_MAC

// External
#  import <OpenGL/gl3.h>

#endif
