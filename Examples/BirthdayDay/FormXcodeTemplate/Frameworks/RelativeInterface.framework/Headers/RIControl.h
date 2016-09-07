//
//  RIControl.h
//  RelativeInterface
//
//  Created by Max Weisel on 1/20/14.
//  Copyright (c) 2014 RelativeWave. All rights reserved.
//

#import "RIView.h"

// Control Types
#import "RIControlTypes.h"

/*!
 The RIControl class is the base class for all interaction controls (sliders, buttons, etc). RIControl handles managing target/action pairs and delivering interaction events to them.
 */

@interface RIControl : RIView

///---------------------------------------------------------------------------------------
/// @name Managing targets and action messages
///---------------------------------------------------------------------------------------

/*!
 @brief Adds a target/action pair to the control to be dispatched for particular control events.
 @details This method is used to specify target/action pairs for the control. This method may be used to add multiple target / action pairs for various control events.
 @param target The target object that will receive the action message.
 @param action The action message that will be called on the target. It cannot be NULL.
 @param controlEvents A bitmask representation of the control events that will fire the target/action pair.
 */
- (void)addTarget:(id)target action:(SEL)action forControlEvents:(RIControlEvents)controlEvents;

/*!
 @brief Removes a target/action pair from the control.
 @details This method is used to remove target/action pairs from the control.
 @param target The target object that will receive the action message. Pass nil to remove all target/action pairs that match the action passed.
 @param action The action message that will be called on the target. Pass NULL to remove all target/action pairs that match the target passed.
 @param controlEvents A bitmask representation of the control events that will fire the target/action pair.
 */
- (void)removeTarget:(id)target action:(SEL)action forControlEvents:(RIControlEvents)controlEvents;

/*!
 @brief Returns all targets associated with the control.
 @details This method returns an NSSet of all targets that have been added to the control.
 */
- (NSSet *)allTargets;

/*!
 @brief Returns the actions that are associated with a specific target and set of control events.
 @details This method returns an NSArray of NSString representations of the actions that are paired with a particular target.
 @param target The target object.
 @param controlEvents A bitmask representation of the control events.
 */
- (NSArray *)actionsForTarget:(id)target forControlEvent:(RIControlEvents)controlEvents;

/*!
 @brief Returns all control events associated with the control.
 @details This method returns a bitmask representation of all control events that have been added via target/action pairs.
 */
- (RIControlEvents)allControlEvents;

/*!
 @brief Sends action messages for the control events passed.
 @details This method fires every target/action pair that matches the control events passed.
 @param controlEvents A bitmask representation that specifies the target/action pairs to fire.
 */
- (void)sendActionsForControlEvents:(RIControlEvents)controlEvents;

/*!
 @brief This method is called in response to an event fire.
 @details This method dispatches a target/action pair. Subclasses may override this method to intercept action messages.
 @param action The action message that will be called on the target.
 @param target The target that will receive the action message.
 */
- (void)sendAction:(SEL)action to:(id)target;


///---------------------------------------------------------------------------------------
/// @name Managing control state
///---------------------------------------------------------------------------------------

/*!
 @brief An RIControlState bitmask that represents the state of the control.
 @details This property reflects the state of the control.
 */
@property (nonatomic, readonly) RIControlState state;

/*!
 @brief A Boolean value that indicates whether the control is enabled.
 @details This property is used to enable / disable the control. If a control is disabled, it will ignore touch events.
 */
@property (nonatomic, getter=isEnabled) BOOL enabled;

/*!
 @brief A Boolean value that indicates whether the control is highlighted.
 @details This property is used to indicate whether or not a touch is currently on top of the control. RIControl clears and updates this value with each touch event.
 */
@property (nonatomic, getter=isHighlighted) BOOL highlighted;

- (void)beginTrackingTouch:(RITouch *)touch;
- (void)continueTrackingTouch:(RITouch *)touch;
- (void)endTrackingTouch:(RITouch *)touch;
- (void)cancelTrackingTouch:(RITouch *)touch;

@end
