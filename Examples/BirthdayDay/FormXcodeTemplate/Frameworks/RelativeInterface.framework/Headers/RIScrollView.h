//
//  RIScrollView.h
//  RelativeInterface
//
//  Created by Max Weisel on 1/16/14.
//  Copyright (c) 2014 RelativeWave. All rights reserved.
//

#import "RIView.h"
#import "RIScrollViewDelegate.h"

@interface RIScrollView : RIView

// Content
@property (nonatomic, readonly) RIView *contentView;

// Scrolling
@property (nonatomic, assign) RIPoint2F contentOffset;
@property (nonatomic, readonly) RISize2F contentSize; // contentView.size * contentView.uniformScale
@property (nonatomic, assign) BOOL scrollEnabled;
// @property (nonatomic) BOOL scrollsToTop;
@property (nonatomic, assign) float decelerationRate;

//@property (nonatomic, assign) BOOL pagingEnabled;
//@property (nonatomic, assign) BOOL bounces;
//@property (nonatomic, assign) BOOL alwaysBounceVertical;
//@property (nonatomic, assign) BOOL alwaysBounceHorizontal;

@property (nonatomic, readonly, getter = isTracking) BOOL tracking;
@property (nonatomic, readonly, getter = isDragging) BOOL dragging;
@property (nonatomic, readonly, getter = isDecelerating) BOOL decelerating;

// Indicators
// TODO: Indicators

// Zooming
@property (nonatomic, assign) float zoomScale;
@property (nonatomic, assign) float minimumZoomScale;
@property (nonatomic, assign) float maximumZoomScale;
@property (nonatomic, readonly, getter = isZooming) BOOL zooming;

// Delegate
@property (nonatomic, weak) id <RIScrollViewDelegate> delegate;

@end
