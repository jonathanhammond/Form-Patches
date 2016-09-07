//
//  PMPresentationController.h
//  Performer
//
//  Created by ederle on 6/10/15.
//  Copyright (c) 2015 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PMRDocument.h"
#import "PMDocumentOptionsProtocol.h"
#import "PMRemoteConnection.h"

extern NSString *const PMRDocumentViewControllerDidBeginSizeTransitionNotification;
extern NSString *const PMRDocumentViewControllerDidEndSizeTransitionNotification;
extern NSString *const PMRDocumentViewControllerShouldUpdateSupportedInterfaceOrientationsNotification;

@class RIApplication;

@protocol PMPresentationControllerDelegate;

/**
 * This controller is manages rendering and managment
 * of the document graph. This controller manages inbound
 * connection messages, RIApplication instance, and document.
 * This controller should be platform independent.
 */
@interface PMPresentationController : NSObject

@property (weak, nonatomic) id<PMPresentationControllerDelegate> delegate;
@property (readonly, nonatomic) PMRDocument *document;
@property (readonly, nonatomic) RIApplication *application;
@property (strong, nonatomic) id<PMRemoteConnection> connection;

// Open a document from a URL
- (instancetype)initWithURL:(NSURL *)url error:(NSError **)error;

// Request that a save message is sent to host and ask delegate to close when complete
- (void)saveAndClosePresentation;

// TODO - This is a bandaid to fix an order of operations problem where the RIClock is nil at init time
- (void)startRendering;

@end

@protocol PMPresentationControllerDelegate <NSObject>

// Request to close the view controller safely with the document
- (void)closePresentationController:(PMPresentationController *)viewController;

// Request that document get saved into cache
@optional
- (void)presentationController:(PMPresentationController *)presentationController addDocumentToCache:(NSURL *)docURL;

@end
