//
//  FMKeyedUnarchiver.h
//  Form
//
//  Created by Chris Osborn on 7/10/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMKeyedUnarchiverDelegate.h"

@interface FMKeyedUnarchiver : NSCoder

+ (id)unarchiveObjectWithData:(NSData *)data;
+ (id)unarchiveObjectWithFile:(NSString *)path;

- (instancetype)initForReadingWithData:(NSData *)data NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
- (id)decodeRootObject;
- (void)finishDecoding;

@property (nonatomic, weak) id<FMKeyedUnarchiverDelegate> delegate;

@end
