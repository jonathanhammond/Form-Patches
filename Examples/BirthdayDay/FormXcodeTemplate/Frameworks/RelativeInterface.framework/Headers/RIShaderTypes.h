//
//  RIShaderTypes.h
//  RelativeInterface
//
//  Created by Max Weisel on 1/5/14.
//  Copyright (c) 2014 RelativeWave. All rights reserved.
//

// Attributes
typedef enum {
    RIShaderAttributePosition = 0,
    RIShaderAttributeNormal,
    RIShaderAttributeTangent,
    RIShaderAttributeBinormal,
    RIShaderAttributeColor,
    RIShaderAttributeTexCoord,
    
    RIShaderAttributesCount
} RIShaderAttributeIndex;

extern NSString *const RIShaderAttributeNamePosition;
extern NSString *const RIShaderAttributeNameNormal;
extern NSString *const RIShaderAttributeNameTangent;
extern NSString *const RIShaderAttributeNameBinormal;
extern NSString *const RIShaderAttributeNameColor;
extern NSString *const RIShaderAttributeNameTexCoord;


// Uniforms
extern NSString *const RIShaderUniformNamePosition;
extern NSString *const RIShaderUniformNameNormal;
extern NSString *const RIShaderUniformNameColor;
extern NSString *const RIShaderUniformNameTexCoord;
extern NSString *const RIShaderUniformNameSampler;
