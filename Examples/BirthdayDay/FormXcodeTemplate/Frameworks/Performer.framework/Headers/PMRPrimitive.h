//
//  PMRPrimitive.h
//  Performer
//
//  Created by Max Weisel on 6/26/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PMRPrimitiveStorageType) {
    PMRClearStorage = 0,
    PMRBooleanStorage,
    PMRIndexStorage,
    PMRNumberStorage,
    PMRRadiansStorage,
    PMRDegreesStorage,
    PMRColorStorage,
    PMRStringStorage
};

/*!
 The PMRPrimitive class represents a primitive type in Form (Boolean, Index, Number, Angle, Color or String). PMRPrimitive handles all value conversion at runtime.
 
 Generally, you will only ever need to make a primitive when setting the default value on an FMRPrimitiveInputPort. During execution, all PMRPrimitives are handled by the system.
 */
@interface PMRPrimitive : NSObject <NSCoding, NSCopying>

// Creation
+ (instancetype)primitiveWithNilValue;
+ (instancetype)primitiveWithBooleanValue:(BOOL)booleanValue;
+ (instancetype)primitiveWithIndexValue:(int)indexValue;
+ (instancetype)primitiveWithNumberValue:(float)numberValue;
+ (instancetype)primitiveWithRadiansValue:(float)radiansValue;
+ (instancetype)primitiveWithDegreesValue:(float)degreesValue;
+ (instancetype)primitiveWithColorValue:(RIColorRGBA)colorValue;
+ (instancetype)primitiveWithStringValue:(NSString *)stringValue;

// Initialization
- (instancetype)initWithNilValue;
- (instancetype)initWithBooleanValue:(BOOL)booleanValue;
- (instancetype)initWithIndexValue:(int)indexValue;
- (instancetype)initWithNumberValue:(float)numberValue;
- (instancetype)initWithRadiansValue:(float)radiansValue;
- (instancetype)initWithDegreesValue:(float)degreesValue;
- (instancetype)initWithColorValue:(RIColorRGBA)colorValue;
- (instancetype)initWithStringValue:(NSString *)stringValue;

// Storage
@property (nonatomic, readonly) PMRPrimitiveStorageType storageType;

// Values
@property (nonatomic, assign) BOOL booleanValue;
@property (nonatomic, assign) int indexValue;
@property (nonatomic, assign) float numberValue;
@property (nonatomic, assign) float radiansValue;
@property (nonatomic, assign) float degreesValue;
@property (nonatomic, assign) RIColorRGBA colorValue;
@property (nonatomic, retain) NSString *stringValue;

// Object Value
- (id)toObject;

@end
