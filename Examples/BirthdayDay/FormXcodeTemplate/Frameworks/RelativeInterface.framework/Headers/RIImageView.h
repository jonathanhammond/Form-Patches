//
//  RIImageView.h
//  RelativeInterface
//
//  Created by Max Weisel on 12/12/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

#import "RIView.h"
#import "RIFilterObserver.h"

@class RIImage;
@class RIFilter;

/*!
 The RIImageView class is used to display an image on screen.
 */

@interface RIImageView : RIView <RIFilterObserver>

///---------------------------------------------------------------------------------------
/// @name Creating an image view
///---------------------------------------------------------------------------------------

/*!
 @brief Create an image view from an RIImage.
 @details This method initializes an RIImageView based on an RIImage.
 
 The size of the image view will be set automatically based on the RIImage.
 @param image The RIImage used to initialize the view.
 */
- (id)initWithImage:(RIImage *)image;


///---------------------------------------------------------------------------------------
/// @name Accessing the image
///---------------------------------------------------------------------------------------

/*!
 @brief The RIImage object.
 @details This property represents the image that will be drawn in the view.
 */
@property (nonatomic, strong) RIImage *image;


///---------------------------------------------------------------------------------------
/// @name Drawing
///---------------------------------------------------------------------------------------

/*!
 @brief The filter used to draw the image.
 @details This property holds an RIFilter that is used to draw the image.
 
 The default value of this property is nil.
 */
@property (nonatomic, strong) RIFilter *filter;

@end
