//
//  RIButton.h
//  RelativeInterface
//
//  Created by Max Weisel on 8/31/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

#import "RIControl.h"


/*!
 The RIButton class is the base class for all buttons. RIButton is very simple, it displays a view and a background view for various control states.
 */

@interface RIButton : RIControl

///---------------------------------------------------------------------------------------
/// @name Managing button views
///---------------------------------------------------------------------------------------

/*!
 @brief Sets the view to display for a specific state.
 @details This method is used to specify the view that should be displayed for a specific control state. If a view has not been specified for a control state, the view set for RIControlStateNormal will be used.
 @param view The view to display. Passing a nil view effectively clears the view for that state.
 @param state The control state for the specified view.
 */
- (void)setView:(RIView *)view forState:(RIControlState)state;

/*!
 @brief Sets the background view to display for a specific state.
 @details This method is used to specify the background view that should be displayed for a specific control state. If a background view has not been specified for a control state, the background view set for RIControlStateNormal will be used.
 @param backgroundView The background view to display. Passing a nil background view effectively clears the background view for that state.
 @param state The control state for the specified background view.
 */
- (void)setBackgroundView:(RIView *)backgroundView forState:(RIControlState)state;

@end
