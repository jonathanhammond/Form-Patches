//
//  RICollectionViewDelegate.h
//  RelativeInterface
//
//  Created by Max Weisel on 9/10/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "RIScrollViewDelegate.h"

@class RICollectionViewItemIndex;

/*!
 The RICollectionViewDelegate protocol is used to describe an object that will receive delegate information from a collection view.
 */

@protocol RICollectionViewDelegate <RIScrollViewDelegate>
// TODO: This should inherit the RIScrollViewDelegate protocol once it's written.

@optional

///---------------------------------------------------------------------------------------
/// @name Highlight
///---------------------------------------------------------------------------------------

/*!
 @brief Returns whether an RICollectionViewItem should be highlighted.
 @details This method is called by a collection view when an item is about to be highlighted.
 
 If this method is not implemented, the collection view will assume YES.
 @param collectionView The collection view sending the message.
 @param index The item index.
 */
- (BOOL)collectionView:(RICollectionView *)collectionView shouldHighlightItemAtIndex:(RICollectionViewItemIndex *)index;

/*!
 @brief Called when a collection view item has been highlighted.
 @details This method is called by a collection view when an item has been highlighted.
 @param collectionView The collection view sending the message.
 @param index The item index.
 */
- (void)collectionView:(RICollectionView *)collectionView didHighlightItemAtIndex:(RICollectionViewItemIndex *)index;

/*!
 @brief Called when a collection view item has been unhighlighted.
 @details This method is called by a collection view when an item has been unhighlighted.
 @param collectionView The collection view sending the message.
 @param index The item index.
 */
- (void)collectionView:(RICollectionView *)collectionView didUnhighlightItemAtIndex:(RICollectionViewItemIndex *)index;


///---------------------------------------------------------------------------------------
/// @name Select
///---------------------------------------------------------------------------------------

/*!
 @brief Returns whether an RICollectionViewItem should be selected.
 @details This method is called by a collection view when an item is about to be selected.
 
 If this method is not implemented, the collection view will assume YES.
 @param collectionView The collection view sending the message.
 @param index The item index.
 */
- (BOOL)collectionView:(RICollectionView *)collectionView shouldSelectItemAtIndex:(RICollectionViewItemIndex *)index;

/*!
 @brief Called when a collection view item has been selected.
 @details This method is called by a collection view when an item has been selected.
 @param collectionView The collection view sending the message.
 @param index The item index.
 */
- (void)collectionView:(RICollectionView *)collectionView didSelectItemAtIndex:(RICollectionViewItemIndex *)index;

/*!
 @brief Returns whether an RICollectionViewItem should be deselected.
 @details This method is called by a collection view when an item is tapped while it is already selected.
 
 If this method is not implemented, the collection view will assume YES.
 @param collectionView The collection view sending the message.
 @param index The item index.
 */
- (BOOL)collectionView:(RICollectionView *)collectionView shouldDeselectItemAtIndex:(RICollectionViewItemIndex *)index;

/*!
 @brief Called when a collection view item has been deselected.
 @details This method is called by a collection view when an item has been deselected.
 @param collectionView The collection view sending the message.
 @param index The item index.
 */
- (void)collectionView:(RICollectionView *)collectionView didDeselectItemAtIndex:(RICollectionViewItemIndex *)index;

@end
