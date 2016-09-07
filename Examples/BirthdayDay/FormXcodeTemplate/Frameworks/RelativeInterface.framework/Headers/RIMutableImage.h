//
//  RIMutableImage.h
//  RelativeInterface
//
//  Created by Max Weisel on 12/14/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

#import "RIImage.h"

#if !defined(APPORTABLE)
// CVPixelBuffer
#  import <CoreVideo/CVPixelBuffer.h>
#endif

/*!
 The RIMutableImage class represents an RIImage whose image data can be changed.
 
 RIMutableImage is useful for using a placeholder while lazily loading images or for streaming video data to an image.
 */

@interface RIMutableImage : RIImage

///---------------------------------------------------------------------------------------
/// @name Replacing image contents
///---------------------------------------------------------------------------------------

/*!
 @brief Replace image contents with an image from disk.
 @details This method loads an image from disk and replaces the receiving image's contents with it.
 @param path The path to the image file.
 */
- (void)replaceWithContentsOfFile:(NSString *)path;

/*!
 @brief Replace image contents with an image from disk with a specific coordinate system.
 @details This method loads an image from disk and replaces the receiving image's contents with it using the specified coordinate system.
 
 RICoordinateSystemTopLeftOrigin loads the image's top left corner at the texture coordinate (0, 0)
 RICoordinateSystemBottomLeftOrigin loads the image's bottom left corner at the texture coordinate (0, 0)
 @param path The path to the image file.
 @param coordinateSystem The coordinate system used when loading the image.
 */
- (void)replaceWithContentsOfFile:(NSString *)path coordinateSystem:(RICoordinateSystem)coordinateSystem;

#if TARGET_OS_IPHONE
/*!
 @brief Replace image contents with a UIImage.
 @details This method replaces the receiving image's contents with the contents of the passed UIImage.
 @param image The UIImage object.
 */
- (void)replaceWithUIImage:(UIImage *)image;

/*!
 @brief Replace image contents with a UIImage using a specific coordinate system.
 @details This method replaces the receiving image's contents with the contents of the passed UIImage using the specified coordinate system.
 
 RICoordinateSystemTopLeftOrigin loads the image's top left corner at the texture coordinate (0, 0)
 RICoordinateSystemBottomLeftOrigin loads the image's bottom left corner at the texture coordinate (0, 0)
 @param image The UIImage object.
 @param coordinateSystem The coordinate system used when loading the image.
 */
- (void)replaceWithUIImage:(UIImage *)image coordinateSystem:(RICoordinateSystem)coordinateSystem;
#endif

/*!
 @brief Replace image contents with a CGImage.
 @details This method replaces the receiving image's contents with the contents of the passed CGImage.
 @param image The CGImage object.
 @param scale The content scale factor of the image.
 */
- (void)replaceWithCGImage:(CGImageRef)image scale:(float)scale;

/*!
 @brief Replace image contents with a CGImage using a specific coordinate system.
 @details This method replaces the receiving image's contents with the contents of the passed CGImage using the specified coordinate system.
 
 RICoordinateSystemTopLeftOrigin loads the image's top left corner at the texture coordinate (0, 0)
 RICoordinateSystemBottomLeftOrigin loads the image's bottom left corner at the texture coordinate (0, 0)
 @param image The CGImage object.
 @param scale The content scale factor of the image.
 @param coordinateSystem The coordinate system used when loading the image.
 */
- (void)replaceWithCGImage:(CGImageRef)image scale:(float)scale coordinateSystem:(RICoordinateSystem)coordinateSystem;

/*!
 @brief Replaces image contents with raw image data.
 @details This method replaces the receiving image's contents with raw image data using a specific coordinate system.
 
 RICoordinateSystemTopLeftOrigin loads the image's top left corner at the texture coordinate (0, 0)
 RICoordinateSystemBottomLeftOrigin loads the image's bottom left corner at the texture coordinate (0, 0)
 @param imageData The image data to load.
 @param width The width of the image data in pixels.
 @param height The height of the image data in pixels.
 @param scale The content scale factor of the image.
 @param coordinateSystem The coordinate system used when loading the image.
 @param premultipliedAlpha A boolean value indicating whether or not the image data has a premultiplied alpha.
 @param pixelFormat The pixel format of the image data passed.
 */
- (void)replaceWithData:(GLubyte *)imageData width:(size_t)width height:(size_t)height scale:(float)scale coordinateSystem:(RICoordinateSystem)coordinateSystem premultipliedAlpha:(BOOL)premultipliedAlpha pixelFormat:(GLenum)pixelFormat;


///---------------------------------------------------------------------------------------
/// @name Replacing image contents asynchronously
///---------------------------------------------------------------------------------------

/*!
 @brief Replace image contents with an image from disk asynchronously.
 @details This method loads an image from disk and replaces the receiving image's contents with it.
 
 This method returns instantly and calls the completion block upon completion
 @param path The path to the image file.
 @param completionBlock The completion block to execute when image loading has completed.
 */
- (void)replaceWithContentsOfFile:(NSString *)path completionBlock:(RIImageCompletionBlock)completionBlock;

/*!
 @brief Replace image contents with an image from disk with a specific coordinate system asynchronously.
 @details This method loads an image from disk and replaces the receiving image's contents with it using the specified coordinate system.
 
 RICoordinateSystemTopLeftOrigin loads the image's top left corner at the texture coordinate (0, 0)
 RICoordinateSystemBottomLeftOrigin loads the image's bottom left corner at the texture coordinate (0, 0)
 @param path The path to the image file.
 @param coordinateSystem The coordinate system used when loading the image.
 @param completionBlock The completion block to execute when image loading has completed.
 */
- (void)replaceWithContentsOfFile:(NSString *)path coordinateSystem:(RICoordinateSystem)coordinateSystem completionBlock:(RIImageCompletionBlock)completionBlock;

#if TARGET_OS_IPHONE
/*!
 @brief Replace image contents with a UIImage asynchronously.
 @details This method replaces the receiving image's contents with the contents of the passed UIImage.
 @param image The UIImage object.
 @param completionBlock The completion block to execute when image loading has completed.
 */
- (void)replaceWithUIImage:(UIImage *)image completionBlock:(RIImageCompletionBlock)completionBlock;

/*!
 @brief Replace image contents with a UIImage using a specific coordinate system asynchronously.
 @details This method replaces the receiving image's contents with the contents of the passed UIImage using the specified coordinate system.
 
 RICoordinateSystemTopLeftOrigin loads the image's top left corner at the texture coordinate (0, 0)
 RICoordinateSystemBottomLeftOrigin loads the image's bottom left corner at the texture coordinate (0, 0)
 @param image The UIImage object.
 @param coordinateSystem The coordinate system used when loading the image.
 @param completionBlock The completion block to execute when image loading has completed.
 */
- (void)replaceWithUIImage:(UIImage *)image coordinateSystem:(RICoordinateSystem)coordinateSystem completionBlock:(RIImageCompletionBlock)completionBlock;
#endif

/*!
 @brief Replace image contents with a CGImage asynchronously.
 @details This method replaces the receiving image's contents with the contents of the passed CGImage.
 @param image The CGImage object.
 @param scale The content scale factor of the image.
 @param completionBlock The completion block to execute when image loading has completed.
 */
- (void)replaceWithCGImage:(CGImageRef)image scale:(float)scale completionBlock:(RIImageCompletionBlock)completionBlock;

/*!
 @brief Replace image contents with a CGImage using a specific coordinate system asynchronously.
 @details This method replaces the receiving image's contents with the contents of the passed CGImage using the specified coordinate system.
 
 RICoordinateSystemTopLeftOrigin loads the image's top left corner at the texture coordinate (0, 0)
 RICoordinateSystemBottomLeftOrigin loads the image's bottom left corner at the texture coordinate (0, 0)
 @param image The CGImage object.
 @param scale The content scale factor of the image.
 @param coordinateSystem The coordinate system used when loading the image.
 @param completionBlock The completion block to execute when image loading has completed.
 */
- (void)replaceWithCGImage:(CGImageRef)image scale:(float)scale coordinateSystem:(RICoordinateSystem)coordinateSystem completionBlock:(RIImageCompletionBlock)completionBlock;


///---------------------------------------------------------------------------------------
/// @name Replacing image contents with a CVPixelBuffer
///---------------------------------------------------------------------------------------

/*!
 @brief Replace image contents with the contents of a CVPixelBuffer.
 @details This method replaces the receiving image's contents with the contents of the specified CVPixelBuffer.
 
 This method also updates the image's size, coordinateSystem and coordinateSpace properties.
 @param pixelBuffer The CVPixelBufferRef to use.
 */
#if !defined(APPORTABLE)
- (void)replaceWithCVPixelBuffer:(CVPixelBufferRef)pixelBuffer;
#endif

@end
