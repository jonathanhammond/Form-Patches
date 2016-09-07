//
//  RIImageRenderSurfaceBuffer.h
//  RelativeInterface
//
//  Created by Max Weisel on 12/18/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

#import "RIRenderSurfaceBuffer.h"

// Image
#import "RIMutableImage.h"

/*!
 The RIImageRenderSurfaceBuffer class represents an RIMutableImage buffer for use with a render surface.
 
 RIImageRenderSurfaceBuffer can be used with a render surface to render contents into an RIMutableImage for use elsewhere in RelativeInterface.
 */

@interface RIImageRenderSurfaceBuffer : RIRenderSurfaceBuffer

///---------------------------------------------------------------------------------------
/// @name Creating an image render surface buffer
///---------------------------------------------------------------------------------------

/*!
 @brief Create a new image render surface buffer.
 @details This method returns a new image render surface buffer with the allocated storage size and scale.
 
 The image property contains an RIMutableImage with an appropriate size and scale.
 @param storageSize The size in pixels of the internal buffer.
 @param scale The scale factor of the buffer contents.
 */
- (id)initWithStorageSize:(RISize2I)storageSize scale:(float)scale;

/*!
 @brief An RIMutableImage that is used as the render surface buffer.
 @details The image property returns the RIMutableImage that the image render surface buffer uses for storage.
 */
@property (nonatomic, readonly) RIMutableImage *image;

@end
