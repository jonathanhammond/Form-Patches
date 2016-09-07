//
//  RIBridgeView.h
//  RelativeInterface
//
//  Created by Max Weisel on 1/16/14.
//  Copyright (c) 2014 RelativeWave. All rights reserved.
//

#import "RIView.h"

// External
#import "RIPlatform.h"
#import RIExternalFramework(RISystemUIFramework, RISystemView.h)

/*!
 The RIBridgeView class is used to display a UIView inside of RelativeInterface.
 
 The bridgeView will automatically be placed as a subview of RIApplication's renderOutputView. RIBridgeView will then take care of syncing its own transformations with the UIView.
 
 Note: Bridge views cannot be occluded by anything inside of RelativeInterface because they are rendered on top of the renderOutputView.
 */

@interface RIBridgeView : RIView

/*!
 @brief A UIView that will be bridged with RelativeInterface.
 @details This property represents the UIView that will be bridged with RelativeInterface. The view's layer's transform will be synced to match the RIBridgeView's transform.
 */

@property (nonatomic, strong) RISystemView *bridgeView;

/*!
 @brief Initializes and returns a newly created bridge view.
 @details Calling this method will initialize the bridge view and automatically set its bridgeView property. The bridgeView will be placed as a subview of the application's renderView.
 @param bridgeView The UIView/NSView to bridge with RelativeInterface.
 */
- (id)initWithBridgeView:(RISystemView *)bridgeView;

@end
