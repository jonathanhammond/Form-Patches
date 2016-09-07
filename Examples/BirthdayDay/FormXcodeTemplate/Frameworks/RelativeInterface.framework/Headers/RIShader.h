//
//  RIShader.h
//  RelativeInterface
//
//  Created by Max Weisel on 12/4/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

// External
#import <Foundation/Foundation.h>

// TODO: Remove this, it's not needed
#import <GLKit/GLKit.h>

// Shader Types
#import "RIShaderTypes.h"

@class RIRenderContext;

/*!
 The RIShader class encapsulates an OpenGL vertex and fragment shader.
 
 Shaders can be bound by calling -[RIShader use] while inside of a view's -draw method.
 
 Commonly used shaders should be added to the RIShaderCache so they can be reused throughout an application.
 */

@interface RIShader : NSObject

///---------------------------------------------------------------------------------------
/// @name Creating a shader
///---------------------------------------------------------------------------------------

/*!
 @brief Create a shader
 @details This method only works for subclasses that override -init and load shader source via [super initWith...].
 */
+ (id)shader;

/*!
 @brief Create a shader from local files
 @details Load shaders from local files.
 
 Passing a file name loads from the main app bundle.
 @param vertexShader The vertex shader file path.
 @param fragmentShader The fragment shader file path.
 */
- (id)initWithVertexShaderFile:(NSString *)vertexShader fragmentShaderFile:(NSString *)fragmentShader;

/*!
 @brief Create a shader from source
 @details Load shaders from an NSString.
 @param vertexSource The vertex shader source code.
 @param fragmentSource The fragment shader source code.
 */
- (id)initWithVertexShaderSource:(NSString *)vertexSource fragmentShaderSource:(NSString *)fragmentSource;

/*!
 @brief Create a shader from source and provide the error message, if any generated
 @details Load shaders from an NSString.
 @param vertexSource The vertex shader source code.
 @param fragmentSource The fragment shader source code.
 @param errorMessage A mutable string that is set to the message of the compilation failure.
 */
- (instancetype)initWithVertexShaderSource:(NSString *)vertexSource
                      fragmentShaderSource:(NSString *)fragmentSource
                              errorMessage:(NSString **)message;


///---------------------------------------------------------------------------------------
/// @name Using a shader
///---------------------------------------------------------------------------------------

/*!
 @brief Activate a shader for drawing.
 @details Calling use on a shader will activate it for the next glDrawArrays/glDrawElements call.
 
 This will set the receiving shader as the current shader on the active render context. It will also bind all necessary uniforms for the current drawing view. Simply adding u_transformMatrix, u_inverseTransformMatrix, u_projectionMatrix, u_transformProjectionMatrix as a mat4 uniform is all that is needed. RIShader will automatically detect the uniform and bind the appropriate matrix.
 
 This method does not need to be called on a render context.
 
 Note: This method should only be called from inside of a view's -draw method.
 */
- (void)use;


///---------------------------------------------------------------------------------------
/// @name Configuring the shader
///---------------------------------------------------------------------------------------

/*!
 @brief Bind an attribute to an attribute index.
 @details Use this method to bind an attribute for reference later. All attributes must be bound before linking a shader.
 @param attributeName An NSString representation of the attribute name.
 @param index The index to bind to.
 @note Some shader indices are reserved by RelativeInterface. See RIAttributeIndex in RIShader.h for more info.
 */
- (void)bindAttribute:(NSString *)attributeName toIndex:(GLuint)index;

/*!
 @brief Link the shader program.
 @details Use this method to link the shader. All attributes must be bound before linking. This method must be called before a shader can be used.
 */
- (void)link;


/*!
 @brief Link the shader program and provide the GL's error message.  Returns YES if linking is successful.
 @details Use this method to link the shader. All attributes must be bound before linking. This method must be called before a shader can be used.
 @param message A mutable string that will be set with the error message (if any) from the linking attempt.
 */
- (BOOL)attemptLinkWithErrorMessage:(NSString **)message;


/*!
 @brief Get the location of a given uniform.
 @details Use this method to get the location of a uniform.
 @param uniformName The name of the uniform to retrieve.
 */
- (GLint)uniformLocation:(NSString *)uniformName;

///---------------------------------------------------------------------------------------
/// @name Subclasses
///---------------------------------------------------------------------------------------

/*!
 @brief Called by a render context to instruct the shader that it should bind for rendering.
 @details RIRenderContext keeps track of the currently bound shader in order to prevent unnecessary shader swapping. When a render context decides it is necessary for a shader to actually bind, it calls renderContextBindShader to instruct the shader to call glUseProgram and to set up any uniforms that are independent of any specific view.
 
 Subclasses should override this method if any special setup is needed. (ie, binding samplers to specific texture units)
 
 Note: If you do not call super, the shader will not be bound.
 @param context The RIRenderContext that is going to bind the shader.
 */
- (void)renderContextBindShader:(RIRenderContext *)context;

@end
