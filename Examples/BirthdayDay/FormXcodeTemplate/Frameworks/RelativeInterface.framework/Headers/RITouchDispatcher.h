//
//  RITouchDispatcher.h
//  RelativeInterface
//
//  iOS only
//
//  Created by Max Weisel on 12/19/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

// External
#import <Foundation/Foundation.h>
#import <UIKit/UIEvent.h>

// Application
@class RIWindow;

// Geometry Types
#import "RIGeometryTypes.h"

// iOS-specific dispatcher for touch events
@interface RITouchDispatcher : NSObject

- (instancetype)initWithWindow:(RIWindow *)window;

- (void)systemTouchesBegan:(NSSet *)systemTouches withEvent:(UIEvent *)event;
- (void)systemTouchesMoved:(NSSet *)systemTouches withEvent:(UIEvent *)event;
- (void)systemTouchesEnded:(NSSet *)systemTouches withEvent:(UIEvent *)event;
- (void)systemTouchesCancelled:(NSSet *)systemTouches withEvent:(UIEvent *)event;

@end
