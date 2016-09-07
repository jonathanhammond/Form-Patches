//
//  RIGestureRecognizerDelegate.h
//  RelativeInterface
//
//  Created by Max Weisel on 1/15/14.
//  Copyright (c) 2014 RelativeWave. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RIGestureRecognizer;

@protocol RIGestureRecognizerDelegate <NSObject>

@optional;
- (BOOL)gestureRecognizer:(RIGestureRecognizer *)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(RIGestureRecognizer *)otherGestureRecognizer;

@end
