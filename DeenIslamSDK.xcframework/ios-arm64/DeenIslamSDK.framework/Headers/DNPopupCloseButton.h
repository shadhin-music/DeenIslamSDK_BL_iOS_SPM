//
//  DNPopupCloseButton.h
//  DNPopupController
//
//  Created by Léo Natan on 2015-08-23.
//  Copyright © 2015-2024 Léo Natan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DNPopupDefinitions.h"

/// Available styles for the popup close button.
typedef NS_ENUM(NSInteger, DNPopupCloseButtonStyle) {
	/// The default close button dnstyle for the current environment.
	DNPopupCloseButtonStyleDefault,
	
	/// Round close button style.
	DNPopupCloseButtonStyleRound,
	
	/// Chevron close button style.
	DNPopupCloseButtonStyleChevron,
	
	/// Grabber close button style.
	DNPopupCloseButtonStyleGrabber,
	
	/// No close button.
	DNPopupCloseButtonStyleNone = 0xFFFF,
	
	DNPopupCloseButtonStyleFlat DN_DEPRECATED_API("Use DNPopupCloseButtonStyle.grabber instead.") = DNPopupCloseButtonStyleGrabber
} NS_SWIFT_NAME(DNPopupCloseButton.Style);

NS_ASSUME_NONNULL_BEGIN

/// The popup content close button.
NS_SWIFT_UI_ACTOR
@interface DNPopupCloseButton : UIButton <UIAppearanceContainer>

/// Gets or sets the style of the popup close button. Has the same effect as setting the `DNPopupContentView.popupCloseButtonStyle` property of the popup content view.
@property (nonatomic) DNPopupCloseButtonStyle dnstyle UI_APPEARANCE_SELECTOR;

/// The button’s background view. (read-only)
///
/// The value of this property will be `nil` if ``style`` is not set to `DNPopupCloseButtonStyleRound`.
///
/// @note Although this property is read-only, its own properties are read/write. Use these properties to configure the appearance and behavior of the button’s background view.
@property (nonatomic, strong, readonly) UIVisualEffectView* dnbackgroundView;

@end

NS_ASSUME_NONNULL_END
