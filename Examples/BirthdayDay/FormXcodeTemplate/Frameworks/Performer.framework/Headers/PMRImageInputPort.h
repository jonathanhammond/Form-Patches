//
//  PMRImageInputPort.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMRValueInputPort.h"

@class RIImage;

/*!
 The PMRImageInputPort class represents a port that accepts an image type.
 
 PMRImageInputPort is made to be used directly in a PMRPatch subclass.
 */
@interface PMRImageInputPort : PMRValueInputPort

@property (nonatomic, strong) RIImage *defaultValue;
@property (nonatomic, readonly) RIImage *value;

@end
