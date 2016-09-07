//
//  RIShaderPositionTextureUniformColor.h
//  RelativeInterface
//
//  Created by Max Weisel on 12/13/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

#import "RIShader.h"

// Color Types
#import "RIColorTypes.h"

// Filter Shader
#import "RIFilterShader.h"

/*!
 RIShaderPositionTextureUniformColor is a bundled shader. It supports the RIShaderAttributePosition and RIShaderAttributeTexCoord attributes in addition to a color uniform via the -setColor: method.
 */

@interface RIShaderPositionTextureUniformColor : RIShader <RIFilterShader>

/*!
 @brief Set the uniform color value
 @details This method is used to set the uniform color value of the shader. This value must be set on every -draw call as it is a shared shader.
 @param color The color used for all vertices.
 */
- (void)setColor:(RIColorRGBA)color;

@end
