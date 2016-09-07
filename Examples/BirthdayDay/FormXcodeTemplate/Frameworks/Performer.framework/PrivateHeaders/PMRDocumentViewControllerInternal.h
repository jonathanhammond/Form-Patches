//
//  PMRDocumentViewControllerInternal.h
//  Performer
//
//  Created by ederle on 4/14/15.
//  Copyright (c) 2015 Relative Wave. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PMRemoteConnection.h"

// This category exposes some private features for configuring the document view controller
@interface PMRDocumentViewController (Internal)

// Allows the PMDocumentConnectionManager to hand off an open server connection
- (void)setConnection:(id<PMRemoteConnection>)connection;

@end

