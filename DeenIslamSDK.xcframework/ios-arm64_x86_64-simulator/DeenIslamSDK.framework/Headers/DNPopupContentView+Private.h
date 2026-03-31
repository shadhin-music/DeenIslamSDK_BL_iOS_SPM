//
//  DNPopupContentView+Private.h
//  DNPopupController
//
//  Created by Léo Natan on 2020-08-04.
//  Copyright © 2015-2024 Léo Natan. All rights reserved.
//

#import "DNPopupContentView.h"

@interface DNPopupContentView ()

- (instancetype)initWithFrame:(CGRect)frame;

@property (nonatomic, strong, readwrite) UIPanGestureRecognizer* dnpopupInteractionGestureRecognizer;
@property (nonatomic, strong, readwrite) DNPopupCloseButton* dnpopupCloseButton;
@property (nonatomic, strong) UIVisualEffectView* effectView;
@property (nonatomic, strong, readonly) UIView* contentView;

@property (nonatomic, weak) UIViewController* currentPopupContentViewController;

- (void)setControllerOverrideUserInterfaceStyle:(UIUserInterfaceStyle)overrideUserInterfaceStyle;

- (void)_applyBackgroundEffectWithContentViewController:(UIViewController*)vc barEffect:(UIBlurEffect*)barEffect;

- (void)_repositionPopupCloseButton;
- (void)_repositionPopupCloseButtonAnimated:(BOOL)animated;

@end

@interface _DNPopupTransitionCoordinator : NSObject <UIViewControllerTransitionCoordinator> @end
