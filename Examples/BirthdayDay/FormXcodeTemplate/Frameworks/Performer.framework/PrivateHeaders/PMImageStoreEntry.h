//
//  PMImageStoreEntry.h
//  Performer
//
//  Created by Max Weisel on 4/2/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PMImageStoreEntry : NSObject <NSCoding>

@property (nonatomic, readonly) NSString *imagePath;
@property (nonatomic, readonly) NSString *key;

- (RIImage *)imageForScale:(float)scale;
- (void)flushImage;

@end
