//
//  PMRPrimitiveOutputPort.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMRValueOutputPort.h"

// Primitives
#import "PMRPrimitive.h"

/*!
 The PMRPrimitiveOutputPort class represents a port that outputs a primitive type (Boolean, Index, Number, Angle, Color or String). The default implementation will take care of all value conversion at runtime.
 
 PMRPrimitiveOutputPort is made to be used directly in a PMRPatch subclass.
 */
@interface PMRPrimitiveOutputPort : PMRValueOutputPort

/*!
 @brief Sets the boolean value to pass out of the patch.
 @details This method is used to store a value to pass out of the patch. The Form runtime will take care of passing this onto all connected patches.
 @param booleanValue The boolean value to send out of the patch.
 */
- (void)setBooleanValue:(BOOL)booleanValue;

/*!
 @brief Sets the index value to pass out of the patch.
 @details This method is used to store a value to pass out of the patch. The Form runtime will take care of passing this onto all connected patches.
 @param indexValue The index value to send out of the patch.
 */
- (void)setIndexValue:(int)indexValue;

/*!
 @brief Sets the number value to pass out of the patch.
 @details This method is used to store a value to pass out of the patch. The Form runtime will take care of passing this onto all connected patches.
 @param numberValue The number value to send out of the patch.
 */
- (void)setNumberValue:(float)numberValue;

/*!
 @brief Sets the radians value to pass out of the patch.
 @details This method is used to store a value to pass out of the patch. The Form runtime will take care of passing this onto all connected patches.
 @param numberValue The radians value to send out of the patch.
 */
- (void)setRadiansValue:(float)radiansValue;

/*!
 @brief Sets the degrees value to pass out of the patch.
 @details This method is used to store a value to pass out of the patch. The Form runtime will take care of passing this onto all connected patches.
 @param numberValue The degrees value to send out of the patch.
 */
- (void)setDegreesValue:(float)degreesValue;

/*!
 @brief Sets the color value to pass out of the patch.
 @details This method is used to store a value to pass out of the patch. The Form runtime will take care of passing this onto all connected patches.
 @param numberValue The color value to send out of the patch.
 */
- (void)setColorValue:(RIColorRGBA)colorValue;

/*!
 @brief Sets the string value to pass out of the patch.
 @details This method is used to store a value to pass out of the patch. The Form runtime will take care of passing this onto all connected patches.
 @param numberValue The string value to send out of the patch.
 */
- (void)setStringValue:(NSString *)stringValue;

@property (nonatomic, strong) PMRPrimitive *value;

@end
