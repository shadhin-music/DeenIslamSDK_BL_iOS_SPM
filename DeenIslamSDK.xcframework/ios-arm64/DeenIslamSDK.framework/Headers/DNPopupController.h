//
//  DNPopupController.h
//  DNPopupController
//
//  Created by Léo Natan on 2015-08-23.
//  Copyright © 2015-2024 Léo Natan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DNPopupBar+Private.h"
#import "UIViewController+DNPopupSupportPrivate.h"
#import "DNPopupCloseButton.h"
#import "DNPopupContentView+Private.h"
#import "DNPopupBar+Private.h"

CF_EXTERN_C_BEGIN

#define _DNPopupPresentationStateTransitioning ((DNPopupPresentationState)2)

@interface DNPopupController : NSObject <_DNPopupBarDelegate>

- (instancetype)initWithContainerViewController:(__kindof UIViewController*)containerController;

@property (nonatomic, weak) UIView* bottomBar;

@property (nonatomic, strong) DNPopupBar* popupBar;
@property (nonatomic, strong, readonly) DNPopupBar* popupBarStorage;
@property (nonatomic, strong, readonly) DNPopupBar* popupBarNoCreate;
@property (nonatomic, strong) DNPopupContentView* popupContentView;
@property (nonatomic, strong) UIScrollView* popupContentContainerView;

@property (nonatomic) DNPopupPresentationState popupControllerPublicState;
@property (nonatomic) DNPopupPresentationState popupControllerInternalState;
@property (nonatomic) DNPopupPresentationState popupControllerTargetState;

@property (nonatomic, weak) id<DNPopupPresentationDelegate> userPopupPresentationDelegate;

@property (nonatomic, strong) __kindof UIViewController* currentContentController;
@property (nonatomic, weak) __kindof UIViewController* containerController;

@property (nonatomic) CGPoint lastPopupBarLocation;
@property (nonatomic) CFTimeInterval lastSeenMovement;

@property (nonatomic, weak) UIViewController* effectiveStatusBarUpdateController;

@property (assign) BOOL wantsFeedbackGeneration;

- (CGFloat)_percentFromPopupBar;

- (void)_setContentToState:(DNPopupPresentationState)state;
- (void)_setContentToState:(DNPopupPresentationState)state animated:(BOOL)animated;

- (void)_movePopupBarAndContentToBottomBarSuperview;

- (void)dnpresentPopupBarWithContentViewController:(UIViewController*)contentViewController dnopenPopup:(BOOL)open animated:(BOOL)animated completion:(void(^)(void))completionBlock;
- (void)dnopenPopupAnimated:(BOOL)animated completion:(void(^)(void))completionBlock;
- (void)dnclosePopupAnimated:(BOOL)animated completion:(void(^)(void))completionBlock;
- (void)dndismissPopupBarAnimated:(BOOL)animated completion:(void(^)(void))completionBlock;

- (void)_configurePopupBarFromBottomBar;
- (void)_configurePopupBarFromBottomBarModifyingGroupingIdentifier:(BOOL)modifyingGroupingIdentifier;
- (void)_updateBarExtensionStyleFromPopupBar;

+ (CGFloat)_statusBarHeightForView:(UIView*)view;

- (void)_fixupGestureRecognizer:(UIGestureRecognizer*)obj;

@end

CF_EXTERN_C_END
