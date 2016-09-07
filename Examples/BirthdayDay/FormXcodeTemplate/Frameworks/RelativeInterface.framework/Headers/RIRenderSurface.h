//
//  RIRenderSurface.h
//  RelativeInterface
//
//  Created by Max Weisel on 12/17/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

// External
#import <Foundation/Foundation.h>

// Rendering
#import "RIRenderTypes.h"
#import "RIRenderSurfaceBuffer.h"

// Color Types
#import "RIColorTypes.h"

/*!
 The RIRenderSurface class represents a render target or OpenGL framebuffer.
 
 RIRenderContext provides a simple interface for rendering content. The render surface automatically sets up all needed buffers, resolves any necessary multisampling buffers and provides necessary GPU hints for clearing renderbuffers. It is used by RelativeInterface to render to the screen and to render content to images.
 */

@interface RIRenderSurface : NSObject

///---------------------------------------------------------------------------------------
/// @name Configuring the render surface
///---------------------------------------------------------------------------------------

/*!
 @brief An RIRenderSurfaceBuffer object that represents the color data of rendered content.
 @details The colorBuffer property points to the buffer that will receive all color data upon calling -[RIRenderSurface renderBlock:].
 
 The default value is a vanilla RIRenderSurfaceBuffer. If you would like to access its contents, use an RIImageRenderSurfaceBuffer.
 */
@property (nonatomic, strong) RIRenderSurfaceBuffer *colorBuffer;

/*!
 @brief The depth format to use when rendering.
 @details At this time, RelativeInterface does not support rendering the depth buffer to a texture. In the meantime, one can set the format of the internal depth buffer via this property.
 */
@property (nonatomic, assign) RIRenderDepthFormat depthFormat;

/*!
 @brief The stencil format to use when rendering.
 @details At this time, RelativeInterface does not support rendering the stencil buffer to a texture. In the meantime, one can set the format of the stencil depth buffer via this property.
 */
@property (nonatomic, assign) RIRenderStencilFormat stencilFormat;

/*!
 @brief The multisampling format to use when rendering.
 @details By default RIRenderSurface does not use multisampling. Changing this property to something other than RIRenderMultisampleFormatNone will tell the render surface to render content to multisampling buffers before resolving to the color, depth and stencil buffers.
 */
@property (nonatomic, assign) RIRenderMultisampleFormat multisampleFormat;

/*!
 @brief The viewport to use when rendering.
 @details The viewport is used to take content that has been normalized by the projection matrix and map it to the various buffers.
 
 The default value is (0, 0, 0, 0). If the width and height values are 0, the width and height of the colorBuffer will be used.
 */
@property (nonatomic, assign) RIRenderSurfaceViewport viewport;

/*!
 @brief An RIColorRGBA value representing the color to set each pixel in the color render buffer before rendering.
 @details Just before executing the contents of the block passed to -[RIRenderSurface renderBlock:], RIRenderSurface sets the viewport and sets each pixel value in the color buffer to the clearColor value.
 */
@property (nonatomic, assign) RIColorRGBA clearColor;


///---------------------------------------------------------------------------------------
/// @name Rendering to the render surface
///---------------------------------------------------------------------------------------

/*!
 @brief Execute a block of OpenGL render commands on the target render surface.
 @details To render contents to the render surface, simply pass call this method with a block that renders all content.
 
 The render surface will bind the render target, clear all buffers, set the viewport and execute the block. Once the block has finished executing, any necessary GPU hints are fired to discard the depth, stencil and multisample buffer contents.
 
 Once this method has returned, it is safe to use the contents of the attached buffers.
 @param block A block that executes OpenGL commands via an RIRenderContext.
 */
- (void)renderBlock:(void (^)(void))block;

@end
