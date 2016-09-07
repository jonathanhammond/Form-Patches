//
//  PMRValueInputPort.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMRInputPort.h"

/*!
 The PMRValueInputPort class represents a port that accepts any object at runtime.
 
 PMRValueInputPort can be used directly in a PMRPatch subclass, or it can be subclassed to create a port that accepts only a specific object type.
 */
@interface PMRValueInputPort : PMRInputPort

///---------------------------------------------------------------------------------------
/// @name Properties
///---------------------------------------------------------------------------------------

/*!
 @brief The default value to use when the port is not wired up, or it is receiving nil from another patch.
 @details This property is different than the default value used to instantiate a FMRValueInputPort.
 
 At runtime, if Form is not able to retrieve an input value from the connected patch, or the value set in the editor is nil, the runtime will pass this value when the patch attempts to use the value property.
 */
@property (nonatomic, strong) id defaultValue;

/*!
 @brief The value of the input port.
 @details Querying this property will trigger Form to go and process all necessary upstream patches if they have not already been processed. Once processing has completed, it will return the value from the connected patch. If no patch is connected, it will pass the static value set in Form's editor. If there is no value set in Form's editor, it will return the value stored in the defaultValue property of this port.
 */
@property (nonatomic, readonly) id value;

@end
