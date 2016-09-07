//
//  RIGestureRecognizer.h
//  RelativeInterface
//
//  Created by Max Weisel on 1/9/14.
//  Copyright (c) 2014 RelativeWave. All rights reserved.
//

// External
#import <Foundation/Foundation.h>

// Delegate
#import "RIGestureRecognizerDelegate.h"

// View
@class RIView;

// Geometry Types
#import "RIGeometryTypes.h"

typedef enum {
    RIGestureRecognizerStatePossible,
    
    RIGestureRecognizerStateBegan,
    RIGestureRecognizerStateChanged,
    RIGestureRecognizerStateEnded,
    RIGestureRecognizerStateCancelled,
    
    RIGestureRecognizerStateFailed,
    
    RIGestureRecognizerStateRecognized = RIGestureRecognizerStateEnded
} RIGestureRecognizerState;

@interface RIGestureRecognizer : NSObject

- (instancetype)initWithTarget:(id)target action:(SEL)action;

@property (nonatomic, assign) BOOL enabled;
@property (nonatomic, weak) id<RIGestureRecognizerDelegate>delegate;
@property (nonatomic, readonly, weak) RIView *view;
@property (nonatomic, readonly) RIGestureRecognizerState state;

- (RIPoint3F)locationInView:(RIView *)view;

- (void)addTarget:(id)target action:(SEL)action;
- (void)removeTarget:(id)target action:(SEL)action;

@end
