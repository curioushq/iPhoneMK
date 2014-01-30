//
//  MKNumberBadgeView.h
//  
// Copyright 2009-2012 Michael F. Kamprath
// michael@claireware.com
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//
// MKNumberBadgeView
// -----------------
//
// Use this class to display a badge containing an integer value.Similar to the app icon badges that the iPhone OS permits.
//
// Notes:
//    * When creating the view, the frame used should be larger than the expected visual size of the badge view. Use the alignment 
//      property to control the horizontal placement of the badge within the view's bounds. The badge will always be vertically
//      centered for the badge itself ignoring the size fo the shadow if it is enabled.
//    * The view's background color is automatically set to clear. If you change the background color, you may get curious results.
//

#import <UIKit/UIKit.h>


typedef NS_ENUM(NSUInteger, MKBadgeAlignment)
{
    MKBadgeAlignmentCenter = 0,
    MKBadgeAlignmentTopRight,
    MKBadgeAlignmentTopLeft,
    MKBadgeAlignmentBottomLeft,
    MKBadgeAlignmentBottomRight,
    MKBadgeAlignmentLeft,
    MKBadgeAlignmentRight
};

@interface MKNumberBadgeView : UIView 
{
	NSUInteger _value;
}

/*!
 * @brief Initializes and returns newly allocated badge view object
 * with frame that fits given text.
 * @note Uses default values (pad, shadowOffset etc.) to calculate the frame.
 * @param patternText The text which must fit the frame entirely.
 * @param aFont Font for pattern text with appropriate size.
 * If aFont is nil, default font will be used (bold System font of size 16).
 * @return Initialized badge view object or nil of the object couldn't
 * be created.
 */
- (id)initWithFrameToFitText:(NSString *)patternText withFont:(UIFont *)aFont;

/*!
 * @brief Returns badge size with default values of font and pad that fits given text.
 * @param textSize Size of text that will be used to calculate the badge's bounds size.
 * @return Badge size that includes shadow offset, stroke width etc.
 */
+ (CGSize)defaultBadgeSizeForTextSize:(CGSize)textSize;

// Text format for the badge, defaults to just the number
@property (retain,nonatomic) NSString *textFormat;

// Adjustment offset for the text in the badge
@property (assign,nonatomic) CGPoint adjustOffset;

// The current value displayed in the badge. Updating the value will update the view's display
@property (assign,nonatomic) NSUInteger value;

// Indicates whether the badge view draws a dhadow or not.
@property (assign,nonatomic) BOOL shadow;

// The offset for the shadow, if there is one.
@property (assign,nonatomic) CGSize shadowOffset;

// The base color for the shadow, if there is one.
@property (retain,nonatomic) UIColor * shadowColor;

// Indicates whether the badge view should be drawn with a shine
@property (assign,nonatomic) BOOL shine;

// The font to be used for drawing the numbers. NOTE: not all fonts are created equal for this purpose.
// Only "system fonts" should be used.
@property (retain,nonatomic) UIFont* font;

// The color used for the background of the badge.
@property (retain,nonatomic) UIColor* fillColor;

// The color to be used for drawing the stroke around the badge.
@property (retain,nonatomic) UIColor* strokeColor;

// The width for the stroke around the badge.
@property (assign,nonatomic) CGFloat strokeWidth;

// The color to be used for drawing the badge's numbers.
@property (retain,nonatomic) UIColor* textColor;

// Returns the visual size of the badge for the current value. Not the same hing as the size of the view's bounds.
// The badge view bounds should be wider than space needed to draw the badge.
@property (readonly,nonatomic) CGSize badgeSize;

// The number of pixels between the number inside the badge and the stroke around the badge. This value 
// is approximate, as the font geometry might effectively slightly increase or decrease the apparent pad.
@property (nonatomic) NSUInteger pad;

// If YES, the badge will be hidden when the value is 0
@property (nonatomic) BOOL hideWhenZero;

// Defines alignment of drawn badge in frame. Default is MKBadgeAlignmentCenter.
@property (nonatomic) MKBadgeAlignment badgeAlignment;

@end
