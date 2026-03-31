//
//  UIViewController+DNPopupSupportPrivate.h
//  DNPopupController
//
//  Created by Léo Natan on 2015-08-23.
//  Copyright © 2015-2024 Léo Natan. All rights reserved.
//

#import "UIViewController+DNPopupSupport.h"
#import "_DNPopupBarBackgroundView.h"

CF_EXTERN_C_BEGIN

@class DNPopupController;

NS_ASSUME_NONNULL_BEGIN

static inline __attribute__((always_inline)) UIEdgeInsets __DNEdgeInsetsSum(UIEdgeInsets userEdgeInsets, UIEdgeInsets popupUserEdgeInsets)
{
	UIEdgeInsets final = userEdgeInsets;
	final.bottom += popupUserEdgeInsets.bottom;
	final.top += popupUserEdgeInsets.top;
	final.left += popupUserEdgeInsets.left;
	final.right += popupUserEdgeInsets.right;
	
	return final;
}

extern BOOL __dn_popup_suppressViewControllerLifecycle;

UIEdgeInsets _DNPopupSafeAreaInsets(id self);
void _DNPopupSupportSetPopupInsetsForViewController(UIViewController* controller, BOOL layout, UIEdgeInsets popupEdgeInsets);

@interface _DNPopupBottomBarSupport : UIView @end

@interface UIViewController (DNPopupSupportPrivate)

- (void)_dn_updateSafeAreaInsets;

- (BOOL)_dn_shouldDisplayBottomShadowViewDuringTransition;

- (BOOL)_dn_reallyShouldExtendPopupBarUnderSafeArea;

- (void)_dn_setPopupPresentationState:(DNPopupPresentationState)newState;

- (nullable UIViewController*)_dn_common_childViewControllerForStatusBarStyle;
- (nullable UIPresentationController*)nonMemoryLeakingPresentationController;

@property (nonatomic, strong, readonly, getter=_dn_popupController) DNPopupController* dn_popupController;
- (DNPopupController*)_dn_popupController_nocreate;
@property (nullable, nonatomic, weak, readwrite) UIViewController* dnpopupPresentationContainerViewController;
@property (nullable, nonatomic, strong, readwrite) UIViewController* dnpopupContentViewController;

@property (nonnull, nonatomic, strong, readonly, getter=_dn_bottomBarSupport) _DNPopupBottomBarSupport* bottomBarSupport;
- (nullable _DNPopupBottomBarSupport *)_dn_bottomBarSupport_nocreate;

- (BOOL)_isContainedInPopupController;
- (BOOL)_isContainedInOpenPopupController;
- (BOOL)_isContainedInPopupControllerOrDeallocated;

- (BOOL)_ignoringLayoutDuringTransition;

- (nullable UIView *)bottomDockingViewForPopup_nocreateOrDeveloper;
- (nonnull UIView *)bottomDockingViewForPopup_internalOrDeveloper;

- (CGFloat)_dn_popupOffsetForPopupBarStyle:(DNPopupBarStyle)barStyle;

- (CGRect)defaultFrameForBottomDockingView_internal;
- (CGRect)_defaultFrameForBottomDockingViewForPopupBar:(DNPopupBar*)DNPopupBar;

- (_DNPopupBarBackgroundView*)_dn_bottomBarExtension_nocreate;
- (_DNPopupBarBackgroundView*)_dn_bottomBarExtension;

- (void)_userFacing_viewWillAppear:(BOOL)animated;
- (void)_userFacing_viewIsAppearing:(BOOL)animated;
- (void)_userFacing_viewDidAppear:(BOOL)animated;
- (void)_userFacing_viewWillDisappear:(BOOL)animated;
- (void)_userFacing_viewDidDisappear:(BOOL)animated;

- (BOOL)_dn_isObjectFromSwiftUI;

@end

@interface _DN_UIViewController_AppearanceControl : UIViewController @end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END
