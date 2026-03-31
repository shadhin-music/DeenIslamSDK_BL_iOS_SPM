//
//  DNPopupBar+Private.h
//  DNPopupController
//
//  Created by Léo Natan on 2015-08-23.
//  Copyright © 2015-2024 Léo Natan. All rights reserved.
//

#import "DNPopupBar.h"
#import "DNPopupBarAppearanceChainProxy.h"
#import "DNPopupBarAppearance+Private.h"
#import "_DNPopupBarBackgroundView.h"
#import "_DNPopupBackgroundShadowView.h"
#import "_DNPopupBarBackgroundMaskView.h"

CF_EXTERN_C_BEGIN

extern const CGFloat DNPopupBarHeightCompact;
extern const CGFloat DNPopupBarHeightProminent;
extern const CGFloat DNPopupBarHeightFloating;

extern CGFloat _DNPopupBarHeightForPopupBar(DNPopupBar* popupBar);

inline __attribute__((always_inline)) DNPopupBarStyle _DNPopupResolveBarStyleFromBarStyle(DNPopupBarStyle style)
{
	DNPopupBarStyle rv = style;
	if(rv == DNPopupBarStyleDefault)
	{
		if(@available(iOS 17, *)) {
			rv = DNPopupBarStyleFloating;
		}
		else
		{
			rv = DNPopupBarStyleProminent;
		}
	}
	return rv;
}

@protocol _DNPopupBarDelegate <NSObject>

- (void)_traitCollectionForPopupBarDidChange:(DNPopupBar*)bar;
- (void)_popupBarMetricsDidChange:(DNPopupBar*)bar;
- (void)_popupBarMetricsDidChange:(DNPopupBar*)bar shouldLayout:(BOOL)layout;
- (void)_popupBarStyleDidChange:(DNPopupBar*)bar;
- (void)_popupBar:(DNPopupBar*)bar updateCustomBarController:(DNPopupCustomBarViewController*)customController cleanup:(BOOL)cleanup;
- (void)_removeInteractionGestureForPopupBar:(DNPopupBar*)bar;

@end

@protocol _DNPopupBarSupport <NSObject>

@property (nonatomic, strong) UIColor *barTintColor;
@property (nonatomic, strong) UIBarAppearance* standardAppearance;

@end

@interface DNPopupBar () <UIPointerInteractionDelegate, _DNPopupBarAppearanceDelegate>

+ (void)setAnimatesItemSetter:(BOOL)animate;

@property (nonatomic, assign, readonly) DNPopupBarStyle resolvedStyle;

@property (nonatomic, strong) UIColor* systemTintColor;
@property (nonatomic, strong) UIColor* systemBackgroundColor;
@property (nonatomic, strong) UIBarAppearance* systemAppearance;
@property (nonatomic, readonly, strong) DNPopupBarAppearance* activeAppearance;
@property (nonatomic, readonly, strong) DNPopupBarAppearanceChainProxy* activeAppearanceChain;

- (void)_recalcActiveAppearanceChain;

@property (nonatomic, strong) UIImageView* shadowView;
@property (nonatomic, strong) UIImageView* bottomShadowView;

@property (nonatomic, weak, readwrite) DNPopupItem* dnpopupItem;

@property (nonatomic, weak) __kindof UIViewController* barContainingController;
@property (nonatomic, weak) id<_DNPopupBarDelegate> _barDelegate;

@property (nonatomic, copy) NSAttributedString* attributedTitle;
@property (nonatomic, copy) NSAttributedString* attributedSubtitle;

@property (nonatomic) NSDirectionalEdgeInsets _hackyMargins;

@property (nonatomic, strong) UIImage* image;

@property (nonatomic, strong) UIView* highlightView;
- (void)setHighlighted:(BOOL)highlighted animated:(BOOL)animated;

@property (nonatomic, strong, readwrite) UIProgressView* dnprogressView;

@property (nonatomic, strong) _DNPopupBarBackgroundView* contentView;
@property (nonatomic, strong) UIView* contentMaskView;

@property (nonatomic, strong) _DNPopupBarBackgroundView* backgroundView;
@property (nonatomic, strong) UIView* backgroundMaskView;
@property (nonatomic) BOOL wantsBackgroundCutout;
- (void)setWantsBackgroundCutout:(BOOL)wantsBackgroundCutout allowImplicitAnimations:(BOOL)allowImplicitAnimations;
@property (nonatomic, strong) _DNPopupBarBackgroundMaskView* backgroundGradientMaskView;

@property (nonatomic, strong) _DNPopupBackgroundShadowView* dnfloatingBackgroundShadowView;

@property (nonatomic, strong) NSString* effectGroupingIdentifier;
- (void)_applyGroupingIdentifierToVisualEffectView:(UIVisualEffectView*)visualEffectView;

@property (nonatomic, copy) NSString* accessibilityCenterLabel;
@property (nonatomic, copy) NSString* accessibilityCenterHint;
@property (nonatomic, copy) NSString* accessibilityImageLabel;
@property (nonatomic, copy) NSString* accessibilityProgressLabel;
@property (nonatomic, copy) NSString* accessibilityProgressValue;

@property (nonatomic, copy, readwrite) NSArray<UIBarButtonItem*>* dnleadingBarButtonItems;
@property (nonatomic, copy, readwrite) NSArray<UIBarButtonItem*>* dntrailingBarButtonItems;

@property (nonatomic, strong, readwrite) UITapGestureRecognizer* dnpopupOpenGestureRecognizer;
@property (nonatomic, strong, readwrite) UILongPressGestureRecognizer* dnbarHighlightGestureRecognizer;
- (void)_cancelGestureRecognizers;

@property (nonatomic) BOOL acceptsSizing;

@property (nonatomic) BOOL _applySwiftUILayoutFixes;

@property (nonatomic, strong) UIFont* swiftuiInheritedFont;

@property (nonatomic, strong) UIView* swiftuiTitleContentView;

@property (nonatomic, strong) UIViewController* swiftuiImageController;
@property (nonatomic, strong) UIViewController* swiftuiHiddenLeadingController;
@property (nonatomic, strong) UIViewController* swiftuiHiddenTrailingController;

- (void)_delayBarButtonLayout;
- (void)_layoutBarButtonItems;

- (void)_setTitleViewMarqueesPaused:(BOOL)paused;

- (void)_transitionCustomBarViewControllerWithPopupContainerSize:(CGSize)size withCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator;
- (void)_transitionCustomBarViewControllerWithPopupContainerTraitCollection:(UITraitCollection *)newCollection withCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator;

- (void)_cancelAnyUserInteraction;

- (BOOL)isWidePad;

@end

CF_EXTERN_C_END
