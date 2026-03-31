//
//  DNPopupBar.h
//  DNPopupController
//
//  Created by Léo Natan on 2015-08-23.
//  Copyright © 2015-2024 Léo Natan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DNPopupDefinitions.h"
#import "DNPopupItem.h"
#import "DNPopupCustomBarViewController.h"
#import "DNPopupBarAppearance.h"

#define DN_UNAVAILABLE_PREVIEWING_MSG "Add context menu interaction or register for previewing directly on the popup bar view."

NS_ASSUME_NONNULL_BEGIN

/// Available styles for the popup bar.
typedef NS_ENUM(NSInteger, DNPopupBarStyle) {
	/// The default bar style for the current environment.
	DNPopupBarStyleDefault,
	
	/// Compact bar style.
	DNPopupBarStyleCompact,
	
	/// Prominent bar style.
	DNPopupBarStyleProminent,
	
	/// Floating bar style.
	DNPopupBarStyleFloating,
	
	/// Custom bar style.
	///
	/// Do not set this style directly. Instead, set the `DNPopupBar.customBarViewController` property and the framework will use this style.
	DNPopupBarStyleCustom = 0xFFFF
} NS_SWIFT_NAME(DNPopupBar.Style);

/// Available styles for the popup bar progress view.
typedef NS_ENUM(NSInteger, DNPopupBarProgressViewStyle) {
	/// Use the most appropriate style for the current operating system version.
	DNPopupBarProgressViewStyleDefault,
	
	/// Progress view on bottom
	DNPopupBarProgressViewStyleBottom,
	
	/// Progress view on bottom
    DNPopupBarProgressViewStyleTop,
	
	/// No progress view
	DNPopupBarProgressViewStyleNone = 0xFFFF
} NS_SWIFT_NAME(DNPopupBar.ProgressViewStyle);

NS_SWIFT_UI_ACTOR
/// A popup bar is a control that displays popup information. Content is populated from ``DNPopupItem`` items.
@interface DNPopupBar : UIView <UIAppearanceContainer>

/// If `true`, the popup bar will automatically inherit its appearance from the bottom docking view.
@property (nonatomic, assign) BOOL inheritsAppearanceFromDockingView UI_APPEARANCE_SELECTOR;

/// The currently displayed popup item. (read-only)
@property (nullable, nonatomic, weak, readonly) DNPopupItem* dnpopupItem;

/// An array of custom bar button items. (read-only)
///
/// For compact popup bars, this property is equivalent to `trailingBarButtonItems`.
@property (nullable, nonatomic, copy, readonly) NSArray<UIBarButtonItem*>* dnbarButtonItems;

/// An array of custom bar button items to display on the left side. (read-only)
@property (nullable, nonatomic, copy, readonly) NSArray<UIBarButtonItem*>* dnleadingBarButtonItems;

/// An array of custom bar button items to display on the right side. (read-only)
@property (nullable, nonatomic, copy, readonly) NSArray<UIBarButtonItem*>* dntrailingBarButtonItems;

/// An image view displayed when the bar style is prominent. (read-only)
@property (nonatomic, strong, readonly) UIImageView* dnimageView;

/// The popup bar style.
@property (nonatomic, assign) DNPopupBarStyle dnbarStyle UI_APPEARANCE_SELECTOR;

/// The effective popup bar style used by the system. (read-only)
///
/// Use this property's value to determine, at runtime, what the result of `DNPopupBarStyleDefault` is.
@property (nonatomic, assign, readonly) DNPopupBarStyle dneffectiveBarStyle;

/// In wide enough environments, such as iPadOS, limit the width of content of floating bars to a system-determined value.
///
/// Defaults to `true`.
@property (nonatomic, assign) BOOL dnlimitFloatingContentWidth;

/// Describes the appearance attributes for the popup bar to use.
@property (nonatomic, copy, null_resettable) DNPopupBarAppearance* standardAppearance UI_APPEARANCE_SELECTOR;

/// The popup bar's progress view style.
@property (nonatomic, assign) DNPopupBarProgressViewStyle dnprogressViewStyle UI_APPEARANCE_SELECTOR;

/// The progress view displayed on the popup bar. (read-only)
@property (nonatomic, strong, readonly) UIProgressView* dnprogressView;

/// A semantic description of the bar items, used to determine the order of bar items when switching between left-to-right and right-to-left layouts.
///
/// Defaults to `UISemanticContentAttributePlayback`.
///
/// See also `UIView.semanticContentAttribute`
@property (nonatomic) UISemanticContentAttribute dnbarItemsSemanticContentAttribute;

/// The gesture recognizer responsible for opening the popup when the user taps on the popup bar. (read-only)
@property (nonatomic, strong, readonly) UITapGestureRecognizer* dnpopupOpenGestureRecognizer;

/// The gesture recognizer responsible for highlighting the popup bar when the user touches on the popup bar. (read-only)
@property (nonatomic, strong, readonly) UILongPressGestureRecognizer* dnbarHighlightGestureRecognizer;

/// Set this property to an ``DNPopupCustomBarViewController`` subclass object to provide a popup bar with custom content.
@property (nullable, nonatomic, strong) __kindof DNPopupCustomBarViewController* dncustomBarViewController;

@end

#pragma mark Deprecations

extern const UIBlurEffectStyle DNBackgroundStyleInherit DN_UNAVAILABLE_API("Use DNPopupBarAppearance instead.");

@interface DNPopupBar (Deprecated)

/// If `true`, the popup bar will automatically inherit its style from the bottom docking view.
@property (nonatomic, assign) BOOL inheritsVisualStyleFromDockingView DN_UNAVAILABLE_API("Use inheritsAppearanceFromDockingView instead.");

/// The popup bar background style that specifies its appearance.
///
/// Use `DNBackgroundStyleInherit` value to inherit the docking view's bar style if possible, or use a system default.
///
/// Defaults to `DNBackgroundStyleInherit`.
@property (nonatomic, assign) UIBlurEffectStyle backgroundStyle DN_UNAVAILABLE_API("Use DNPopupBarAppearance.backgroundEffect instead.");

/// The tint color to apply to the popup bar background.
@property (nullable, nonatomic, strong) UIColor* barTintColor DN_UNAVAILABLE_API("Use DNPopupBarAppearance.backgroundColor instead.");

/// A Boolean value that indicates whether the popup bar is translucent (`true`) or not (`false`).
@property(nonatomic, assign, getter=isTranslucent) BOOL translucent DN_UNAVAILABLE_API("Use DNPopupBarAppearance.configureWithOpaqueBackground() instead.");

/// Display attributes for the popup bar’s title text.
///
/// You may specify the font, text color, and shadow properties for the title in the text attributes dictionary, using the keys found in `NSAttributedString.h`.
@property (nullable, nonatomic, copy) NSDictionary<NSAttributedStringKey, id>* titleTextAttributes DN_UNAVAILABLE_API("Use DNPopupBarAppearance.titleTextAttributes instead.");

/// Display attributes for the popup bar’s subtitle text.
///
/// You may specify the font, text color, and shadow properties for the title in the text attributes dictionary, using the keys found in `NSAttributedString.h`.
@property (nullable, nonatomic, copy) NSDictionary<NSAttributedStringKey, id>* subtitleTextAttributes DN_UNAVAILABLE_API("Use DNPopupBarAppearance.subtitleTextAttributes instead.");

/// When enabled, titles and subtitles that are longer than the space available will scroll text over time.
///
/// Defaults to `false`.
@property (nonatomic, assign) BOOL marqueeScrollEnabled DN_UNAVAILABLE_API("Use DNPopupBarAppearance.marqueeScrollEnabled instead.");

/// The scroll rate, in points, of the title and subtitle marquee animation.
///
/// Defaults to `30`.
@property (nonatomic, assign) CGFloat marqueeScrollRate DN_UNAVAILABLE_API("Use DNPopupBarAppearance.marqueeScrollRate instead.");

/// The delay, in seconds, before starting the title and subtitle marquee animation.
///
/// Defaults to `2`.
@property (nonatomic, assign) NSTimeInterval marqueeScrollDelay DN_UNAVAILABLE_API("Use DNPopupBarAppearance.marqueeScrollDelay instead.");

/// When enabled, the title and subtitle marquee scroll animations will be coordinated.
///
/// If either the title or subtitle of the current popup item change, the animation will reset so the two can scroll together.
///
/// Defaults to `true`.
@property (nonatomic, assign) BOOL coordinateMarqueeScroll DN_UNAVAILABLE_API("Use DNPopupBarAppearance.coordinateMarqueeScroll instead.");

/// An array of custom bar button items to display on the left side. (read-only)
@property (nullable, nonatomic, copy, readonly) NSArray<UIBarButtonItem*>* leftBarButtonItems DN_UNAVAILABLE_API("Use leadingBarButtonItems instead.");

/// An array of custom bar button items to display on the right side. (read-only)
@property (nullable, nonatomic, copy, readonly) NSArray<UIBarButtonItem*>* rightBarButtonItems DN_UNAVAILABLE_API("Use barButtonItems or trailingBarButtonItems instead.");

@end

NS_ASSUME_NONNULL_END
