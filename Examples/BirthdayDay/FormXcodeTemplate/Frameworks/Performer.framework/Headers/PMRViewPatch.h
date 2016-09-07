//
//  PMRViewPatch.h
//  Performer
//
//  Created by Max Weisel on 6/25/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMRPatch.h"

@class RIView;

/*!
 The PMRViewPatch class represents a patch in Form's viewer.
 
 When creating a custom view patch in Form, you should always subclass this patch class. In addition to performing the same responsibilities as a normal PMRPatch, Form recognizes this patch as a view and allows users to add subviews to it.
 */
@interface PMRViewPatch : PMRPatch

///---------------------------------------------------------------------------------------
/// @name Specifying a view class
///---------------------------------------------------------------------------------------

/*!
 @brief This method is called by PMRViewPatch in order to get the class of the view to instantiate.
 @details Override this method to in order to provide your custom RIView subclass. When this patch is instantiated by the runtime, a new instance of this view class will be created and stored in the view property.
 
 The default implementation will automatically return the RIView class.
 */
+ (Class)viewClass;

/*!
 @brief The view for the patch.
 @details This property represents the view for this patch. Its position and orientation will automatically be set by PMRViewPatch.
 */
@property (nonatomic, readonly) RIView *view;

/*!
 @brief The stencil view for the patch.
 @details In order to support certain rendering features, PMRViewPatch may reset the stencil view property its view. Use this property to provide Form with a custom stencil view.
 */
@property (nonatomic, readonly) RIView *stencilView;

@end
