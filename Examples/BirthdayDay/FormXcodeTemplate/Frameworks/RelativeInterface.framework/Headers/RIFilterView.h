//
//  RIFilterView.h
//  RelativeInterface
//
//  Created by Max Weisel on 12/15/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

#import "RIView.h"

// Mutable Image
#import "RIMutableImage.h"

// Filter
#import "RIFilter.h"

/*!
 The RIFilterView class is used to filter a collection of subviews. The filter view renders its subviews into its mutable image each frame just before -draw is called.
 
 RIFilterView automatically matches its perspective when rendering based on its position in 3D space. Thus, the resulting image's contents appear to be viewed from the same perspective as if they were subviews of a vanilla RIVIew.
 */

@interface RIFilterView : RIView <RIFilterObserver>

///---------------------------------------------------------------------------------------
/// @name Drawing
///---------------------------------------------------------------------------------------

/*!
 @brief The filter used to draw the image.
 @details This property holds an RIFilter that is used to draw the filter view's contents.
 
 The default value of this property is nil.
 */
@property (nonatomic, strong) RIFilter *filter;

// TODO: Add the ability to lock the size of the RIMutableImage instead of unprojecting the filter view's quad.

@end
