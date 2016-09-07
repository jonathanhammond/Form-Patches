//
//  PMRGestureOutputPort.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMROutputPort.h"

@class PMRViewPatch;

@interface PMRGestureOutputPort : PMROutputPort

@property (nonatomic, strong) RIGestureRecognizer *gestureRecognizer;

@property (nonatomic, readonly) PMRViewPatch *viewPatch;

@end
