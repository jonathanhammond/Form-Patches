//
//  RIFilterObserver.h
//  RelativeInterface
//
//  Created by vector on 8/28/15.
//  Copyright (c) 2015 Google, Inc. All rights reserved.
//

@class RIFilter;

@protocol RIFilterObserver

- (void)filterDidChange:(RIFilter *)filter;

@end
