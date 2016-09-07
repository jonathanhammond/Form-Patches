//
//  RelativeInterface.h
//  RelativeInterface
//
//  Created by Max Weisel on 11/15/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

// Utility
#import "RIFunctions.h"

// Geometry
#import "RIGeometry.h"

// Color
#import "RIColor.h"

// Rendering
#import "RIRenderTypes.h"
#import "RIRenderContext.h"
#import "RIRenderSurface.h"
#import "RIRenderSurfaceBuffer.h"
#import "RIImageRenderSurfaceBuffer.h"

#import "RIShader.h"
#import "RIShaderCache.h"

// Application
#import "RIApplication.h"

// Images
#import "RIImage.h"
#import "RIMutableImage.h"
#import "RIImageCache.h"

// Filters
#import "RIFilter.h"
#import "RIFilterSubclass.h"
#import "RIFilterShader.h"
#import "RIImageProcessor.h"
#import "RIClearFilter.h"
#import "RISinglePassFilter.h"
#import "RICombinationFilter.h"
#import "RIInvertFilter.h"
#import "RIBlurFilter.h"

// Animation
#import "RIAnimationClock.h"

// Views
#import "RIView.h"
#import "RIWindow.h"
#import "RIColorView.h"
#import "RIImageView.h"
#import "RITextView.h"
#import "RIScrollView.h"
#import "RIBridgeView.h"
#import "RIFilterView.h"
#import "RICoreGraphicsView.h"

#if TARGET_OS_IPHONE // TODO: Remove this once this works on mac

#  import "RICollectionView.h"
#  import "RICollectionViewItem.h"
#  import "RICollectionViewItemIndex.h"
#  import "RICollectionViewLayout.h"
#  import "RICollectionViewLayoutItem.h"
#  import "RICollectionViewListLayout.h"
#  import "RICollectionViewDelegateListLayout.h"
#  import "RICollectionViewFlowLayout.h"

#endif

// Interaction
#import "RIInteraction.h"

// Touches
#import "RITouch.h"
#import "RIGestureRecognizer.h"
#import "RIGestureRecognizerSubclass.h"
#import "RIPanGestureRecognizer.h"
#import "RIPinchGestureRecognizer.h"
#import "RIRotationGestureRecognizer.h"

#if TARGET_OS_IPHONE

#   import "RITouchDispatcher.h"
#   import "RIControl.h"
#   import "RIButton.h"

#elif TARGET_OS_MAC

#   import "RIMouseToTouchDispatcher.h"
#   import "RIMouse.h"

#endif
