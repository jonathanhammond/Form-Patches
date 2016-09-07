//
//  RIAnimationClock.h
//  RelativeInterface
//
//  Created by Max Weisel on 12/20/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

// External
#import <Foundation/Foundation.h>

/*!
 The RIAnimationClockTick protocol defines the tick method called by RIAnimationClock.
 */

@protocol RIAnimationClockTick <NSObject>

/*!
 @brief Animation clock tick
 @details The animation clock tick method is called by RIAnimationClock when an object is added to the clock via -startTick:.
 @param deltaTime The number of seconds since the last tick call.
 @param videoSync A unix timestamp for when the currently updating / drawing frame will be displayed.
 */
- (void)tick:(double)deltaTime videoSync:(CFTimeInterval)videoSync;

@end

/*!
 The RIAnimationClock class represents an animation clock in RelativeInterface. It is used by RIApplication to provide a clock tick for each frame before the layout and draw phases.
 */

@interface RIAnimationClock : NSObject

/*!
 @brief Get the currently active clock.
 @details Use this method to retrieve the active animation clock for an application.
 */
+ (id)activeClock;


///---------------------------------------------------------------------------------------
/// @name Starting & Stopping animation ticks.
///---------------------------------------------------------------------------------------

/*!
 @brief Start animation clock ticks on an object.
 @details Use this method to start receiving clock ticks on an object. The tick method is defined in the RIAnimationClockTick protocol.
 @param object The object that will start receiving clock ticks.
 @note The animation clock does not hold a strong reference to its objects.
 */
- (void)startTick:(id<RIAnimationClockTick>)object;

/*!
 @brief Stop animation clock ticks on an object.
 @details Use this method to stop receiving clock ticks on an object.
 @param object The object that will stop receiving clock ticks.
 */
- (void)stopTick:(id<RIAnimationClockTick>)object;

/*!
 @brief Stop animation clock ticks for all objects.
 @details Use this method to stop receiving clock ticks for all objects.
 */
- (void)stopAllTicks;

@end
