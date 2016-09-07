//
//  RICollectionViewListLayout.h
//  RelativeInterface
//
//  Created by Max Weisel on 9/12/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

#import "RICollectionViewLayout.h"
#import "RICollectionViewDelegateListLayout.h"

/*!
 The RICollectionViewListLayout class is an RICollectionViewLayout subclass that functions as a vertical scrolling list of items. (Similar to Apple's UITableView).
 */

@interface RICollectionViewListLayout : RICollectionViewLayout

///---------------------------------------------------------------------------------------
/// @name Layout
///---------------------------------------------------------------------------------------

/*!
 @brief A float value that represents the height of each item in the list.
 @details This value is used to size each RICollectionViewItem. The width of each item is automatically set to the width of the content view.
 */
@property (nonatomic, assign) float itemHeight;

@end
