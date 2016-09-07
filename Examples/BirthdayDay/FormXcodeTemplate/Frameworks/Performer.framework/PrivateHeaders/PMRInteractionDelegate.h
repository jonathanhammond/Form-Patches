//
//  PMRInteractionDelegate.h
//  Performer
//
//  Created by Max Weisel on 6/30/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol PMRInteractionDelegate <NSObject>

@required;
- (void)touchesBegan:(NSSet *)touches inView:(RIView *)view;
- (void)touchesMoved:(NSSet *)touches inView:(RIView *)view;
- (void)touchesEnded:(NSSet *)touches inView:(RIView *)view;
- (void)touchesCancelled:(NSSet *)touches inView:(RIView *)view;

@end
