//
//  RIImage.h
//  RelativeInterface
//
//  Created by Max Weisel on 12/12/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

// External
#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>
#ifdef APPORTABLE
#  import <OpenGLES/ES2/gl.h>
#endif
#if TARGET_OS_IPHONE
#  import <UIKit/UIImage.h>
#endif

// Geometry Types
#import "RIGeometryTypes.h"

// Image Types
#import "RIImageTypes.h"

/*!
 The RIImage class represents an image in RelativeInterface.
 
 An RIImage instance roughly represents an OpenGL texture. Internally, multiple instances of RIImage can point to the same texture unless they're RIMutableImages.
 */

@interface RIImage : NSObject <NSCopying>

///---------------------------------------------------------------------------------------
/// @name Creating an image
///---------------------------------------------------------------------------------------

/*!
 @brief Create an image from disk.
 @details This method is analogous to UIImage's -imageNamed:. Simply pass the name of an image that exists in the app bundle.
 
 An image created with this method will be added to RelativeInterface's shared RIImageCache.
 @param name The image file name.
 @note Calling this method twice with the same image name will return the same object.
 */
+ (id)imageNamed:(NSString *)name;

/*!
 @brief Create an image from disk.
 @details This method is similar to -imageNamed: with the exception that images are not cached.
 @param path The path to the image file.
 @note Calling this method twice with the same image will return different objects.
 */
+ (id)imageWithContentsOfFile:(NSString *)path;

/*!
 @brief Create an image from disk.
 @details This method is similar to -imageNamed: with the exception that images are not cached.
 @param path The path to the image file.
 @note Calling this method twice with the same image will return different objects.
 */
- (id)initWithContentsOfFile:(NSString *)path;

/*!
 @brief Create an image from disk with a specific coordinate system.
 @details This method creates an image with a specific coordinate system.
 
 RICoordinateSystemTopLeftOrigin loads the image's top left corner at the texture coordinate (0, 0)
 RICoordinateSystemBottomLeftOrigin loads the image's bottom left corner at the texture coordinate (0, 0)
 @param path The path to the image file.
 @param coordinateSystem The coordinate system used when loading the image.
 @note Calling this method twice with the same image will return different objects.
 */
- (id)initWithContentsOfFile:(NSString *)path coordinateSystem:(RICoordinateSystem)coordinateSystem;

#if TARGET_OS_IPHONE
/*!
 @brief Create an image from a UIImage.
 @details This method creates an RIImage object from a UIImage representation.
 @param image The UIImage object.
 */
- (id)initWithUIImage:(UIImage *)image;

/*!
 @brief Create an image from a UIImage.
 @details This method creates an RIImage object from a UIImage representation with a specific coordinate system.
 
 RICoordinateSystemTopLeftOrigin loads the image's top left corner at the texture coordinate (0, 0)
 RICoordinateSystemBottomLeftOrigin loads the image's bottom left corner at the texture coordinate (0, 0)
 @param image The UIImage object.
 @param coordinateSystem The coordinate system used when loading the image.
 */
- (id)initWithUIImage:(UIImage *)image coordinateSystem:(RICoordinateSystem)coordinateSystem;
#endif

/*!
 @brief Create an image from a CGImageRef.
 @details This method creates an RIImage object from a CGImage representation.
 @param image The CGImage object.
 @param scale The content scale factor of the image.
 */
- (id)initWithCGImage:(CGImageRef)image scale:(float)scale;

/*!
 @brief Create an image from a CGImageRef.
 @details This method creates an RIImage object from a CGImage representation with a specific coordinate system.
 
 RICoordinateSystemTopLeftOrigin loads the image's top left corner at the texture coordinate (0, 0)
 RICoordinateSystemBottomLeftOrigin loads the image's bottom left corner at the texture coordinate (0, 0)
 @param image The CGImage object.
 @param scale The content scale factor of the image.
 @param coordinateSystem The coordinate system used when loading the image.
 */
- (id)initWithCGImage:(CGImageRef)image scale:(float)scale coordinateSystem:(RICoordinateSystem)coordinateSystem;

/*!
 @brief Create an image from raw image data.
 @details This method creates an RIImage object from a raw image data with a specific coordinate system.
 
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
- (id)initWithData:(GLubyte *)imageData width:(size_t)width height:(size_t)height scale:(float)scale coordinateSystem:(RICoordinateSystem)coordinateSystem premultipliedAlpha:(BOOL)premultipliedAlpha pixelFormat:(GLenum)pixelFormat;


///---------------------------------------------------------------------------------------
/// @name Creating an image asynchronously
///---------------------------------------------------------------------------------------

/*!
 @brief Create an image from disk asynchronously
 @details This method works exactly like +[RIImage imageNamed:], only it returns instantly and calls a completion block once the image has been loaded.
 
 An image created with this method will be added to RelativeInterface's shared RIImageCache.
 @param name The image file name.
 @param completionBlock The completion block to execute when image loading has completed.
 */
+ (id)imageNamed:(NSString *)name completionBlock:(RIImageCompletionBlock)completionBlock;

/*!
 @brief Create an image from disk asynchronously.
 @details This method works exactly like +[RIImage imageWithContentsOfFile:], only it returns instantly and calls a completion block once the image has been loaded.
 @param path The path to the image file.
 @param completionBlock The completion block to execute when image loading has completed.
 */
+ (id)imageWithContentsOfFile:(NSString *)path completionBlock:(RIImageCompletionBlock)completionBlock;

/*!
 @brief Create an image from disk asynchronously.
 @details This method works exactly like -[RIImage initWithContentsOfFile:], only it returns instantly and calls a completion block once the image has been loaded.
 @param path The path to the image file.
 @param completionBlock The completion block to execute when image loading has completed.
 */
- (id)initWithContentsOfFile:(NSString *)path completionBlock:(RIImageCompletionBlock)completionBlock;

/*!
 @brief Create an image from disk with a specific coordinate system asynchronously.
 @details This method works exactly like -[RIImage initWithContentsOfFile:coordinateSystem:], only it returns instantly and calls a completion block once the image has been loaded.
 @param path The path to the image file.
 @param coordinateSystem The coordinate system used when loading the image.
 @param completionBlock The completion block to execute when image loading has completed.
 */
- (id)initWithContentsOfFile:(NSString *)path coordinateSystem:(RICoordinateSystem)coordinateSystem completionBlock:(RIImageCompletionBlock)completionBlock;

#if TARGET_OS_IPHONE
/*!
 @brief Create an image from a UIImage asynchronously.
 @details This method works exactly like -[RIImage initWithUIImage:], only it returns instantly and calls a completion block once the image has been loaded.
 @param image The UIImage object.
 @param completionBlock The completion block to execute when image loading has completed.
 */
- (id)initWithUIImage:(UIImage *)image completionBlock:(RIImageCompletionBlock)completionBlock;

/*!
 @brief Create an image from a UIImage using a specific coordinate system asynchronously.
 @details This method works exactly like -[RIImage initWithUIImage:coordinateSystem:], only it returns instantly and calls a completion block once the image has been loaded.
 @param image The UIImage object.
 @param coordinateSystem The coordinate system used when loading the image.
 @param completionBlock The completion block to execute when image loading has completed.
 */
- (id)initWithUIImage:(UIImage *)image coordinateSystem:(RICoordinateSystem)coordinateSystem completionBlock:(RIImageCompletionBlock)completionBlock;
#endif

/*!
 @brief Create an image from a CGImageRef asynchronously.
 @details This method works exactly like -[RIImage initWithCGImage:scale:], only it returns instantly and calls a completion block once the image has been loaded.
 @param image The CGImage object.
 @param scale The content scale factor of the image.
 @param completionBlock The completion block to execute when image loading has completed.
 */
- (id)initWithCGImage:(CGImageRef)image scale:(float)scale completionBlock:(RIImageCompletionBlock)completionBlock;

/*!
 @brief Create an image from a CGImageRef asynchronously.
 @details This method works exactly like -[RIImage initWithCGImage:scale:coordinateSystem:], only it returns instantly and calls a completion block once the image has been loaded.
 @param image The CGImage object.
 @param scale The content scale factor of the image.
 @param coordinateSystem The coordinate system used when loading the image.
 @param completionBlock The completion block to execute when image loading has completed.
 */
- (id)initWithCGImage:(CGImageRef)image scale:(float)scale coordinateSystem:(RICoordinateSystem)coordinateSystem completionBlock:(RIImageCompletionBlock)completionBlock;


///---------------------------------------------------------------------------------------
/// @name Using an image
///---------------------------------------------------------------------------------------

/*!
 @brief Bind an image for drawing.
 @details This method binds an image for all drawing code that follows. Any drawing code / shader that requires a texture must have an image bound.
 
 This automatically binds to GL_TEXTURE0
 @note This method should only be called inside of -[RIView draw:]
 @see useWithTextureUnit:
 */
- (void)use;

/*!
 @brief Bind an image for drawing.
 @details This method binds an image for all drawing code that follows. Any drawing code / shader that requires a texture must have an image bound.
 
 Drawing with textures before binding an image is undefined and will produce unexpected results.
 @param textureUnit The texture unit to bind the image to.
 @note This method should only be called inside of -[RIView draw:]
 */
- (void)useWithTextureUnit:(GLenum)textureUnit;

/*!
 @brief Draw the image at a point.
 @details This method draws an image in a rectangle at the point specified.
 
 This is the equivalent of calling -[RIImage drawInRect:] with a rectangle made of the point and the image's size property.
 @param point The point to draw the image.
 @note This method should only be called inside of -[RIView draw:]. Using this method is slower than RIImageView.
 */
- (void)drawAtPoint:(RIPoint2F)point;

/*!
 @brief Draw the image in a rectangle.
 @details This method draws an image in a rectangle. The image will be drawn in local space coordinates.
 @param rect The area to draw the image.
 @note This method should only be called inside of -[RIView draw:]. Using this method is slower than RIImageView.
 */
- (void)drawInRect:(RIRect2F)rect;


///---------------------------------------------------------------------------------------
/// @name Accessing image information
///---------------------------------------------------------------------------------------

/*!
 @brief The size of the image in points.
 @details The size property is an RISize2F value that represents the size of the image in points.
 */
@property (nonatomic, readonly) RISize2F size;

/*!
 @brief The scale of the image.
 @details The scale property is a value that represents the image's content scale factor.
 */
@property (nonatomic, readonly) float scale;

/*!
 @brief The coordinate space of the image.
 @details The coordinateSystem property determines the origin and y-axis direction of an image.
 */
@property (nonatomic, readonly) RICoordinateSystem coordinateSystem;

/*!
 @brief The texture coordinates that would map this image to a quad.
 @details The coordinateSpace property contains a rect that accurately maps this image to a quad.
 */
@property (nonatomic, readonly) RICoordinateSpace coordinateSpace;

/*!
 @brief A Boolean value that indicates whether the image uses a premultiplied alpha.
 @details The premultipliedAlpha property is used when blending an image to determine if the alpha component has been premultiplied into the RGB components of the image.
 */
@property (nonatomic, readonly) BOOL premultipliedAlpha;


///---------------------------------------------------------------------------------------
/// @name Copying
///---------------------------------------------------------------------------------------

/*!
 @brief Create an immutable copy of the receiving image.
 @details This method uses RIImageProcess to render this image to a new image.
 */
- (id)copy;

@end
