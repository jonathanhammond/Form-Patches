//
//  RIRenderSurfaceBuffer.h
//  RelativeInterface
//
//  Created by Max Weisel on 12/17/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

// External
#import <Foundation/Foundation.h>

// Geometry Types
#import "RIGeometryTypes.h"

// Render Types
#import "RIRenderTypes.h"

/*!
 The RIRenderSurfaceBuffer class represents a single buffer to render content into.
 
 RIRenderSurfaceBuffer has a few subclasses that provide access to their contents. A vanilla render surface buffer is used when a buffer is needed for render, but the contents do not need to be read. This is usually the case with depth, stencil and multisampling buffers.
 */

@interface RIRenderSurfaceBuffer : NSObject

///---------------------------------------------------------------------------------------
/// @name Creating a render surface buffer
///---------------------------------------------------------------------------------------

/*!
 @brief Create a vanilla render surface buffer.
 @details This method returns a new render surface buffer with the allocated storage size and format.
 @param storageSize The size in pixels of the internal buffer.
 @param storageFormat The OpenGL format for each pixel in the internal buffer.
 @param multisampleFormat The multisample format.
 */
- (id)initWithStorageSize:(RISize2I)storageSize storageFormat:(GLenum)storageFormat multisampleFormat:(RIRenderMultisampleFormat)multisampleFormat;


///---------------------------------------------------------------------------------------
/// @name Retrieving buffer information
///---------------------------------------------------------------------------------------

/*!
 @brief An RISize2I that represents the size of the internal buffer in pixels.
 */
@property (nonatomic, readonly) RISize2I storageSize;

/*!
 @brief An RISize2F that represents the size of the internal buffer in points.
 */
@property (nonatomic, readonly) RISize2F size;

/*!
 @brief The scale factor of the buffer's contents.
 */
@property (nonatomic, readonly) float scale;

@end
