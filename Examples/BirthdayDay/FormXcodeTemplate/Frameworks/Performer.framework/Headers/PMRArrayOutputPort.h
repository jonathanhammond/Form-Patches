//
//  PMRArrayOutputPort.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMRValueOutputPort.h"

/*!
 The PMRArrayOutputPort class represents a port that outputs an array type.
 
 PMRArrayOutputPort is made to be used directly in a PMRPatch subclass.
 */
@interface PMRArrayOutputPort : PMRValueOutputPort

@property (nonatomic, strong) NSArray *value;

@end
