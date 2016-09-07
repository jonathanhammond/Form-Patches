//
//  PMRValueOutputPort.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMROutputPort.h"

/*!
 The PMRValueOutputPort class represents a port that outputs any object at runtime.
 
 PMRValueOutputPort can be used directly in a PMRPatch subclass, or it can be subclassed to create a port that outputs only a specific object type.
 */
@interface PMRValueOutputPort : PMROutputPort

///---------------------------------------------------------------------------------------
/// @name Properties
///---------------------------------------------------------------------------------------

/*!
 @brief The value to pass out of the patch.
 @details This property is used to store a value to pass out of the patch. The Form runtime will take care of passing this onto all connected patches.
 */
@property (nonatomic, strong) id value;

@end
