//
//  PMRFilterOutputPort.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMRValueOutputPort.h"

/*!
 The PMRFilterOutputPort class represents a port that outputs a filter type.
 
 PMRFilterOutputPort is made to be used directly in a PMRPatch subclass.
 */
@interface PMRFilterOutputPort : PMRValueOutputPort

@property (nonatomic, strong) RIFilter *value;

@end
