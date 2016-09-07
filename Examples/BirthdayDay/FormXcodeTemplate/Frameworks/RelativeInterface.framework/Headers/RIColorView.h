//
//  RIColorView.h
//  RelativeInterface
//
//  Created by Max Weisel on 12/13/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

#import "RIView.h"

// Color Types
#import "RIColorTypes.h"

/*!
 The RIColorView class is a view that draws a single uniform color on a plane that runs along the x and y axes.
 */

@interface RIColorView : RIView

///---------------------------------------------------------------------------------------
/// @name Creating a color view
///---------------------------------------------------------------------------------------

/*!
 @brief Create a color view with an initial color.
 @details This method initializes an RIColorView with the color specified.
 @param color The RIColorRGBA value used to initialize the view.
 */
- (id)initWithColor:(RIColorRGBA)color;

/*!
 @brief An RIColorRGBA value that determines the view's color.
 @details The default value of this property is white (1.0f, 1.0f, 1.0f, 1.0f).
 */
@property (nonatomic, assign) RIColorRGBA color;

@end
