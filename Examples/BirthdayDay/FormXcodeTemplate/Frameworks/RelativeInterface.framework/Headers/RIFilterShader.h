//
//  RIFilterShader.h
//  RelativeInterface
//
//  Created by Max Weisel on 5/7/14.
//  Copyright (c) 2014 RelativeWave. All rights reserved.
//

#import <Foundation/Foundation.h>

// Color Types
#import "RIColorTypes.h"

@protocol RIFilterShader <NSObject>

/*!
 @brief Set the uniform color value
 @details This method is used to set the uniform color value of the shader. This value must be set on every -draw call as it is a shared shader.
 @param color The color used for all vertices.
 */
- (void)setColor:(RIColorRGBA)color;

@end
