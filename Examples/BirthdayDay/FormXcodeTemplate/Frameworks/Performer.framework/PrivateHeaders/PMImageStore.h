//
//  PMImageStore.h
//  Perform
//
//  Created by Max Weisel on 4/2/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

// External
#import <Foundation/Foundation.h>

// Entry
#import "PMImageStoreEntry.h"

@interface PMImageStore : NSObject

+ (id)sharedImageStore;

- (void)addEntry:(PMImageStoreEntry *)imageStoreEntry;
- (void)removeEntryForKey:(NSString *)imageStoreEntryKey;
- (RIImage *)imageForKey:(NSString *)key withScale:(float)scale;

- (void)flushCachedImages;

@end
