//
//  PMErrorMessage.h
//  Performer
//
//  Created by ederle on 4/22/15.
//  Copyright (c) 2015 Relative Wave. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PMErrorMessage : NSObject

// Show an alert to the user when a document is invalid
+ (void)showAlertForInvalidDocumentWithError:(NSError *)error
                    presentingViewController:(UIViewController *)presentingViewController;

@end
