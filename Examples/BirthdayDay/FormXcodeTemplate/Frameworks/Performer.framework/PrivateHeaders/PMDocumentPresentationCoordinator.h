//
//  PMDocumentPresentationCoordinator.h
//  Perform
//
//  Created by ederle on 4/8/15.
//  Copyright (c) 2015 Relative Wave. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PMRDocumentViewController;

typedef void (^PMCloseDocumentHandler)(BOOL  didClose);

// Tracks if a form document is being presented or not
typedef NS_ENUM(NSInteger, PMDocumentViewState) {
    PMDocumentViewStateNotPresenting,    // No document is being shown
    PMDocumentViewStatePresenting        // Form document view controller is modal
};

/**
 * This class manages presenting a form document and making sure that
 * only 1 presentation can be shown at a time.
 */
@interface PMDocumentPresentationCoordinator : NSObject

- (id)initWithWindow:(UIWindow *)window;

@property (readonly, nonatomic) PMDocumentViewState viewState;
@property (readonly, nonatomic) PMRDocumentViewController *documentViewController;

// Present document view controller
- (void)openDocumentWithViewController:(PMRDocumentViewController *)viewController
                               animate:(BOOL)shouldAnimate
                               handler:(dispatch_block_t)completionHandler;

// Close currently presented document view controller
- (void)closeDocumentWithAnimation:(BOOL)shouldAnimate
                           handler:(PMCloseDocumentHandler)completionHandler;

@end
