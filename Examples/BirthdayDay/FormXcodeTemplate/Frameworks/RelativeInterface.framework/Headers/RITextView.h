//
//  RITextView.h
//  RelativeInterface
//
//  Created by Max Weisel on 12/14/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

#import "RIView.h"

// Color Types
#import "RIColorTypes.h"

typedef enum {
    RITextAlignmentLeft = 0,
    RITextAlignmentRight,
    RITextAlignmentCenter,
} RITextAlignment;

/*!
 The RITextView class displays text on screen.
 
 An RITextView instance bears many similarities in purpose to UILabel.
 */

@interface RITextView : RIView

+ (NSAttributedString *)attributedStringWithString:(NSString *)string
                                          fontName:(NSString *)fontName
                                              size:(float)size
                                             color:(RIColorRGBA)color
                                         alignment:(RITextAlignment)alignment
                                        shouldClip:(BOOL)shouldClip;

///---------------------------------------------------------------------------------------
/// @name Setting Text
///---------------------------------------------------------------------------------------

/*!
 @brief The attributed string to display
 @details The text property is an NSAttributedString. All text formatting can be added via the NSAttributedString.
 
 If the size property is not set, no text will be drawn.
 @note The string is rendered via CoreText into the view's drawing rectangle. When setting string attributes, use the attributes from CoreText. (ie kCTForegroundColorAttributeName instead of NSForegroundColorAttributeName)
 */
@property (nonatomic, copy) NSAttributedString *text;

/*!
 @brief The scale factor of the backing texture of the text view.
 @details When drawing a text view, sometimes it is desirable to scale it up or bring it forward in z-space. This property tells the RITextView to increase the resolution of the backing texture in order to prevent text from becoming fuzzy.
 
 The default value is 1.0.
 @note This property will be removed in the future in favor of a proper mipmap based solution.
 */
@property (nonatomic, assign) float textureScaleFactor;

// TODO: Add nice text property methods like UILabel. Allow attributed string for developers who want more control.

@end
