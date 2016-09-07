//
//  PMDocumentCacheManager.h
//  Perform
//
//  Created by ederle on 4/8/15.
//  Copyright (c) 2015 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>

// Notifications
extern NSString * const PMDocumentCacheManagerURLAddedNotification;
extern NSString * const PMDocumentCacheManagerURLRemovedNotification;

// Notificaiton Keys
extern NSString * const PMDocumentCacheManagerURLKey;

/**
 * This class manages a collection of documents. When you add a URL
 * to the cache it makes a copy of the file and keeps track of the copy.
 * You should only ever add file URL's into the cache manager. When
 * documents are added or removed an NSNotification will be sent for
 * the corresponding event with the URL for context.
 */
@interface PMDocumentCacheManager : NSObject

// Add file URL into cache by creating a copy of it
- (BOOL)addURLToCache:(NSURL *)url;

// Remove URL from cache and delete the cached copy
- (void)removeURLFromCache:(NSURL *)url;

// Array of NSURL's for all cached documents
- (NSArray *)arrayFromCache;

@end

