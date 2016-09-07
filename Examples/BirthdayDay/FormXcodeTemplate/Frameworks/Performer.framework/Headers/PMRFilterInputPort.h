//
//  PMRFilterInputPort.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMRValueInputPort.h"
#import "PMRelativeInterfacePlatform.h"

@class RIFilter;

/*!
 The PMRFilterInputPort class represents a port that accepts a filter type.
 
 PMRFilterInputPort is made to be used directly in a PMRPatch subclass.
 */
@interface PMRFilterInputPort : PMRValueInputPort

@property (nonatomic, strong) RIFilter *defaultValue;
@property (nonatomic, readonly) RIFilter *value;

@end
