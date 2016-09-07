//
//  PMRDocumentDelegate.h
//  Performer
//
//  Created by Max Weisel on 2/18/15.
//  Copyright (c) 2015 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PMRDocument;

@protocol PMRDocumentDelegate <NSObject>

@required
- (void)documentWillProcessGraph:(PMRDocument *)document;
- (void)documentDidProcessGraph:(PMRDocument *)document frameTime:(double)frameTime processingTime:(double)processingTime;

@end