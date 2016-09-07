//
//  PMRDictionaryInputPort.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMRValueInputPort.h"

/*!
 The PMRDictionaryInputPort class represents a port that accepts a dictionary type.
 
 PMRDictionaryInputPort is made to be used directly in a PMRPatch subclass.
 */
@interface PMRDictionaryInputPort : PMRValueInputPort

@property (nonatomic, strong) NSDictionary *defaultValue;
@property (nonatomic, readonly) NSDictionary *value;

@end
