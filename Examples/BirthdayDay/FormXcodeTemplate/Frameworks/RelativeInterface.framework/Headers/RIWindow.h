//
//  RIWindow.h
//  RelativeInterface
//
//  Created by Max Weisel on 11/29/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

#import "RIView.h"

/*!
 The RIWindow class is used as the top-most superview for any view hierarchy in RelativeInterface.
 
 An RIWindow instance manages the projection matrix and is responsible for unprojecting all interaction for its subviews.
 */

@interface RIWindow : RIView


///---------------------------------------------------------------------------------------
/// @name Configuring perspective
///---------------------------------------------------------------------------------------

/*!
 @brief The field of view of the application
 @details The field of view is used to calculate the perspective matrix applied to all views in the application.
 
 This value is an angle measured in radians along the vertical axis.
 
 @note The RIWindow is automatically positioned whenever the fieldOfView changes. The window is placed so that one unit is equal to one point on screen.
 */
@property (nonatomic, assign) float fieldOfView;

/*!
 @brief The distance between window and the near clipping plane.
 @details The window is automatically placed in 3D space based on the fieldOfView. This value sets the distance that the near clipping plane should be from the window.
 
 The default value is 150.0
 
 @note The near clipping plane cannot be placed behind the camera.
 */
@property (nonatomic, assign) float nearDistance;

/*!
 @brief The distance between window and the far clipping plane.
 @details The window is automatically placed in 3D space based on the fieldOfView. This value sets the distance that the far clipping plane should be from the window.
 
 The default value is 150.0
 */
@property (nonatomic, assign) float farDistance;


///---------------------------------------------------------------------------------------
/// @name Accessing the window's perspective transform
///---------------------------------------------------------------------------------------

/*!
 @brief The projection matrix used to represent the window.
 @details The projection matrix is a 4x4 matrix that represents the perspective matrix used for drawing all subviews of the window.
 
 This matrix does not include any of the translation transforms of the window. Those are reflected in the transformMatrix property.
 */
@property (nonatomic, readonly) GLKMatrix4 projectionMatrix;

@end
