//
//  DNPopupItem+Private.h
//  DNPopupController
//
//  Created by Léo Natan on 2016-12-30.
//  Copyright © 2015-2024 Léo Natan. All rights reserved.
//

#import "DNPopupItem.h"
#import "DNPopupCustomBarViewController.h"
#import "DNPopupController.h"

@interface DNPopupCustomBarViewController ()

@property (nonatomic, weak, readwrite) DNPopupBar* dncontainingPopupBar;
@property (nonatomic, weak) DNPopupController* popupController;

- (void)_activeAppearanceDidChange:(DNPopupBarAppearance*)activeAppearance;

- (void)_userFacing_viewWillAppear:(BOOL)animated;
- (void)_userFacing_viewIsAppearing:(BOOL)animated;
- (void)_userFacing_viewDidAppear:(BOOL)animated;
- (void)_userFacing_viewWillDisappear:(BOOL)animated;
- (void)_userFacing_viewDidDisappear:(BOOL)animated;

@end

@interface _DNPopupCustomBarViewController_AppearanceControl : DNPopupCustomBarViewController @end
