//
//  FMKeyedArchiver.h
//  Form
//
//  Created by Chris Osborn on 7/10/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FMKeyedArchiver : NSCoder

+ (NSString *)versionKey;

+ (NSData *)archivedDataWithRootObject:(id)rootObject;
+ (BOOL)archiveRootObject:(id)rootObject toFile:(NSString *)path;

- (instancetype)initForWritingWithMutableData:(NSMutableData *)data;
- (void)finishEncoding;

- (void)setClassName:(NSString *)codedName forClass:(Class)cls;
- (NSString *)classNameForClass:(Class)cls;

@end
