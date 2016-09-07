//
//  RITouch.h
//  RelativeInterface
//
//  Created by Max Weisel on 12/19/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

// External
#import <Foundation/Foundation.h>

// Interaction
#import "RIInteraction.h"

// Geometry Types
#import "RIGeometryTypes.h"

#import "RIPlatform.h"

/*!
 The RITouch class represents a touch in 3D space.
 
 RITouch instances are persistant between each event for the same touch. This means you can compare pointers of RITouch objects to keep track of multiple touches between touch events.
 */

@interface RITouch : NSObject <RIInteraction>

///---------------------------------------------------------------------------------------
/// @name Getting touch information
///---------------------------------------------------------------------------------------

- (instancetype)init NS_UNAVAILABLE;

/*!
 @brief An RIRay3F value that represents the touch in global space coordinates.
 @details This property is recalculated everytime the RITouch object is passed via a touches event method.
 @note Call -[RITouch locationInView:] to project the touch onto a view's interactionPlane.
 */
@property (nonatomic, readonly) RIRay3F ray;

/*!
 @brief An RIRay3F value that represents the previous touch location in global space coordinates.
 @details This property is recalculated everytime the RITouch object is passed via a touches event method.
 @note Call -[RITouch previousLocationInView:] to project the previous touch location onto a view's interactionPlane.
 */
@property (nonatomic, readonly) RIRay3F previousRay;

/*!
 @brief Returns the point in the screen corresponding to the touch.
 @details screenPoint gives the location of the touch in the coordinate system
    of the largest container.  On a mobile device, this is the single application 
    view, but in a desktop environment, screenPoint is relative to application's
    main window.
 */
@property (nonatomic, readonly) RIPoint2F screenPoint;

/*!
 @brief Returns the state of screenPoint just prior to the last change in screenPoint.
 @details See screenPoint for coordinate system information.
 */
@property (nonatomic, readonly) RIPoint2F previousScreenPoint;

/*!
 @brief Get the previous location of a touch in a specific view.
 @details This method projects the previous touch location onto the view's interactionPlane and returns the result in the view's local coordinate space.
 
 The return point is a 3D vector that exists on the interaction plane. If the default interaction plane is used, the z coordinate will always be 0.
 @param view The view to project the previous touch location onto.
 */
- (RIPoint3F)previousLocationInView:(RIView *)view;


/*!
 @brief Get the force of the touch, commonly as measured by the amounnt of finger deformation.
 @details This property provides a normalized measure of the user's force on this touch, 
    with 1.0f being the force applied by a typical touch, 0.0f being the minimal force.
 Values greater than 1.0f result from "hard press" user actions.
 Devices running iOS 8 (thus without force-measurement support) will return a very
    rough estimate of the force of the touch based on the radius of the touch.
 Emulated touches based on mouse input will return 1.0f in all cases.
 */
@property (nonatomic, readonly) float touchForce;

/*!
 @brief Returns the maximum possible value of touchForce for this device.
 */
@property (nonatomic, readonly) float maximumPossibleTouchForce;

/*!
 @brief Returns true if the device provides full (not radius-estimated) support for measuring touch force.
 @details Emulated touches and devices without force-touch-measurement support will return NO.
 */
@property (nonatomic, readonly) BOOL touchForceSupported;

@end
