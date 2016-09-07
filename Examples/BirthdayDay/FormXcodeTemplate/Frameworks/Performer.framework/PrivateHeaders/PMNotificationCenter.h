//
//  PMNotificationCenter.h
//  Performer
//
//  Created by osbornc on 5/19/15.
//  Copyright (c) 2015 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PMNotificationCenter : NSObject

+ (PMNotificationCenter *)defaultCenter;

- (void)addObserver:(id)observer selector:(SEL)selector name:(NSString *)name;

- (void)removeObserver:(id)observer name:(NSString *)name;

- (void)postNotification:(NSNotification *)notification;
- (void)postNotificationName:(NSString *)name;
- (void)postNotificationName:(NSString *)name userInfo:(NSDictionary *)userInfo;

@end
