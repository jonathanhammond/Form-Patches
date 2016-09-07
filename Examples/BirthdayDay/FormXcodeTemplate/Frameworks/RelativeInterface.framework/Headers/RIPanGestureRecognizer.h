//
//  RIPanGestureRecognizer.h
//  RelativeInterface
//
//  Created by Max Weisel on 1/14/14.
//  Copyright (c) 2014 RelativeWave. All rights reserved.
//

#import "RIGestureRecognizer.h"

// Geometry Types
#import "RIGeometryTypes.h"

@interface RIPanGestureRecognizer : RIGestureRecognizer

- (RIPoint3F)translationInView:(RIView *)view;
- (RIPoint3F)velocityInView:(RIView *)view;

@end
