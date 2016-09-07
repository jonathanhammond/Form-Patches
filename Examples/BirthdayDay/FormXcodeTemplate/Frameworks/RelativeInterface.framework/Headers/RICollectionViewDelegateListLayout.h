//
//  RICollectionViewDelegateListLayout.h
//  RelativeInterface
//
//  Created by Max Weisel on 9/26/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

#import "RICollectionViewDelegate.h"

@class RICollectionView;
@class RICollectionViewListLayout;
@class RICollectionViewItemIndex;

/*!
 The RICollectionViewDelegateListLayout protocol is used to describe an object that will receive delegate information from a collection view's list layout.
 */

@protocol RICollectionViewDelegateListLayout <RICollectionViewDelegate>

@optional

/*!
 @brief Returns the height for the specified collection view item index.
 @details This method is called by an RICollectionViewListLayout to retrieve the height for a specific item index. If this method is not implemented, the value of the itemHeight property of the list layout will be used.
 @param collectionView The collection view.
 @param layout The list layout.
 @param itemIndex The index of the item.
 */
- (float)collectionView:(RICollectionView *)collectionView layout:(RICollectionViewListLayout *)layout heightForItemAtIndex:(RICollectionViewItemIndex *)itemIndex;

@end
