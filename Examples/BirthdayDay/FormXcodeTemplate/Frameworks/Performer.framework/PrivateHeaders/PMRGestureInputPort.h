//
//  PMRGestureInputPort.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMRInputPort.h"

@interface PMRGestureInputPort : PMRInputPort

@property (nonatomic, readonly) NSSet *gestureRecognizers;

@end
