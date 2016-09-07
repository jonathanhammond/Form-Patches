//
//  RIView.h
//  RelativeInterface
//
//  Created by Max Weisel on 11/29/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

// External
#import <Foundation/Foundation.h>
#import <GLKit/GLKMatrix4.h>

// Geometry
#import "RIGeometryTypes.h"

// Interaction
#import "RIInteraction.h"
#import "RITouch.h"
#import "RIGestureRecognizer.h"

#if TARGET_OS_MAC && !TARGET_OS_IPHONE
#  import "RIMouse.h"
#  import "RIScroll.h"
#endif

/*!
 The RIView class is used to display content on screen. A view handles drawing content on screen and any touch interaction with that content.
 
 RIView has many similarities to UIView/CALayer from Apple's UIKit with a few differences:
 
 - Views are 3 dimensional coordinate spaces.
 - Views use position and size, instead of a frame
 - Views have an anchorPoint property
 
 */
@interface RIView : NSObject

///---------------------------------------------------------------------------------------
/// @name Configuring appearance
///---------------------------------------------------------------------------------------

/*!
 @brief A boolean value that indicates whether the view (and its subviews) will be drawn.
 @details Setting the value of this property to YES will stop the view from being drawn to the screen. The default value is NO.
 
 If a view is hidden, it will not receive new interaction events nor will it pass them on to its subviews.
 
 Setting the value of this property will stop the view's subviews from being drawn or receiving new interaction events, however, it will not alter their hidden state. Thus, a view's superview can cause the view to be hidden without the hidden property being set.
 
 @see effectivelyHidden
 */
@property (nonatomic, getter = isHidden) BOOL hidden;

/*!
 @brief A Boolean value that indicates whether the view (and its subviews) will be drawn.
 @details If a view's hidden property is set to NO, it can still be hidden by a superview. This property reflects whether the view itself or any of its superviews are hidden.
 */
@property (nonatomic, readonly, getter = isEffectivelyHidden) BOOL effectivelyHidden;

/*!
 @brief A float value that indicates the view's opacity.
 @details Setting the opacity of a view will affect the opacity of the view and the effectiveOpacity property of its subviews.
 
 The default value is 1.0.
 
 @see effectiveOpacity
 */
@property (nonatomic, assign) float opacity;

/*!
 @brief A float value that indicates the view's opacity including its superviews.
 @details This property is calculated based on the view's own opacity property and the opacity of all superviews.
 
 When creating an RIView subclass that includes custom drawing code, this is the value that should be used to set the opacity of the content that is being drawn.
 */
@property (nonatomic, readonly) float effectiveOpacity;


///---------------------------------------------------------------------------------------
/// @name Configuring the view's transform
///---------------------------------------------------------------------------------------

/*!
 @brief The view's 2-dimensional position.
 @details The view's position exists in its superview's coordinate space. The default value is (0, 0).
 @see position3
 @note Setting this property is the equivelent of setting the x and y values of position3.
 */
@property (nonatomic, assign) RIPoint2F position;

/*!
 @brief The view's position.
 @details The view's position exists in its superview's coordinate space. The default value is (0, 0, 0).
 @see position
 */
@property (nonatomic, assign) RIPoint3F position3;

/*!
 @brief The view's 2-dimensional size.
 @details The view's size determines the tappable area.
 @see size3
 @note Setting this property is the equivelent of setting size3 with the current depth value.
 */
@property (nonatomic, assign) RISize2F size;

/*!
 @brief The view's size.
 @details The view's size determines the tappable area. The default value is (0, 0, 0).
 @see size
 */
@property (nonatomic, assign) RISize3F size3;

/*!
 @brief The view's 2-dimensional rotation value.
 @details The rotation value of the view. The default value is (0, 0, 0).
 
 All rotation values are measured in radians.
 @see rotation3
 @note Setting this property is the equivelent of setting the z value of rotation3.
 */
@property (nonatomic, assign) float rotation;

/*!
 @brief The view's rotation.
 @details The rotation value of the view. The default value is (0, 0, 0).
 
 All rotation values are measured in radians.
 @see rotation
 */
@property (nonatomic, assign) RIPoint3F rotation3;

/*!
 @brief The view's uniformScale factor.
 @details This value scales the view uniformly along all axis. The default value is 1.0.
 */
@property (nonatomic, assign) float uniformScale;

/*!
 @brief The view's 2-dimensional anchor point.
 @details The anchor point is used to determine the center of the view's transform.
 
 It's value is often between (0, 0) and (1, 1) with the former residing in the top left corner and the latter in the bottom right when using the top-left origin coordinate space. A value of (0.5, 0.5) places the anchor point in the center of the view.
 
 The default value is (0, 0).
 @see anchorPoint3
 @note Setting this property is the equivelent of setting the x and y values of anchorPoint3.
 */
@property (nonatomic, assign) RIPoint2F anchorPoint;

/*!
 @brief The view's anchor point.
 @details The anchor point is used to determine the center of the view's transform. The default value is (0, 0, 0).
 @see anchorPoint
 */
@property (nonatomic, assign) RIPoint3F anchorPoint3;

/*!
 @brief The view's 2-dimensional origin in local coordinate space.
 @details This property is particularly useful for offsetting a view's subviews and content. The default value is (0, 0).
 @see localOrigin3
 @note Setting this property is the equivelent of setting the x and y values of localOrigin3.
 */
@property (nonatomic, assign) RIPoint2F localOrigin;

/*!
 @brief The view's origin in local coordinate space.
 @details This property is particularly useful for offsetting a view's subviews and content. The default value is (0, 0, 0).
 @see localOrigin
 */
@property (nonatomic, assign) RIPoint3F localOrigin3;

/*!
 @brief The view's coordinate system.
 @details The coordinate system property is used to set the origin and direction of the axes of the view's coordinate system.
 
 This value affects the view's drawing code, position, rotation and anchorPoint of subviews.
 
 The default value is RICoordinateSystemTopLeftOrigin.
 */
@property (nonatomic, assign) RICoordinateSystem coordinateSystem;

/*!
 @brief The view's content scale factor.
 @details This property determines how many pixels exist per point. On iOS this value is either 1.0 or 2.0 (Retina).
 
 If this view does not have a superview, its contentScaleFactor is set to that of the device's main screen.
 */
@property (nonatomic, readonly) float contentScaleFactor;


///---------------------------------------------------------------------------------------
/// @name Working with the view hierarchy
///---------------------------------------------------------------------------------------

/*!
 @brief Add a subview to the view's view hierarchy.
 @details This method adds a subview onto the top of the stack.
 
 Views maintain a strong reference to their subviews. Subviews maintain a weak reference to their superview.
 @param subview The view to be added.
 */
- (void)addSubview:(RIView *)subview;

/*!
 @brief Insert a subview into the view's view hierarchy at a specific index.
 @details This methods inserts a subview into the subview stack at the specified index.
 @param subview The view to be added.
 @param index The index at which to insert the view. The subview index cannot exceed the number of subviews.
 */
- (void)insertSubview:(RIView *)subview atIndex:(NSInteger)index;

/*!
 @brief Remove a subview from its superview's view hierarchy.
 */
- (void)removeFromSuperview;

/*!
 @brief Removes all subviews from the view's view hierarchy.
 */
- (void)removeAllSubviews;

/*!
 @brief The view's superview or nil if it has none.
 */
@property (nonatomic, weak, readonly) RIView *superview;

/*!
 @brief An array of the view's subviews.
 @details Use this property to retreive subviews contained by the view. Views are in drawing order with the view at index 0 being the back-most view.
 */
@property (nonatomic, readonly) NSArray *subviews;


///---------------------------------------------------------------------------------------
/// @name Laying out subviews
///---------------------------------------------------------------------------------------

/*!
 @brief Prepare for a layoutSubviews call.
 @details The default implementation of this method does nothing.
 
 RelativeInterface takes runs layoutSubviews for sibling views concurrently. This means layoutSubviews is not guaranteed to occur on the main thread. Any preparation required for layoutSubviews that needs to be run on the main thread should occur in this method.
 
 It is safe to assume that this method has finished for all superviews of the view receiving the message.
 @see layoutSubviews
 */
- (void)prepareForLayoutSubviews;

/*!
 @brief Lay out all subviews of the receiving view.
 @details The default implementation of this method does nothing.
 
 Subclasses should override this method to lay out their subviews. This method should never be called directly. Instead, call -[RIView setNeedsLayout] to force a -layoutSubviews call before the next draw. If a layout is required immediately, call -[RIView layoutSubviewsIfNeeded].
 
 This method does not run on the main thread! To improve layout performance, RelativeInterface calls layoutSubviews on sibling views concurrently. Therefore, one should never attempt to layout sibling views or superviews in this method. It is safe to assume that layoutSubviews has finished for all superviews of the view receiving the message.
 @see prepareForLayoutSubviews
 */
- (void)layoutSubviews;

/*!
 @brief Marks the current layout as dirty and triggers a layout before the next draw call.
 @details This method marks the layout as dirty. It will return immediately and recalculate layout on the next layout cycle. This allows you to invalidate the layout of multiple views at the same time without forcing any new immediate updates. Using this method also assures that only one layoutSubviews call is made per frame.
 @see layoutSubviews
 */
- (void)setNeedsLayout;

/*!
 @brief Forces subviews to layout immediately.
 @details This method forces subviews to be layed out immediately if necessary. In order to ensure that the subview layout isn't created and then invalidated by a superview relayout, this method traverses up the view hierarchy and starts with the top-most view that needs layout. Thus, calling this method may force all superviews to lay out.
 @see setNeedsLayout
 */
- (void)layoutSubviewsIfNeeded;


///---------------------------------------------------------------------------------------
/// @name Working with the view's transform
///---------------------------------------------------------------------------------------

/*!
 @brief The transform matrix for the current view.
 @details Use the the transformMatrix property to convert a point from local coordinate space to global coordinate space.
 @note This matrix does not include projection.
 */
@property (nonatomic, readonly) GLKMatrix4 transformMatrix;

/*!
 @brief The inverse transform matrix for the current view.
 @details Use the the inverseTransformMatrix property to convert a point from global coordinate space to local coordinate space.
 @note This matrix does not include projection.
 */
@property (nonatomic, readonly) GLKMatrix4 inverseTransformMatrix;


///---------------------------------------------------------------------------------------
/// @name Drawing
///---------------------------------------------------------------------------------------

/*!
 @brief Prepares to draw the view's contents.
 @details You should never call this method directly. This method will be called automatically by the application just before it calls -draw.
 
 Use this method to perform any calculations needed for -draw. If calculations need to be made on a per-frame basis, use the RIAnimationClock to receive a -tick: event before each frame is drawn.
 */
- (void)prepareForDraw;

/*!
 @brief Draws the view's contents.
 @details You should never call this method directly. This method will be called automatically by the application whenever the view's contents need to be drawn.
 
 Do not use the draw method to perform calculations. If calculations need to be made on a per-frame basis, use the RIAnimationClock to receive a -tick: event before each frame is drawn.
 
 RelativeInterface requires that draw methods use vertex array objects for setting state. Performing draws without them will result in undefined behavior.
 */
- (void)draw;

/*!
 @brief Marks the current view as needing a fresh draw call.
 @details This method marks the view's representation on screen as invalid. It will return immediately and force all necessary views to draw on the next draw cycle.
 @see draw
 */
- (void)setNeedsDraw;

/*!
 @brief Retrieve the view that is currently drawing.
 @details This method returns the view currently running -draw or nil if no view is currently drawing.
 
 This method is useful for implementing drawing methods that do not pertain to one view. (`-[RIImage drawAtPoint:point];` uses this method)
 */
+ (RIView *)currentDrawingView;


///---------------------------------------------------------------------------------------
/// @name Interaction
///---------------------------------------------------------------------------------------

/*!
 @brief A Boolean value indicating whether this view should receive interaction events.
 @details Setting this value to NO stops the view (and its subviews) from receiving touches. The default value is YES.
 */
@property (nonatomic, assign) BOOL interactionEnabled;

/*!
 @brief The plane that interactions are projected onto.
 @details A view's interaction plane exists in the view's local coordinate space.
 
 All interactions are converted into rays and projected onto each view's interactionPlane. If the projected point is inside of the view's bounding box (determined by the size3 value) the view will receive the touch.
 
 The default value is a plane that runs parallel to the x and y axis.
 */
@property (nonatomic, assign) RIPlane interactionPlane;

/*!
 @brief The plane that interactions are projected onto, represented in global space coordinates.
 @details A view's global interaction plane is calculated by transforming the view's interaction plane by its transform matrix.
 @see interactionPlane
 */
@property (nonatomic, readonly) RIPlane worldInteractionPlane;

/*!
 @brief Determines if an interaction resides inside of a view.
 @details This method projects the interaction onto the view's interactionPlane, then tests that the intersection point resides inside of the view's bounding box. (determined by the size3 value)
 @param interaction The interaction used to perform the hit test.
 */
- (BOOL)hitTest:(id<RIInteraction>)interaction;

/*!
 @brief Returns the subview that an interaction corresponds to.
 @details This method traverses the receiving view's view hierarchy in search of a view that passes -hitTest:. If no view is found, nil is returned.
 @param interaction The interaction used to perform the hit test.
 */
- (RIView *)viewForInteraction:(id<RIInteraction>)interaction;

/*!
 @brief Tells the receiving view when a group of touches have began tracking in the receiving view.
 @details The default implementation passes the touches event up to its superview.
 
 If you override this method without calling super, it is recommended that you override all touches event methods in order to prevent unexpected behavior.
 @param touches An NSSet of RITouch objects.
 */
- (void)touchesBegan:(NSSet *)touches;

/*!
 @brief Tells the receiving view when a group of touches have moved in the receiving view.
 @details The default implementation passes the touches event up to its superview.
 
 If you override this method without calling super, it is recommended that you override all touches event methods in order to prevent unexpected behavior.
 @param touches An NSSet of RITouch objects.
 */
- (void)touchesMoved:(NSSet *)touches;

/*!
 @brief Tells the receiving view when a group of touches have ended tracking in the receiving view.
 @details The default implementation passes the touches event up to its superview.
 
 If you override this method without calling super, it is recommended that you override all touches event methods in order to prevent unexpected behavior.
 @param touches An NSSet of RITouch objects.
 */
- (void)touchesEnded:(NSSet *)touches;

/*!
 @brief Tells the receiving view when a group of touches have cancelled tracking in the receiving view.
 @details The default implementation passes the touches event up to its superview.
 
 If you override this method without calling super, it is recommended that you override all touches event methods in order to prevent unexpected behavior.
 @param touches An NSSet of RITouch objects.
 */
- (void)touchesCancelled:(NSSet *)touches;

#if TARGET_OS_MAC && !TARGET_OS_IPHONE
/*!
 @brief Tells the receiving view when a mouse event has began tracking in the receiving view.
 @details The default implementation passes the mouse event up to its superview.
 
 If you override this method without calling super, it is recommended that you override all mouse event methods in order to prevent unexpected behavior.
 @param mouse An RIMouse object that represents the mouse cursor.
 */
- (void)mouseBegan:(RIMouse *)mouse;

/*!
 @brief Tells the receiving view when a mouse event has moved in the receiving view.
 @details The default implementation passes the mouse event up to its superview.
 
 If you override this method without calling super, it is recommended that you override all mouse event methods in order to prevent unexpected behavior.
 @param mouse An RIMouse object that represents the mouse cursor.
 */
- (void)mouseMoved:(RIMouse *)mouse;

/*!
 @brief Tells the receiving view when a mouse event has ended tracking in the receiving view.
 @details The default implementation passes the mouse event up to its superview.
 
 If you override this method without calling super, it is recommended that you override all mouse event methods in order to prevent unexpected behavior.
 @param mouse An RIMouse object that represents the mouse cursor.
 */
- (void)mouseEnded:(RIMouse *)mouse;

/*!
 @brief A Boolean value indicating whether this view should receive mouse hover events.
 @details Setting this value to NO stops the view from receiving mouse hover events. The default value is NO.
 */
@property (nonatomic, assign) BOOL mouseHoverEnabled;

/*!
 @brief Tells the receiving view when a mouse hover event has began tracking in the receiving view.
 @details The default implementation passes the mouse event up to its superview.
 
 If you override this method without calling super, it is recommended that you override all mouse event methods in order to prevent unexpected behavior.
 @param mouse An RIMouse object that represents the mouse cursor.
 */
- (void)mouseHoverBegan:(RIMouse *)mouse;

/*!
 @brief Tells the receiving view when a mouse hover event has moved in the receiving view.
 @details The default implementation passes the mouse event up to its superview.
 
 If you override this method without calling super, it is recommended that you override all mouse event methods in order to prevent unexpected behavior.
 @param mouse An RIMouse object that represents the mouse cursor.
 */
- (void)mouseHoverMoved:(RIMouse *)mouse;

/*!
 @brief Tells the receiving view when a mouse hover event has ended tracking in the receiving view.
 @details The default implementation passes the mouse event up to its superview.
 
 If you override this method without calling super, it is recommended that you override all mouse event methods in order to prevent unexpected behavior.
 @param mouse An RIMouse object that represents the mouse cursor.
 */
- (void)mouseHoverEnded:(RIMouse *)mouse;

/*!
 @brief Tells the receiving view when a scroll event has began tracking in the receiving view.
 @details The default implementation passes the scroll event up to its superview.
 
 If you override this method without calling super, it is recommended that you override all scroll event methods in order to prevent unexpected behavior.
 @param scroll An RIScroll object that represents the scroll wheel.
 */
- (void)scrollBegan:(RIScroll *)scroll;

/*!
 @brief Tells the receiving view when a scroll event has moved in the receiving view.
 @details The default implementation passes the scroll event up to its superview.
 
 If you override this method without calling super, it is recommended that you override all scroll event methods in order to prevent unexpected behavior.
 @param scroll An RIScroll object that represents the scroll wheel.
 */
- (void)scrollMoved:(RIScroll *)scroll;

/*!
 @brief Tells the receiving view when a scroll event has ended tracking in the receiving view.
 @details The default implementation passes the scroll event up to its superview.
 
 If you override this method without calling super, it is recommended that you override all scroll event methods in order to prevent unexpected behavior.
 @param scroll An RIScroll object that represents the scroll wheel.
 */
- (void)scrollEnded:(RIScroll *)scroll;

/*!
 @brief Tells the receiving view when a scroll event has cancelled tracking in the receiving view.
 @details The default implementation passes the scroll event up to its superview.
 
 If you override this method without calling super, it is recommended that you override all scroll event methods in order to prevent unexpected behavior.
 @param scroll An RIScroll object that represents the scroll wheel.
 */
- (void)scrollCancelled:(RIScroll *)scroll;

#endif

///---------------------------------------------------------------------------------------
/// @name Gesture Recognizers
///---------------------------------------------------------------------------------------

/*!
 @brief Adds an RIGestureRecognizer to the receiving view.
 @details Use this method to add an RIGestureRecognizer to a view.
 
 Once added, an RIGestureRecognizer will receive all interaction events that hit the receiving view.
 @param gestureRecognizer an RIGestureRecognizer subclass.
 */
- (void)addGestureRecognizer:(RIGestureRecognizer *)gestureRecognizer;

/*!
 @brief Remove an RIGestureRecognizer from the receiving view.
 @details Use this method to remove an RIGestureRecognizer from a view.
 @param gestureRecognizer an RIGestureRecognizer subclass that has already been added to the view.
 */
- (void)removeGestureRecognizer:(RIGestureRecognizer *)gestureRecognizer;

/*!
 @brief Remove all RIGestureRecognizers from the receiving view.
 @details Use this method to remove all RIGestureRecognizers from a view.
 */
- (void)removeAllGestureRecognizers;

/*!
 @brief An array of all gesture recognizers that are attached to the view.
 @details An immutable array of all RIGestureRecognizer subclasses that have been added to the view.
 */
@property (nonatomic, readonly) NSArray *gestureRecognizers;


///---------------------------------------------------------------------------------------
/// @name Stenciling
///---------------------------------------------------------------------------------------

/*!
 @brief The view's stencil.
 @details The stencilView is used to clip the content of the view. If this property is nil, no clipping will occur. The default value of this property is nil.
 
 Each stencilled view can only have 7 parent views with stencils. This is due to an 8-bit limitation in the OpenGL ES stencil buffer.
 
 If the stencilView does not have a superview, it will be drawn in the view's local coordinate space.
 */
@property (nonatomic, strong) RIView *stencilView;


///---------------------------------------------------------------------------------------
/// @name Converting between views
///---------------------------------------------------------------------------------------

/*!
 @brief Converts a point from the receiving view to another view.
 @details This method converts a point from the receiving view to another view's coordinate space. Both views must share a common ancestor.
 @param point An RIPoint2F in the receiving view's coordinate space.
 @param view An RIView that shares a common ancestor with the receiving view.
 */
- (RIPoint2F)convertPoint2F:(RIPoint2F)point toView:(RIView *)view;

/*!
 @brief Converts a point from another view to the receiving view.
 @details This method converts a point from another view to the receiving view's coordinate space. Both views must share a common ancestor.
 @param point An RIPoint2F in another view's coordinate space.
 @param view An RIView that shares a common ancestor with the receiving view.
 */
- (RIPoint2F)convertPoint2F:(RIPoint2F)point fromView:(RIView *)view;

/*!
 @brief Converts a point from the receiving view to another view.
 @details This method converts a point from the receiving view to another view's coordinate space. Both views must share a common ancestor.
 @param point An RIPoint3F in the receiving view's coordinate space.
 @param view An RIView that shares a common ancestor with the receiving view.
 */
- (RIPoint3F)convertPoint3F:(RIPoint3F)point toView:(RIView *)view;

/*!
 @brief Converts a point from another view to the receiving view.
 @details This method converts a point from another view to the receiving view's coordinate space. Both views must share a common ancestor.
 @param point An RIPoint3F in another view's coordinate space.
 @param view An RIView that shares a common ancestor with the receiving view.
 */
- (RIPoint3F)convertPoint3F:(RIPoint3F)point fromView:(RIView *)view;

/*!
 @brief Converts a vector from the receiving view to another view.
 @details This method converts a vector from the receiving view to another view's coordinate space. Both views must share a common ancestor.
 @param vector An RIPoint2F vector in the receiving view's coordinate space.
 @param view An RIView that shares a common ancestor with the receiving view.
 */
- (RIPoint2F)convertVector2F:(RIPoint2F)vector toView:(RIView *)view;

/*!
 @brief Converts a vector from another view to the receiving view.
 @details This method converts a vector from another view to the receiving view's coordinate space. Both views must share a common ancestor.
 @param vector An RIPoint2F vector in another view's coordinate space.
 @param view An RIView that shares a common ancestor with the receiving view.
 */
- (RIPoint2F)convertVector2F:(RIPoint2F)vector fromView:(RIView *)view;

/*!
 @brief Converts a vector from the receiving view to another view.
 @details This method converts a vector from the receiving view to another view's coordinate space. Both views must share a common ancestor.
 @param vector An RIPoint3F vector in the receiving view's coordinate space.
 @param view An RIView that shares a common ancestor with the receiving view.
 */
- (RIPoint3F)convertVector3F:(RIPoint3F)vector toView:(RIView *)view;

/*!
 @brief Converts a vector from another view to the receiving view.
 @details This method converts a vector from another view to the receiving view's coordinate space. Both views must share a common ancestor.
 @param vector An RIPoint3F vector in another view's coordinate space.
 @param view An RIView that shares a common ancestor with the receiving view.
 */
- (RIPoint3F)convertVector3F:(RIPoint3F)vector fromView:(RIView *)view;

@end
