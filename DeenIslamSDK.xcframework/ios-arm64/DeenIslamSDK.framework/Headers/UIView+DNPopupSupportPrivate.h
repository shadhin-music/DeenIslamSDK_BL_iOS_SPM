//
//  UIView+DNPopupSupportPrivate.h
//  DNPopupController
//
//  Created by Léo Natan on 2020-08-01.
//  Copyright © 2015-2024 Léo Natan. All rights reserved.
//

#import <UIKit/UIKit.h>

@class DNPopupBar;
@class DNPopupController;

NS_ASSUME_NONNULL_BEGIN

typedef void (^DNInWindowBlock)(dispatch_block_t);

@interface NSObject (DNPopupSupportPrivate)

@property (nonatomic, weak, nullable, getter=_dn_attachedPopupController, setter=_dn_setAttachedPopupController:) DNPopupController* attachedPopupController;

@end

UIEdgeInsets _DNEdgeInsetsFromDirectionalEdgeInsets(UIView* forView, NSDirectionalEdgeInsets edgeInsets);

@interface UIView (DNPopupSupportPrivate)

- (void)_dn_triggerBarAppearanceRefreshIfNeededTriggeringLayout:(BOOL)layout;
- (BOOL)_dn_scrollEdgeAppearanceRequiresFadeForPopupBar:(DNPopupBar*)popupBar;

- (void)_dn_letMeKnowWhenViewInWindowHierarchy:(DNInWindowBlock)block;
- (void)_dn_forgetAboutIt;
- (nullable NSString*)_dn_effectGroupingIdentifierIfAvailable;

- (void)_dn_freezeInsets;

@end

@interface UIView ()

- (id)_dnpopup_scrollEdgeAppearance;

@end

@interface UITabBar ()

@property (nonatomic, getter=_ignoringLayoutDuringTransition, setter=_setIgnoringLayoutDuringTransition:) BOOL ignoringLayoutDuringTransition;

@end

#if TARGET_OS_MACCATALYST

@interface UIWindow (MacCatalystSupport)

@property (nonatomic, strong, readonly) UIEvent* _dn_currentEvent;

@end

#endif

NS_ASSUME_NONNULL_END

@interface UIScrollView (DNPopupSupportPrivate)

- (BOOL)_dn_hasHorizontalContent;
- (BOOL)_dn_hasVerticalContent;
- (BOOL)_dn_scrollingOnlyVertically;
- (BOOL)_dn_isAtTop;

@end
