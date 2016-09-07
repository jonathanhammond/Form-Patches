//
//  PMRArrayInputPort.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMRValueInputPort.h"

/*!
 The PMRArrayInputPort class represents a port that accepts an array type.
 
 PMRArrayInputPort is made to be used directly in a PMRPatch subclass.
 */
@interface PMRArrayInputPort : PMRValueInputPort

@property (nonatomic, strong) NSArray *defaultValue;
@property (nonatomic, readonly) NSArray *value;

@end
