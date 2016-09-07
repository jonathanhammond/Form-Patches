//
//  PMDocumentOptionsProtocol.h
//  Performer
//
//  Created by ederle on 6/10/15.
//  Copyright (c) 2015 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PMRDocument.h"

// Configure available document options and actions
typedef NS_OPTIONS(NSUInteger, PMRDocumentOptions) {
    PMRDocumentOptionsNone = 0,
    PMRDocumentOptionsSave = 1 << 0,
    PMRDocumentOptionsShare = 1 << 1,
    PMRDocumentOptionsDefault = PMRDocumentOptionsSave
};

// This protocol makes it so that the presentation controller can stay platform agnostic for document option UI's
@protocol PMDocumentOptionsProtocol <NSObject>

// set docuement for operations
- (void)setDocument:(PMRDocument *)document;

// show options
- (void)showDocumentOptions;

// hide options
- (void)hideDocumentOptions:(dispatch_block_t)completion;

@end
