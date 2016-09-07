//
//  RIShaderCache.h
//  RelativeInterface
//
//  Created by Max Weisel on 12/4/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

// External
#import <Foundation/Foundation.h>

// Shader
#import "RIShader.h"

// Bundled Shaders
#import "RIBundledShaders.h"

/*!
 The RIShaderCache class is used to store commonly used shaders for use throughout an application.
 
 An RIShaderCache instance can be preloaded with a few default shaders. See RIBundledShaders.h for more info.
 */

@interface RIShaderCache : NSObject

///---------------------------------------------------------------------------------------
/// @name Getting the shader cache
///---------------------------------------------------------------------------------------

/*!
 @brief Get the shared shader cache.
 @details Use this method to retrieve the shared shader cache for an application.
 */
+ (id)sharedCache;

///---------------------------------------------------------------------------------------
/// @name Loading bundled shaders
///---------------------------------------------------------------------------------------

/*!
 @brief Load default shaders.
 @details This method loads the prebundled shaders that come with RelativeInterface.
 @note The prebundled shaders are defined in RIDefaultShaders.h
 */
- (void)loadDefaultShaders;


///---------------------------------------------------------------------------------------
/// @name Storing and Retrieving shaders
///---------------------------------------------------------------------------------------

/*!
 @brief Add a shader to the shader cache.
 @details Use this method to add a shader for a given key.
 @param shader The RIShader to be added to the cache
 @param key The key used to store the shader
 */
- (void)setShader:(RIShader *)shader forKey:(NSString *)key;

/*!
 @brief Retrieve a shader for a given key.
 @details Use this method to retrieve a shader for a given key.
 @param key The key used to retrieve the shader.
 */
- (id)shaderForKey:(NSString *)key;

@end
