//
//  RIImageCache.h
//  RelativeInterface
//
//  Created by Max Weisel on 12/12/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

// External
#import <Foundation/Foundation.h>

// Image
#import "RIImage.h"

/*!
 The RIImageCache class is used to cache RIImage objects for use throughout an application.
 
 RIImages created with -imageNamed: are automatically added / retreived from the shared cache.
 */

@interface RIImageCache : NSObject

///---------------------------------------------------------------------------------------
/// @name Getting the image cache
///---------------------------------------------------------------------------------------

/*!
 @brief Get the shared image cache.
 @details Use this method to retrieve the shared image cache for an application.
 */
+ (id)sharedCache;


///---------------------------------------------------------------------------------------
/// @name Storing and Retrieving images
///---------------------------------------------------------------------------------------

/*!
 @brief Add an image to the image cache.
 @details Use this method to add an image for a given key.
 @param image The RIImage to be added to the cache
 @param key The key used to store the image
 */
- (void)setImage:(RIImage *)image forKey:(NSString *)key;

/*!
 @brief Retrieve an image for a given key.
 @details Use this method to retrieve an image for a given key.
 @param key The key used to retrieve the image.
 */
- (RIImage *)imageForKey:(NSString *)key;


///---------------------------------------------------------------------------------------
/// @name Managing the cache
///---------------------------------------------------------------------------------------

/*!
 @brief Flushes all images that are not currently referenced from the cache.
 @details Use this method to flush all images that are no longer in use from the cache.
 */
- (void)flushCache;

@end
