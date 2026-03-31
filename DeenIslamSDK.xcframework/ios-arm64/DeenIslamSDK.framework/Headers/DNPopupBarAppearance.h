//
//  DNPopupBarAppearance.h
//  DNPopupController
//
//  Created by Léo Natan on 2021-06-20.
//  Copyright © 2015-2024 Léo Natan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DNPopupDefinitions.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_UI_ACTOR
/// An object for customizing the appearance of popup bars.
///
/// After creating a `DNPopupBarAppearance` object, use the methods and properties of this class to specify the appearance of items in the popup bar. Use the inherited properties from `UIBarAppearance` to configure the background and shadow attributes of the popup bar itself.
@interface DNPopupBarAppearance : UIBarAppearance

/// Display attributes for the popup bar’s title text.
///
/// You may specify the font, text color, and shadow properties for the title in the text attributes dictionary, using the keys found in `NSAttributedString.h`.
@property (nullable, nonatomic, copy) NSDictionary<NSAttributedStringKey, id>* dntitleTextAttributes NS_REFINED_FOR_SWIFT;

/// Display attributes for the popup bar’s subtitle text.
///
/// You may specify the font, text color, and shadow properties for the title in the text attributes dictionary, using the keys found in `NSAttributedString.h`.
@property (nullable, nonatomic, copy) NSDictionary<NSAttributedStringKey, id>* dnsubtitleTextAttributes NS_REFINED_FOR_SWIFT;

/// The appearance for plain-style bar button items.
@property (nonatomic, readwrite, copy) UIBarButtonItemAppearance* dnbuttonAppearance;

/// The appearance for done-style bar button items.
@property (nonatomic, readwrite, copy) UIBarButtonItemAppearance* dndoneButtonAppearance;

/// The color to apply for the bar's highlight.
@property (nonatomic, copy) UIColor* dnhighlightColor;

/// Configures the popup bar with the default highlight color.
- (void)dnconfigureWithDefaultHighlightColor;

/// When enabled, titles and subtitles that are longer than the space available will scroll text over time.
///
/// Defaults to `false`.
@property (nonatomic, assign) BOOL dnmarqueeScrollEnabled;

/// The scroll rate, in points, of the title and subtitle marquee animation.
///
/// Defaults to `30`.
@property (nonatomic, assign) CGFloat dnmarqueeScrollRate;

/// The delay, in seconds, before starting the title and subtitle marquee animation.
///
/// Defaults to `2`.
@property (nonatomic, assign) NSTimeInterval dnmarqueeScrollDelay;

/// When enabled, the title and subtitle marquee scroll animations will be coordinated.
///
/// If either the title or subtitle of the current popup item change, the animation will reset so the two can scroll together.
///
/// Defaults to `true`.
@property (nonatomic, assign) BOOL dncoordinateMarqueeScroll;

/// Configures the popup bar with marquee scroll enabled and sets the default marquee scroll configuration values.
- (void)dnconfigureWithDefaultMarqueeScroll;

/// Configures the popup bar with marquee scroll disabled.
- (void)dnconfigureWithDisabledMarqueeScroll;

/// The shadow displayed underneath the popup bar image view.
@property (nonatomic, copy, nullable) NSShadow* dnimageShadow;

- (void)dnconfigureWithDefaultImageShadow;
- (void)dnconfigureWithStaticImageShadow;
- (void)dnconfigureWithNoImageShadow;

/// A specific blur effect to use for the bar floating background. This effect is composited first when constructing the bar's floating background.
@property (nonatomic, copy, nullable) UIBlurEffect* dnfloatingBackgroundEffect;

/// A color to use for the bar floating background. This color is composited over `floatingBackgroundEffect`.
@property (nonatomic, copy, nullable) UIColor* dnfloatingBackgroundColor;

/// An image to use for the bar floating background. This image is composited over the `floatingBackgroundColor`, and resized per the `floatingBackgroundImageContentMode`.
@property (nonatomic, strong, nullable) UIImage* dnfloatingBackgroundImage;

/// The content mode to use when rendering the `floatingBackgroundImage`. Defaults to `UIViewContentModeScaleToFill`. `UIViewContentModeRedraw` will be reinterpreted as `UIViewContentModeScaleToFill`.
@property (nonatomic, assign) UIViewContentMode dnfloatingBackgroundImageContentMode;

/// The shadow displayed underneath the bar floating background.
@property (nonatomic, copy, nullable) NSShadow* dnfloatingBarBackgroundShadow;

/// Reset floating background and shadow properties to their defaults.
- (void)dnconfigureWithDefaultFloatingBackground;

/// Reset floating background and shadow properties to display theme-appropriate opaque colors.
- (void)dnconfigureWithOpaqueFloatingBackground;

/// Reset floating background and shadow properties to be transparent.
- (void)dnconfigureWithTransparentFloatingBackground;

@end

NS_ASSUME_NONNULL_END
