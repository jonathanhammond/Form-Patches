//
//  PMRPrimitiveInputPort.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMRValueInputPort.h"

#import "PMRelativeInterfacePlatform.h"

@class PMRPrimitive;

/*!
 The PMRPrimitiveInputPort class represents a port that accepts any primitive type (Boolean, Index, Number, Angle, Color or String). The default implementation will take care of all value conversion at runtime.
 
 PMRPrimitiveInputPort is made to be used directly in a PMRPatch subclass.
 */
@interface PMRPrimitiveInputPort : PMRValueInputPort

/*!
 @brief The boolean value of the input port.
 @details Querying this property will trigger Form to go and process all necessary upstream patches if they have not already been processed. Once processing has completed, it will return the value from the connected patch. PMRPrimitiveInputPort takes care of doing all necessary value conversion.
 */
@property (nonatomic, readonly) BOOL booleanValue;

/*!
 @brief The index value of the input port.
 @details Querying this property will trigger Form to go and process all necessary upstream patches if they have not already been processed. Once processing has completed, it will return the value from the connected patch. PMRPrimitiveInputPort takes care of doing all necessary value conversion.
 */
@property (nonatomic, readonly) int indexValue;

/*!
 @brief The number value of the input port.
 @details Querying this property will trigger Form to go and process all necessary upstream patches if they have not already been processed. Once processing has completed, it will return the value from the connected patch. PMRPrimitiveInputPort takes care of doing all necessary value conversion.
 */
@property (nonatomic, readonly) float numberValue;

/*!
 @brief The radians value of the input port.
 @details Querying this property will trigger Form to go and process all necessary upstream patches if they have not already been processed. Once processing has completed, it will return the value from the connected patch. PMRPrimitiveInputPort takes care of doing all necessary value conversion.
 */
@property (nonatomic, readonly) float radiansValue;

/*!
 @brief The degrees value of the input port.
 @details Querying this property will trigger Form to go and process all necessary upstream patches if they have not already been processed. Once processing has completed, it will return the value from the connected patch. PMRPrimitiveInputPort takes care of doing all necessary value conversion.
 */
@property (nonatomic, readonly) float degreesValue;

/*!
 @brief The color value of the input port.
 @details Querying this property will trigger Form to go and process all necessary upstream patches if they have not already been processed. Once processing has completed, it will return the value from the connected patch. PMRPrimitiveInputPort takes care of doing all necessary value conversion.
 */
@property (nonatomic, readonly) RIColorRGBA colorValue;

/*!
 @brief The string value of the input port.
 @details Querying this property will trigger Form to go and process all necessary upstream patches if they have not already been processed. Once processing has completed, it will return the value from the connected patch. PMRPrimitiveInputPort takes care of doing all necessary value conversion.
 */
@property (nonatomic, readonly) NSString *stringValue;

@property (nonatomic, strong) PMRPrimitive *defaultValue;
@property (nonatomic, readonly) PMRPrimitive *value;

@end
