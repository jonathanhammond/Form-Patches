//
//  RIScrollViewDelegate.h
//  RelativeInterface
//
//  Created by Max Weisel on 1/16/14.
//  Copyright (c) 2014 RelativeWave. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RIScrollView;

@protocol RIScrollViewDelegate <NSObject>

@optional

// Scrolling
- (void)scrollViewDidScroll:(RIScrollView *)scrollView;
- (void)scrollViewWillBeginDragging:(RIScrollView *)scrollView;
- (void)scrollViewDidEndDragging:(RIScrollView *)scrollView willDecelerate:(BOOL)willDecelerate;
- (void)scrollViewWillBeginDecelerating:(RIScrollView *)scrollView;
- (void)scrollViewDidEndDecelerating:(RIScrollView *)scrollView;

// Zooming
- (void)scrollViewDidZoom:(RIScrollView *)scrollView;
- (void)scrollViewWillBeginZooming:(RIScrollView *)scrollView;
- (void)scrollViewDidEndZooming:(RIScrollView *)scrollView scale:(float)scale;

@end
