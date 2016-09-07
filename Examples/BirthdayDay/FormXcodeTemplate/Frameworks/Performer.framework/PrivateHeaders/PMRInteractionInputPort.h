//
//  PMRInteractionInputPort.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMRInputPort.h"

@interface PMRInteractionInputPort : PMRInputPort

// Whether or not this port is wired to other interaction ports.
@property (nonatomic, readonly) BOOL connected;
@property (nonatomic, readonly) NSArray *interactionDelegates;

@end
