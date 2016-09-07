//
//  RIInteraction.h
//  RelativeInterface
//
//  Created by Max Weisel on 1/10/14.
//  Copyright (c) 2014 RelativeWave. All rights reserved.
//

// External
#import <Foundation/Foundation.h>

// Geometry Types
#import "RIGeometryTypes.h"

// View
@class RIView;

/*!
 The RIInteraction protocol defines an interaction that can occur on a view.
 
 Usually these interactions are touches or mouse events.
 */

@protocol RIInteraction <NSObject>

/*!
 @brief The RIView in which the interaction initially occurred.
 */
@property (nonatomic, readonly, weak) RIView *view;

/*!
 @brief Get the location of an interaction in a specific view.
 @details This method projects an interaction onto the view's interactionPlane and returns the result in the view's local coordinate space.
 
 The return point is a 3D vector that exists on the interaction plane. If the default interaction plane is used, the z coordinate will always be 0.
 @param view The view to project the interaction onto.
 */
- (RIPoint3F)locationInView:(RIView *)view;

@end
