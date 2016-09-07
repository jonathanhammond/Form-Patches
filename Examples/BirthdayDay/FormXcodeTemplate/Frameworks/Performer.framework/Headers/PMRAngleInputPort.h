//
//  PMRAngleInputPort.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMRPrimitiveInputPort.h"

@class PMRPrimitive;

/*!
 The PMRAngleInputPort class represents a port that accepts an angle type specifically. The default implementation will take care of all value conversion at runtime.
 
 PMRAngleInputPort is made to be used directly in a PMRPatch subclass.
 */
@interface PMRAngleInputPort : PMRPrimitiveInputPort

@property (nonatomic, strong) PMRPrimitive *defaultValue;
@property (nonatomic, readonly) PMRPrimitive *value;

@end
