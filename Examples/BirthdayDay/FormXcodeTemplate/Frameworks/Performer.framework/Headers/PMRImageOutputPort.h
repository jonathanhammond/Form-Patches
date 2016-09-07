//
//  PMRImageOutputPort.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMRValueOutputPort.h"

/*!
 The PMRImageOutputPort class represents a port that outputs an image type.
 
 PMRImageOutputPort is made to be used directly in a PMRPatch subclass.
 */
@interface PMRImageOutputPort : PMRValueOutputPort

@property (nonatomic, strong) RIImage *value;

@end
