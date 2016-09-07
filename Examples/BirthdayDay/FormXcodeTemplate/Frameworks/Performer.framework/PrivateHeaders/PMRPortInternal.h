//
//  PMRPortInternal.h
//  Performer
//
//  Created by Max Weisel on 6/26/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMRPort.h"

@class PMRPatch;
@class PMPort;

@interface PMRPort ()

@property (nonatomic, weak) PMRPatch *patch;
@property (nonatomic, weak) PMPort *nodePort;

@property (nonatomic, readonly) NSArray *connectedPorts;

@end
