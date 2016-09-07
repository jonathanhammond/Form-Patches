//
//  RIGestureRecognizerSubclass.h
//  RelativeInterface
//
//  Created by Max Weisel on 1/14/14.
//  Copyright (c) 2014 RelativeWave. All rights reserved.
//

#import "RIGestureRecognizer.h"

// Touch
#import "RITouch.h"

// View
#import "RIView.h"

@interface RIGestureRecognizer (Subclass)

@property (nonatomic, readwrite) RIGestureRecognizerState state;

- (void)touchesBegan:(NSSet *)touches;
- (void)touchesMoved:(NSSet *)touches;
- (void)touchesEnded:(NSSet *)touches;
- (void)touchesCancelled:(NSSet *)touches;
- (void)reset;

@end
