//
//  PMRInteractionOutputPort.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMROutputPort.h"
#import "PMRInteractionDelegate.h"

// Interaction Delegate

@interface PMRInteractionOutputPort : PMROutputPort

@property (nonatomic, weak) id <PMRInteractionDelegate> delegate;

@end
