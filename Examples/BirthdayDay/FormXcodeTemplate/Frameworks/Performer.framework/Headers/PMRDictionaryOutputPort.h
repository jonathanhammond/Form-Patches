//
//  PMRDictionaryOutputPort.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMRValueOutputPort.h"

/*!
 The PMRDictionaryOutputPort class represents a port that outputs a dictionary type.
 
 PMRDictionaryOutputPort is made to be used directly in a PMRPatch subclass.
 */
@interface PMRDictionaryOutputPort : PMRValueOutputPort

@property (nonatomic, strong) NSDictionary *value;

@end
