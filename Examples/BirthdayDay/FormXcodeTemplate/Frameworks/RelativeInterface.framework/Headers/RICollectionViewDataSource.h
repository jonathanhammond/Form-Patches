//
//  RICollectionViewDataSource.h
//  RelativeInterface
//
//  Created by Max Weisel on 9/10/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RICollectionView;
@class RICollectionViewItem;
@class RICollectionViewItemIndex;

/*!
 The RICollectionViewDataSource protocol is used to describe an object that will provide the data for the collection view to display.
 */

@protocol RICollectionViewDataSource <NSObject>

///---------------------------------------------------------------------------------------
/// @name Info
///---------------------------------------------------------------------------------------

/*!
 @brief Returns the number of sections to display in the collection view.
 @details This method is called by a collection view to retrieve the number of sections to display.
 @param collectionView The collection view requesting data.
 */
- (int)numberOfSectionsInCollectionView:(RICollectionView *)collectionView;

/*!
 @brief Returns the number of rows to display for a particular section.
 @details This method is called by a collection view to retrieve the number of rows to display in the collection view for a particular section.
 @param collectionView The collection view requesting data.
 @param section The index of the section.
 */
- (int)collectionView:(RICollectionView *)collectionView numberOfItemsInSection:(int)section;


///---------------------------------------------------------------------------------------
/// @name Items
///---------------------------------------------------------------------------------------

/*!
 @brief Returns an item for a particular item index.
 @details This method is called by a collection view to retrieve an RICollectionViewItem for a particular RICollectionViewItemIndex
 @param collectionView The collection view requesting data.
 @param itemIndex The item index.
 */
- (RICollectionViewItem *)collectionView:(RICollectionView *)collectionView itemAtIndex:(RICollectionViewItemIndex *)itemIndex;

@end
