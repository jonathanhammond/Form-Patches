//
//  RIImageProcessor.h
//  RelativeInterface
//
//  Created by Max Weisel on 5/6/14.
//  Copyright (c) 2014 RelativeWave. All rights reserved.
//

// External
#import <Foundation/Foundation.h>

// Filter
#import "RIFilter.h"

// Image
#import "RIImage.h"

@interface RIImageProcessor : NSObject

@property (nonatomic, strong) RIFilter *filter;
@property (nonatomic, strong) RIImage *sourceImage;

// This is only a hint to tell the image processor you might not need an image at full resolution.
@property (nonatomic, assign) RISize2F destinationSize;

- (RIImage *)filterImage;
- (RIImage *)filterImageWithoutFinalPass;

@end
