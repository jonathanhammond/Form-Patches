//
//  PMRDocument.h
//  Performer
//
//  Created by Max Weisel on 9/18/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PMRDocumentDelegate.h"

@class PMGraph;
@class PMImageStore;

@interface PMRDocument : NSObject

- (instancetype)initWithDocumentName:(NSString *)documentName;
- (instancetype)initWithURL:(NSURL *)url error:(NSError **)error;

@property (nonatomic, weak) id<PMRDocumentDelegate> delegate;
@property (nonatomic, getter = isRunning) BOOL running;
@property (nonatomic, strong) PMGraph *graph;
@property (nonatomic, readonly) PMImageStore *imageStore;
@property (nonatomic, readonly) RIView *renderView;
@property (nonatomic, readonly) NSURL *url;

@end
