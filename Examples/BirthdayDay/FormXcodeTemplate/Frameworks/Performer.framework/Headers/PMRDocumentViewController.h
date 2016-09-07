//
//  PMRDocumentViewController.h
//  Performer
//
//  Created by Max Weisel on 2/18/15.
//  Copyright (c) 2015 Relative Wave. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Performer/PMDeviceServerDelegate.h>
#import <Performer/PMDocumentOptionsProtocol.h>
#import <Performer/PMPresentationController.h>

@class PMRDocument;

@protocol PMRDocumentViewControllerDelegate;

@interface PMRDocumentViewController : UIViewController

// Open a document from a URL
- (instancetype)initWithURL:(NSURL *)url error:(NSError **)error;

@property (weak, nonatomic) id<PMRDocumentViewControllerDelegate> delegate;
@property (nonatomic) PMRDocumentOptions options;

// Shows action sheet of actions that can be taken
- (void)showDocumentOptions;

// Hide any document options shown
- (void)hideDocumentOptions:(dispatch_block_t)complete;

// YES if this document is connect to a host for live editing
- (BOOL)isConnectedWithHost;

@end

/**
 * The delegate helps this view controller outsource responsibilities that are
 * outside the scope of what the viewer needs to understand such as working
 * with the presentation coordinator, document cache manager, and connection manager.
 */
@protocol PMRDocumentViewControllerDelegate <NSObject>

// Request to close the view controller safely with the document
- (void)closeDocumentViewController:(PMRDocumentViewController *)viewController;

@optional
- (void)documentViewController:(PMRDocumentViewController *)viewController addDocumentToCache:(NSURL *)docURL;

@end
